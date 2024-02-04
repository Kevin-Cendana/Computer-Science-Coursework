// Kevin Cendana
// CSC 139 Fall 2023

#include "umem.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#define ALIGNMENT 8 // 8-byte alignment for memory blocks
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~(ALIGNMENT-1)) // Aligns given size to nearest multiple of ALIGNMENT
#define DEBUG 0 // Debug flag; 1 when I want to see debug messages, change to 0 when done, probably going to delete all debug messages after though

// Struct for free list's block header
typedef struct global_block {
    size_t size;                
    struct global_block *next; 
} global_block;

// Global variables
static global_block *free_list_head = NULL;
static global_block *next_fit_ptr = NULL;
static char *global_ptr = NULL;
static int is_initialized = 0;
static int alloc_algorithm;

// Debugging functions
void debug_print(const char *message); // Debug print function; prints if #define DEBUG is 1, may remove these debug function calls later
int has_cycle(global_block *head);     // Debugging function to check for cycles in free list
int check_free_list_consistency();       // Debugging function to check for consistency in free list

void debug_print(const char *message) {
    if (DEBUG) {
        printf("DEBUG: %s\n", message);
    }
}

int check_free_list_consistency() {
    global_block *current = free_list_head;
    while (current!=NULL && current->next!=NULL) {
        if ((char*)current + current->size + sizeof(global_block) > (char*)current->next) {
            printf("Inconsistency detected in free list (possible error)?\n");
            return -1;
        }
        current = current->next;
    }
    return 0;
}

int has_cycle(global_block *head) {
    global_block *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1; // Cycle detected
        }
    }
    return 0; // No cycle
}

// Functions
int umeminit(size_t size_of_region, int allocationAlgo);
void *umalloc(size_t size);
void umemdump();
int ufree(void *ptr);
void *umalloc_first_fit(size_t size);
void *umalloc_best_fit(size_t size);
void *umalloc_worst_fit(size_t size);
void *umalloc_next_fit(size_t size);


//--------------------------------------------------------------------------------------//
//                                       umeminit                                       //
//                              initializes memory allocator                            //
//--------------------------------------------------------------------------------------//

int umeminit(size_t size_of_region, int allocationAlgo) {
    alloc_algorithm = allocationAlgo;

    if (is_initialized) {
        fprintf(stderr, "Error: umeminit already called\n");
        return -1;
    }

    if (size_of_region <= 0) {
        fprintf(stderr, "Error: size_of_region must be greater than 0\n");
        return -1;
    }

    size_t page_size = getpagesize();
    size_of_region = (size_of_region+page_size - 1) / page_size * page_size;

    // Using mmap w/ MAP_ANON for mem mapping
    global_ptr = mmap(NULL,size_of_region, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (global_ptr==MAP_FAILED) {
        perror("mmap");
        return -1;
    }

    // Initialize the free list
    free_list_head = (global_block *)global_ptr;
    free_list_head->size = size_of_region - sizeof(global_block);
    free_list_head->next = NULL;

    is_initialized = 1;

    umemdump();
    return 0;
}


//--------------------------------------------------------------------------------------//
//                                       umalloc                                        //
//                          has the same interface as malloc                            //
//--------------------------------------------------------------------------------------//

void *umalloc(size_t size) {
    switch (alloc_algorithm) {
        case BEST_FIT:
            return umalloc_best_fit(size);
        case WORST_FIT:
            return umalloc_worst_fit(size);
        case NEXT_FIT:
            return umalloc_next_fit(size);
        case FIRST_FIT:
            return umalloc_first_fit(size);
        default:
            fprintf(stderr, "Unknown allocation algorithm\n");
            return NULL;
    }
}

//!--------------------------------------------------------------------------------------//
//!                                        ufree                                         //
//!                            has the same interface as free                            //
//!--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//
//                                        ufree                                         //
//                            has the same interface as free                            //
//--------------------------------------------------------------------------------------//

int ufree(void *ptr) {
    if (!ptr) {
        return 0; // If ptr is NULL, no operation is performed
    }

    if (has_cycle(free_list_head)) {
        return -1; // or handle as appropriate
    }

    // Get the block header for the block being freed
    global_block *block_to_free = (global_block *)ptr - 1;

    // Coalescing: Check adjacent blocks in the free list to merge contiguous free blocks
    global_block *current = free_list_head;
    global_block *previous = NULL;

    while (current != NULL) {
        if ((char *)current + current->size + sizeof(global_block) == (char *)block_to_free) {
            // Adjust size to include next block and header
            block_to_free->size += current->size + sizeof(global_block);

            // Update the next pointer of the merged block
            block_to_free->next = current->next;

            // If this block was the first in the free list, update the head
            if (previous == NULL) free_list_head = block_to_free;

            // No need to continue as the block has been merged
            break;
        } else if ((char *)block_to_free + block_to_free->size + sizeof(global_block) == (char *)current) {

            // Adjust size of previous block to include this block and header
            previous->size += block_to_free->size + sizeof(global_block);

            // Update the next pointer of the merged block
            previous->next = current->next;

            // Set block_to_free to the merged block (previous)
            block_to_free = previous;

            // No need to continue as the block has been merged
            break;
        } else {
            // Move both previous and current forward
            previous = current;
            current = current->next;
        }
    }

    // If block_to_free is not in the free list, remmber to add it
    if (block_to_free != previous) {
        if (previous != NULL) previous->next = block_to_free;
        else free_list_head = block_to_free;
        block_to_free->next = current;
    }
    umemdump();
    return 0;
}


//--------------------------------------------------------------------------------------//
//                                       umemdump                                       //
//     prints which regions are currently free and is primarily to aid your debugging   //
//--------------------------------------------------------------------------------------//

void umemdump() {
    printf("Free List Dump:\n");
    global_block *current = free_list_head;
    int block_counter = 0; 
    int loop_cap = 10; // I might remove this later, but 10 is a good cap to check for inf loops

    while (current != NULL && block_counter < loop_cap) {
        printf("Block %d: Address %p, Size: %zu bytes, Next: %p\n", 
               block_counter++, (void*)current, current->size, (void*)current->next);
        current = current->next;
    }
    if (block_counter >= loop_cap) { 
        printf("Warning: Stopped printing due to too many blocks (potential inf loop).\n");
    }
}


//--------------------------------------------------------------------------------------//
//                                       BEST FIT                                       //
//--------------------------------------------------------------------------------------//

void *umalloc_best_fit(size_t size) {
    // Align the requested size
    size = ALIGN(size);

    // Return NULL if size is 0
    if (size == 0) {
        return NULL;
    }

    global_block *best_fit = NULL;
    global_block *best_fit_prev = NULL;
    size_t best_fit_size = SIZE_MAX;

    global_block *current = free_list_head;
    global_block *previous = NULL;

    // Iterate over the free list to find the best fit
    while (current != NULL) {
        if (current->size >=size && current->size < best_fit_size) {
            best_fit = current;
            best_fit_prev = previous;
            best_fit_size = current->size;
        }
        previous = current;
        current = current->next;
    }

    // If a best fit is found, allocate it
    if (best_fit != NULL) {
        printf("Best fit block found: Address %p, Size %zu\n", (void*)best_fit, best_fit->size);
        
        // Split the block if it's large enough to be divided
        if (best_fit->size > size + sizeof(global_block)) {
            global_block *new_block = (global_block *)((char *)best_fit + sizeof(global_block) + size);
            new_block->size = best_fit->size - sizeof(global_block) - size;
            new_block->next = best_fit->next;

            best_fit->size = size;
            best_fit->next = new_block;
        } else {
            printf("No suitable block found for size: %zu\n", size);
            // If the block cannot be split, adjust the free list
            if (best_fit_prev != NULL) {
                best_fit_prev->next = best_fit->next;
            } else {
                free_list_head = best_fit->next;
                best_fit_prev = NULL; // Add this line to handle the case when best_fit_prev is NULL
            }
        }

        // Return the allocated memory (excluding the header)
        return (void *)(best_fit + 1);
    }

    // No suitable block found, return NULL
    umemdump();
    return NULL;
}

//--------------------------------------------------------------------------------------//
//                                      WORST FIT                                       //
//--------------------------------------------------------------------------------------//

void *umalloc_worst_fit(size_t size) {
    // Align the requested size
    size = ALIGN(size);

    // Return NULL if size is 0
    if (size == 0) {
        return NULL;
    }

    global_block *worst_fit = NULL;
    global_block *worst_fit_prev = NULL;
    size_t worst_fit_size = 0; // Start with 0 to find the maximum

    global_block *current = free_list_head;
    global_block *previous = NULL;

    // Iterate over the free list to find the worst fit (largest block)
    while (current != NULL) {
        if (current->size >= size && current->size > worst_fit_size) {
            worst_fit = current;
            worst_fit_prev = previous;
            worst_fit_size = current->size;
        }
        previous = current;
        current = current->next;
    }

    // If a worst fit is found, allocate it
    if (worst_fit != NULL) {
        printf("Worst fit block found: Address %p, Size %zu\n", (void*)worst_fit, worst_fit->size);
        
        // Split the block if it's large enough to be divided
        if (worst_fit->size > size + sizeof(global_block)) {
            global_block *new_block = (global_block *)((char *)worst_fit + sizeof(global_block) + size);
            new_block->size = worst_fit->size - sizeof(global_block) - size;
            new_block->next = worst_fit->next;

            worst_fit->size = size;
            worst_fit->next = new_block;
        } else {
            // If the block cannot be split, adjust the free list
            if (worst_fit_prev != NULL) {
                worst_fit_prev->next = worst_fit->next;
            } else {
                free_list_head = worst_fit->next;
            }
        }

        // Return the allocated memory (excluding the header)
        return (void *)(worst_fit + 1);
    }

    // No suitable block found, return NULL
    umemdump();
    return NULL;
}


//--------------------------------------------------------------------------------------//
//                                      FIRST FIT                                       //
//--------------------------------------------------------------------------------------//

void *umalloc_first_fit(size_t size) {
    // Align the requested size to ensure proper mem alignment
    size = ALIGN(size);

    // Check if requested size is 0
    if (size == 0) 
        return NULL;

    // Search free list for a suitable block
    global_block *current = free_list_head;
    global_block *previous = NULL;

    while (current != NULL) {
        // Check if current block is large enough for request
        if (current->size >= size) {
            // Check if block can be split
            if (current->size > size + sizeof(global_block)) {
                // Create new header for the remaining part of the block
                global_block *new_block = (global_block *)((char *)current + sizeof(global_block) + size);
                new_block->size = current->size - sizeof(global_block) - size;
                new_block->next = current->next;

                // Update the size of the curr block
                current->size = size;

                // Update the next pointer of the prev block (or free list head)
                if (previous == NULL) {
                    free_list_head = new_block;
                } else {
                    previous->next = new_block;
                }
            } else {
                // If the block cant be split, remove from the free list
                if (previous == NULL) {
                    free_list_head = current->next;
                } else {
                    previous->next = current->next;
                }
            }

            // Return the allocated memory (excluding the header)
            return (void *)(current + 1);
        }

        // Move to the next block in the free list
        previous = current;
        current = current->next;
    }

    // No suitable block found, return NULL
    umemdump();    
    return NULL;
}

//--------------------------------------------------------------------------------------//
//                                       NEXT FIT                                       //
//--------------------------------------------------------------------------------------//

void *umalloc_next_fit(size_t size) {
    // Align requested size
    size = ALIGN(size);

    // Return NULL if size = 0
    if (size == 0) {
        return NULL;
    }

    // Initialize next_fit_ptr if it's NULL
    if (next_fit_ptr == NULL) {
        next_fit_ptr = free_list_head;
    }

    global_block *start = next_fit_ptr;
    do {
        // Check if the curr block is large enough to satisfy request
        if (next_fit_ptr->size >= size) {
            // Split the block if it's large enough to be divided
            if (next_fit_ptr->size > size + sizeof(global_block)) {
                global_block *new_block = (global_block *)((char *)next_fit_ptr + sizeof(global_block) + size);
                new_block->size = next_fit_ptr->size - sizeof(global_block) - size;
                new_block->next = next_fit_ptr->next;
                next_fit_ptr->size = size;
                next_fit_ptr->next = new_block;
            } else {
                // If the block cannot be split, adjust the free list
                if (next_fit_ptr == free_list_head) {
                    free_list_head = next_fit_ptr->next;
                }
            }

            // Update next_fit_ptr to the next block in the free list for future calls
            global_block *allocated_block = next_fit_ptr;
            next_fit_ptr = next_fit_ptr->next ? next_fit_ptr->next : free_list_head;

            // Return the allocated memory (excluding the header)
            return (void *)(allocated_block + 1);
        }

        // Move to the next block in the free list, wrapping around if necessary
        next_fit_ptr = next_fit_ptr->next ? next_fit_ptr->next : free_list_head;

        // If we've come back to the start, break the loop to avoid infinite iteration (recurring problem :< )
        if (next_fit_ptr == start) {
            break;
        }        
    } while (next_fit_ptr != start); // Loop until we come back to the start

    // No suitable block found, return NULL
    umemdump();    
    return NULL;
}


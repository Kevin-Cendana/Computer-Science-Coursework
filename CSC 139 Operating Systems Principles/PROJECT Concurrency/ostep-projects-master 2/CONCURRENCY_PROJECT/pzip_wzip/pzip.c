// Kevin Cendana | CSC 139 | Fall 2023
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define BUFFER_SIZE 1024 

// Function declarations
void* compress(void* args); // Function to compress a segment of the file

// Structure to pass data to threads
typedef struct {
    char *filename;
    long start;
    long end;
    int isStartingThread;
    char *outputBuffer; // Buffer to store the output of current thread
    int outputSize;     // Size of the output in buffer
} ThreadArg;

// Mutex for thread synchronization
pthread_mutex_t mutex; 

int main(int argc, char *argv[]) {

    // Check if the user provided a file name
    if (argc < 2) {
        printf("pzip: file1 [file2 ...]\n"); // Print how it's supposed to be used if user messesup
        return 1;                            // Return error code
    }

    // Initialize mutex for some multithreading action wooo
    pthread_mutex_init(&mutex, NULL);

    // Count how many files we need to make
    int numThreads = argc - 1; 
    pthread_t threads[numThreads];     // Array of threads ID
    ThreadArg thread_args[numThreads]; // Array of thread arguments

    // Calculate file size and divide it into segments for each thread
    for (int i = 0; i < numThreads; i++) { 
        FILE *fp = fopen(argv[i + 1], "r"); // Open file

        // Check if file exists first
        if (fp == NULL) {
            printf("pzip: cannot open file\n");
            return 1;
        }

        // Get file size
        fseek(fp, 0, SEEK_END);     // Move the file pointer to the end of the file
        long fileSize = ftell(fp); // Get the current file position, which is the file size
        fclose(fp);                 // Close the file

        // Divide file into equal segments for each thread
        long segment_size = fileSize / numThreads; // Calculate size of each segment
        thread_args[i].filename = argv[i + 1]; // Set filename in thread arguments
        thread_args[i].start = i * segment_size; // Calculate the start position for this thread
        thread_args[i].end = (i == numThreads - 1) ? fileSize : (i + 1) * segment_size; // Calculate the end position for this thread
        thread_args[i].isStartingThread = (i == 0); // Set isStartingThread flag to true for the first thread

        pthread_create(&threads[i], NULL, compress, &thread_args[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL); // Wait for the thread to finish
    }

    // All done, clean up by destroying mutex!
    pthread_mutex_destroy(&mutex);     // Clean up the mutex

    return 0;
}

// Function where each thread does it's part of compression
void* compress(void* args) {
    ThreadArg *details = (ThreadArg*)args;             // Get thread-specific arguments
    FILE *filePointer = fopen(details->filename, "r"); // Open the file for this thread
    if (filePointer == NULL) {
        pthread_exit(NULL); // Exit if the file couldn't be opened
    }

    // Adjust the start position for threads that are not the first
    if (!details->isStartingThread) {

        // Make sure we start compressing at the beginning of a character sequence
        fseek(filePointer, details->start - 1, SEEK_SET);    // Go back one char to find sequence start
        char tempChar = fgetc(filePointer);                  // Get char at this position

        // Keep going back until we find the start of this sequence of characters
        while (tempChar != EOF && tempChar == fgetc(filePointer)) {
            details->start--;                                 // Adjust the start position backward
            fseek(filePointer, details->start - 1, SEEK_SET); // Move the file pointer
        }
    }

    fseek(filePointer, details->start, SEEK_SET); // Set the file pointer to the start position
    long position = details->start; // Current position in the file
    char currentChar, previousChar = '\0'; // Variables for current and previous chars
    int counter = 0; // Counter for repeated characters

    // Create a buffer for output
    char buffer[BUFFER_SIZE];
    int bufferIndex = 0; // Current index in the buffer

    // Time to compress! Process the file segment
    while ((currentChar = fgetc(filePointer)) != EOF && position < details->end) {

        // Check if we have a repeating character
        if (counter == 0) {
            previousChar = currentChar; // Set the first character
            counter = 1;                // Start counting
        } else if (currentChar == previousChar) {
            counter++; // Increment counter for repeating characters
        } else {

            // Check if we have space in the buffer
            if (bufferIndex < BUFFER_SIZE - sizeof(int) - 1) {
                memcpy(&buffer[bufferIndex], &counter, sizeof(int)); // Copy the count
                bufferIndex += sizeof(int);
                buffer[bufferIndex++] = previousChar; // Copy the character
            }

            // If buffer is full, we need to write it out
            if (bufferIndex >= BUFFER_SIZE - sizeof(int) - 1) {
                pthread_mutex_lock(&mutex);
                fwrite(buffer, 1, bufferIndex, stdout); // Write buffer to stdout
                pthread_mutex_unlock(&mutex);           // Unlock the mutex
                bufferIndex = 0;                        // Reset buffer index
            }

            previousChar = currentChar; // Update previous char
            counter = 1;                // Reset counter
        }
        position++; // Move to the next character
    }

    // Write any remaining content in the buffer
    if (bufferIndex > 0) {
        pthread_mutex_lock(&mutex);             // todo Lock the mutex (maybe improve efficiency by locking differently?)
        fwrite(buffer, 1, bufferIndex, stdout); // Write final buffer content
        pthread_mutex_unlock(&mutex);           // Unlock the mutex
    }

    fclose(filePointer); // Close the file
    pthread_exit(NULL);  // Exit the thread
}

/* Current Run Times: 
    0.70 seconds total for 6.in (the final testing file for original wzip),
    21.468 seconds total for 320 mb file 
    72.79 seconds total for 1.07 gb file*/

/* PZIP Notes 
    - Use run-length encoding as the basic compression technique.
    - Basically WZIP but use POSIX threads for parallelization.
    - Determine how many threads to create w/ :
        - get_nprocs() 
        - get_procs_conf()
    - Read via fread(), read(), or even use mmap()
    ./pzip file > file.z */

/* WZIP Notes
notes: run length encoding
ex: aaabbbcc -> 3a3b2c
write out 4 byte integer in binary followed by the character in ASCII
- fwrite() to write integer in binary format to file
- to compress file.txt into file.z:       ./wzip file.txt > file.z
- to decompress file.z into file.txt:     ./wunzip file.z > file.txt
requirements:
- invoke w/ 1+ arguments
- if no files are specified, exit w return code 1 and print "wzip: file1 [file2 ...]\n" 
    or "wunzip: file1 [file2 ...]\n"
- compressed file format must be a 4 byte integer followed by the character in ASCII
- if multiple files are passed to wzip, they are compressed into a single compressed output,
    and when unzipped, will turn into a single uncompressed stream of text */
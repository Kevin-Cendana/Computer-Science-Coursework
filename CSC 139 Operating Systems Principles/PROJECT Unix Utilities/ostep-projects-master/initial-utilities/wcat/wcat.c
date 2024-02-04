// Kevin Cendana | CSC 139 | Fall 2023
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_S 9999

int main(int argc, char *argv[]) { 
    // check if 1+ filenames provided
    if (argc < 2) {                                         // if no filename provided
        //fprintf(stdout, "how to use: type ./wcat [filename]\n");     //  let user know how to use
        return 0;                                           //  exit without error code
    }

    // loop through each file
    for (int i = 1; i < argc; i++) {    
        // open current file
        FILE *filePointer = fopen(argv[i], "r");            // open argv[i], r = read mode
        if (filePointer == NULL) {                          // if file not found
            fprintf(stdout, "wcat: cannot open file\n");    //  print error message
            exit(1);                                        //  exit with error code
        }

        // read and print the current file contents line by line
        char buffer[BUFFER_S];                                  // decent size buffer to store each line
        while (fgets(buffer, BUFFER_S, filePointer) != NULL) {  // read line by line
            printf("%s", buffer);                           // print the line
        }

        fclose(filePointer);                              
    }
    return 0;   
}

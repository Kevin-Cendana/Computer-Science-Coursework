// Kevin Cendana | CSC 139 | Fall 2023
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // check if 1+ filename(s) provided
    if (argc < 2) {                                           // if no filename provided
        printf("wunzip: file1 [file2 ...]\n");
        //fprintf(stderr, "wunzip: file1 [file2 ...]\n");      //  fprint to stderr so it doesn't write to file if redirected
        return(1);                                            //  exit with error code
    }

    // loop through each file
    int counter;                                              // counter of total number of characters
    char character;                                           // current character
    for (int i = 1; i < argc; i++) {        
        FILE *filePointer = fopen(argv[i], "rb");             // open file in read mode
        if (filePointer == NULL) {                            // if file not found
            fprintf(stderr, "wunzip: cannot open file\n");    //  print error message
            return(1);                                        //  exit with error code
        }
        // for current file, read and print the contents line by line (each line is a word)
        while (fread(&counter, sizeof(int), 1, filePointer) == 1 && fread(&character, sizeof(char), 1, filePointer) == 1) {
            if (counter <= 0 || counter > 9999) {             // 9999 seems like a reasonable max value
            fprintf(stderr, "wunzip: corrupted or invalid compressed file\n");    // print error message
            return(1);
            }
            for (int j = 0; j < counter; j++) {              // loop through total number of characters
                putchar(character);                          // print character
            }
            if (feof(filePointer)) {                         // if end of file
                break;                                       //  break out of (potentially infinite) loop
            }
        }
        fclose(filePointer);
    }
    return 0;
}

/* notes:
 - if no files are specified, exit w return code 1 and print "wzip: file1 [file2 ...]\n" 
    or "wunzip: file1 [file2 ...]\n"
*/
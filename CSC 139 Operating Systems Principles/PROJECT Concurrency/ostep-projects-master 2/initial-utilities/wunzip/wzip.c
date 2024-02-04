// Kevin Cendana | CSC 139 | Fall 2023
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // check if 1+ filename(s) provided
    if (argc < 2) {                             // if no filename provided
        printf("wzip: file1 [file2 ...]\n");    //  let user know how to use
        return(1);                              //  exit with error code
    }

    // loop through each file
    FILE *filePointer;                          // pointer to file
    char currentChar, previousChar;             // current and previous characters
    int counter = 0;                            // counter of current character
    for (int i = 1; i < argc; i++) {            // loop through each file
        filePointer = fopen(argv[i], "r");      // open file in read mode
        if (filePointer == NULL) {              // if file not found
            printf("wzip: cannot open file\n"); //  print error message
            return(1);                          //  exit with error code
        }
        // for current file, read and print the contents line by line (each line is a word)
        while ((currentChar = fgetc(filePointer)) != EOF) {  // read character by character
            if (counter == 0) {                              // if first character
                previousChar = currentChar;                  //  set previousChar to currentChar
                counter = 1;                                 //  set counter to 1
            } else if (currentChar == previousChar) {        // else if currentChar is same as previousChar
                counter++;                                   //  increment counter
            } else {                                         // else (currentChar is different from previousChar)
                fwrite(&counter, sizeof(int), 1, stdout);    //  write counter to stdout
                fputc(previousChar, stdout);                 //  write previousChar to stdout
                previousChar = currentChar;                  //  set previousChar to currentChar
                counter = 1;                                 //  set counter to 1
            }
        }
        fclose(filePointer);                                
    }

    // write out the last character (easier to do seperately than in the loop)
    if (counter > 0) {                             // if there is a last character
        fwrite(&counter, sizeof(int), 1, stdout);  //  write counter to stdout
        fputc(previousChar, stdout);               //  write previousChar to stdout
    }

    return 0;
}

/* notes: run length encoding
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
- if multiple files are passed to wzip, theey are compressed into a single compressed output,
    and when unzipped, will turn into a single uncompressed stream of text */

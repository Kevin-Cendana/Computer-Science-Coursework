// Kevin Cendana | CSC 139 | Fall 2023
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void searchFile(const char *fileName, const char *searchTerm);  // function that searches a file for a word

int main(int argc, char *argv[]) {
    // check if a filename is provided
    if (argc < 2) {                                   // if no filename provided
        printf("wgrep: searchterm [file ...]\n");     //  let user know how to use
        exit(1);                                      //  exit with error code
    }

    // check if search term is empty
    const char *searchterm = argv[1];                 // 1st argument is search term
    if (strlen(searchterm) == 0) {                    // if search term is empty
        return 0;                                     // exit the program without searching
    }
    // check if files are provided
    if (argc == 2) {                                  // if no files provided
        //printf("wgrep.c: search term given but file not found. instead, enter text to search:\n");   // let user know to just search stdin
        char *line = NULL;                            //  buffer to store each line
        size_t len = 0;                               //  length of line, set to 0 to let getline() allocate memory
        while (getline(&line, &len, stdin) != -1) {   //  read line by line
            if (strstr(line, searchterm) != NULL) {   //  if searchterm is found in line (str str is case sensitive)
                printf("%s", line);                   //   print the line
            }
        }
        free(line);                                   // free memory used from by getline()
    } else {                                          // if files provided
        for (int i = 2; i < argc; i++) {              //  loop through each file
            searchFile(argv[i], searchterm);          //  search for searchterm in file
        }
    }

    return 0;   
}

// function to search for searchTerm in fileName
void searchFile(const char *fileName, const char *searchTerm) {
    
    // check for valid file
    FILE *filePointer = fopen(fileName, "r");   // open file in read mode
    if (filePointer == NULL) {                  // if file not found
        printf("wgrep: cannot open file\n");    //  print error message
        exit(1);                                //  exit with error code 1
    }

    //search the file for searchTerm
    char *line = NULL;  // buffer to store each line
    size_t length = 0;  // length of line, set to 0 to let getline() allocate memory
    ssize_t read;       // number of characters read, size_t is unsigned, ssize_t is signed
    while ((read = getline(&line, &length, filePointer)) != -1) {   // read line by line
        if (strstr(line, searchTerm) != NULL) {                     // if searchTerm is found in line
            printf("%s", line);                                     //  print the line
        }
    }

    free(line);              // free memory used from by getline()
    fclose(filePointer);     // close the file
}

/* Requirements
- search is case sensitive: use strstr() 
- lines can be arbitrarily long: use getline()

- If wgrep is passed no command-line arguments, it should print "wgrep: searchterm [file ...]"
 (followed by a newline) and exit with status 1.
- If wgrep encounters a file that it cannot open, it should print "wgrep: cannot open file" 
 (followed by a newline) and exit with status 1.
- else wgrep should exit with return code 0.
- If a search term, but no file, is specified, wgrep should work,
  but instead of reading from a file, wgrep should read from standard input. 
  Doing so is easy, because the file stream stdin is already open; you can use 
  fgets() (or similar routines) to read from it.
- else exit with return code 0

- **For simplicity, if passed the empty string as a search string, wgrep can either match NO lines or match ALL lines, both are acceptable.
*/
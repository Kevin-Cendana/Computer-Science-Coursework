# Summary

For this assignment, I had to...
- Open two files that contained the top 5000 male and female names
- Read and upload each name into a vector data structure
- Search for a user inputted name and display the name's number in both the male and female rankings

# Instructions (Copy and Pasted from Canvas and Formatted)

This activity will use file I/O and vectors to give the user an interactive tool for looking up the popularity of baby names. 

**Setup**

In addition to creating a new project, you need to download these two data files:

*names-f.txt*

*names-m.txt*

These files contain 5000 female names and 5000 male names, listed in order by their popularity in the United States in 2016. 

**Program Specification**

Your program must do the following steps first:

- Create two separate vectors, one for female names and one for male names.

- Open each file. Using a do-while loop, read all lines and add each name to the appropriate vector.

- Close the files.

After that, repeatedly:

- Prompt the user to enter a name. If they enter blank (""), stop the program.

- Otherwise, loop through BOTH vectors, one at a a time.

Report the results of searching for the name in the female and male lists. For each list, if the name is on it, report which rank it has. Otherwise, report that it is not on the list. For instance:

- Sophia was #4 on the list of female names.

- Sophia was not in the top 5000 male names.

- Evan was #2216 on the list of female names.

- Evan was #69 on the list of male names.

- Ganon was not in the top 5000 female names.

-  Ganon was not in the top 5000 male names.

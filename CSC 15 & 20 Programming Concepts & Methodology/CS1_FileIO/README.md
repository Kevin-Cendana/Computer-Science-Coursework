# Summary

For this assignment, I had to...
- Read data from a text file representing a table of show titles and ratings
- Enter any new user data in case they want to enter any ratings of shows
- Search for any possible titles and it's rating

# Instructions (Copy and Pasted from Canvas and Formatted)

For this exercise, you will write a program to process a file that specifies a set of movie rating data for a user. Think of this as one tiny part of the database Netflix keeps for all of its users and all the movies they have rated. The format of the file is as follows:

- Line #1 contains a user's name.

- Line #2 contains the title of a movie.

- Line #3 contains a single integer from 1 to 5, representing the rating the user gave to the movie in line 2.

This may be followed by other lines. They will always be in pairs, matching the format of Lines 2 and 3, alternating between titles and ratings.

**Write a program to manage the contents of data files with this format.**

Each time the program runs, begin by asking for a filename. You will use that name to do the opening (or attempted) of the file required for each of the three menu options. (See the note below.)

After that, present the user with a menu of three choices as described below.

1) Read and display the current data in the file.
This should show the name from the file followed by a well-formatted table of titles and ratings.

2) Enter new user data.
This should prompt for the user's name, then give them an opportunity to enter as many titles and ratings as they want, writing everything to the file.

3) Search for a title.
This should prompt for a title, then read the data in the file to see if the title exists.

If it does, report "[user] gave [title] a rating of [number]".

If not, report "no match found."


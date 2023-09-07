# Summary

For this assignment, I had to...
- Construct a database to keep track of individual students in a class and other info about them
- Calculate their average quiz score and their grade recieved
- Linearly search through the database for any students with an ID number entered by the user

# Instructions (Copy and Pasted from Canvas and Formatted)

In this task, you will implement a simple "database" application for tracking information about students in a class.

First, create a *struct* named Student to store the following information about an individual student:

- name: the student's full name

- idnum: the student's ID number

- quizAverage: a double value between 0.0 and 100.0

- grade: a character representing the current letter grade

Then, in your main(), create a vector of Student elements.

*Behavior*

The behavior of the program has two phases. Please read the instructions below carefully!

**Phase A**

Ask the user how many students there are.

In a loop, repeat the specified number of times to input information about all students:

Ask for the name, ID number and a sequence of 5 quiz scores. Assume each score is between 0 and 100.

Calculate and store the letter grade based on the average quiz score, using the scale below.

- A:	average ≥ 90

- B:	80 ≤ average < 90

- C:	70 ≤ average < 80

- D:	60 ≤ average < 70

- F:	average < 60
 

**Phase B**

Once the input of all student data is complete, the user will now be able to look up information about students:

Repeatedly prompt the user to enter an ID number, stopping when they enter -1. Each time they enter an ID number:

If there is no student with that ID number, report "Not found".

If there is a student with that ID number, print out the student's name, that student's quiz average and grade.

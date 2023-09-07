# Summary

For this assignment, I had to:
- Create a trivia game sample
- Display a temperature table for Celsius and Fahrenheit
- Display a distance table
- Create a small voting simulator and display the count for each vote
- Recieve user prices and report the average and sum of all prices
- Recieve user movie ratings and display the average of the ratings and the well rated movies

# Instructions (Copy and Pasted from Canvas and Formatted)

These tasks focus on loops and logical operators (!, &&, ||).

Make sure you start working on this early enough, follow directions carefully, and test your program thoroughly before submitting.

Your program must begin by presenting the user with a MENU of numbered items, exactly like this:

1) Trivia

2) Temperature Table

3) Distance Table

4) Voting Counter

5) Price Calculator

6) Movie Ratings

 

**Task 1 - Trivia**

Think of a trivia question. Using a loop, repeatedly do the following until they enter the right answer:

Ask the question

If the correct answer is given, print a congratulatory message.

If a wrong answer is given, report how many wrong answers they have given so far.

(*** To enable grading, please also have your program print out the correct answer at the beginning of this task.)

**Task 2 - Temperature Table**

Using a for loop, print a table of temperatures in both Celsius and Fahrenheit, ranging from 0 degrees C to 100 degrees C. Use output formatting to print the Fahrenheit numbers with one decimal place, as shown below:

- Celcius  / Fahrenheit

- 0 /         32.0

- 1 /         33.8

- 2 /        35.6

... [many more lines] ...

- 100  /      212.0

*(Note: The formula in "normal math" for converting from Celsius to Fahrenheit is: F = C * 9/5 + 32*

**Task 3 - Distance Table**

*The distance a vehicle has traveled after a given amount time can be calculated with :distance = speed * time*

Write code that asks for:

- How far the user needs to travel (in miles)

- The speed of a vehicle (in miles per hour)

Then, using a loop, print a sequence of lines showing how many hours it has traveled and how far it has traveled after each hour, until it has reached or gone past the requested distance.

*Example run (text after "?"s is user input):*

- How far are you going (in miles)? 100

- How fast are you driving (in mph)? 30

Hours / Distance

1 /     30

2 /     60

3 /     90

4 /     120

**Task 4 - Voting Counter**

Invent a survey question that has exactly three answers. You must use a different question from my example. Then:

- Repeatedly ask the user to enter a "vote" for one of those three answers.

- Keep track of the total number of times each one was entered, until the user types "DONE".

- If they enter an invalid choice, print an error, but continue asking questions.

- At the end, report how many votes each answer received. 

*Example run (text after "?"s is user input):*

Human, Zerg or Protoss? Human

Human, Zerg or Protoss? Zerg

Human, Zerg or Protoss? Zerg

Human, Zerg or Protoss? Protoss

Human, Zerg or Protoss? Zerg

Human, Zerg or Protoss? DONE

Results

-------

Human 2

Zerg 3 

Protoss 1

**Task 5 - Price Calculator**

Using a for loop, ask the user to enter 5 prices.

After each price is inputted, tell the user what that price is with 9% tax added

(Hint: Multiply by 1.09)

At the end, tell the user:

- The total of all prices (including tax)

- The average of the prices

**Task 6 - Movie Ratings**

Using a for loop, ask the user to enter 5 movie titles (or books, or songs... anything that has a title).

As each title is entered, ask the user to rate that item with a number of "stars" between 1 and 5.  

Use a while loop inside your for loop to do input validation for each rating.

- At the end, tell the user:

- The average of the ratings

- How many titles they rated above 3

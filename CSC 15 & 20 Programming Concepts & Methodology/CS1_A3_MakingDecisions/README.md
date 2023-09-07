# Summary

Based on user input, I had to:
- Make a simple arithmetic question and verify if the answer is correct
- Produce an astronaut weight report showing their weight on different planets
- Display their MPH
- Allow the user to enter a club based on their age and if they had the password

# Instructions (Copy and Pasted from Canvas and Formatted)

Your program must begin by presenting the user with a MENU of numbered items, exactly like this:

- A) Arithmetic Tutor
- B) Astronaut Weight Report
- C) Speed Check
- D) CS Club

After presenting the menu, get a char input from the user. 

Do input validation with a loop, repeating the prompt until they enter a valid choice. You also must accept upper or lowercase input.

For each number on the menu, when the user chooses it, add code to implement each task described below.

**Task A - Arithmetic Tutor**

Generate two random whole dollar amounts between $100 and $999

Display them as a "quiz" in this form (note the numbers below are just an example!):

  $242 + $ 145 = ???
   
Get an answer from the user, then use an if / else to tell them if they are correct or not.

**Task B  - Astronaut Weight Report**

This task calculates how much an astronaut will weigh on different planets.

- Ask "What is your name?"

- Do input validation for this -- they must enter a non-blank string.

- Ask the user for their weight in pounds.

- Do input validation for this -- they must enter a number that is greater than 0.

- Multiply that quantity to determine the user's weight on three different planets. The numbers to multiply are:

  - Venus: 0.907
 
  - Mars: 0.377

  - Jupiter: 2.364

Print a report that follows the form below. (With ___s filled in with name and numbers as appropriate.)

*Mission report for _(user's name)__*
- Weight on Earth: ____
- Weight on Venus: ____
- Weight on Mars: ____
- Weight on Jupiter: ___

**Task C - Speed Check**

Ask the user for three pieces of information:

* What is the speed limit?
* How far did you drive your car, in miles?
* How long did it take to drive that distance, in whole minutes?

Calculate and report the user's speed, using this formula:
 
   *speed = miles / (minutes / 60.0)*

Report the user's speed, in this form:

 *Your speed was ___ MPH.*

Compare the user's speed to the speed limit, use if / else if / else to report one of the following:

* You were traveling under the speed limit.
* You were traveling exactly at the speed limit.
* You were traveling over the speed limit.
 

**Task D - CS Club**

Suppose there is a CS-themed club that requires anyone to be an adult (18 or older) and know the secret password, "compiler", to enter.

Ask the user:

*  How old are you?
* What is the password?

Depending on what their answers were, respond with ONE of the following:

- You may enter.

- You are old enough, but you must know the password to enter.

- You are not old enough to enter.

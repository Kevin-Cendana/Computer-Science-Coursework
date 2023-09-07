# Summary

For this assignment, I had to create functions that..
- Roll a dice X amount of times based on user input and print the sum
- Display a table for falling distance based on time
- Save account info to a text file
- Display the area of a screen based on height and width
- Create a function that validates user data so that it is between x and y
- Displays a trivia question and whether or not the user answered correctly

# Instructions (Copy and Pasted from Canvas)

Each task below involves creating and using a specific function. For each one, you need to do write code in three different places:

- Include an appropriate prototype above main()

- Write the full function definition below main()

- Include a short series of commands inside main() that call the function in an appropriate manner. For this step, you need to follow the exact instructions given.

*Important Notes*

I will test your program two ways: First, I will run your main() as you submitted it. Second, I will combining your functions with my main() to check that each individual function matches the required behavior exactly. As you write functions, I strongly recommending rereading the specification to make sure your function does ONLY what the specification says, nothing more or less.
The functions are divided into two categories. Make sure you are clear about the difference between a void function and a value-returning function

**Function name: RollDice**

Specification: This function has 1 parameter representing the number of times to roll. The function simulates rolling a 20-sided die (i.e. picking a random number from 1 to 20) repeatedly, the given number times, printing the number each time. Using a running total, it also prints the sum of all rolls.

What to do in main(): Ask the user how many times to roll the dice, then call the function using that information.

**Function name: FallingDistance**

Specification: This function has 1 parameter, representing a number of seconds.

When the function runs, it must print a table of time and distance for a falling object, up to the given number of seconds.
  
  - The formula for fallind distance is: distance = 4.9 * (time)2

Example output — assuming the argument passed is 3:

- Time / Distance 

- 1 s /  4.9 m

- 2 s /  19.6 m

- 3 s /  44.1 m

What to do in main(): Ask the user for a number of seconds. Then call the function using that information.

**Function name: SaveAccountInfo**

Specification: This function has 3 parameters, representing

- a filename

- an account number (a whole number)

- an amount of money

When the function runs, it must open the given file for output, then store the account number and money amount into the file.

What to do in main(): Ask the user for an account number and account balance, then call the function to store that information in a file named "bank.txt"

**Value-Returning Functions**

**Function name: Diagonal**

Specification: This function has 2 parameters, representing
  
  - The width of a screen
 
  - The height of a screen

When the function runs, it must calculate and return the diagonal length for the screen.
  
  *Note: The calculation for the diagonal is sqrt(width2 + height2)*

What to do in main(): Ask the user for the dimensions of a screen. Then, by calling the Diagonal() function, report the length of its diagonal.

**Function name: InputWithinRange**

Specification: This function handles getting an integer input from the user.

It has 2 parameters, representing

- the lowest valid number

- the highest valid number

When it runs, it must prompt the user with a question in this form:

Enter a number from lowest to highest:

(In the prompt, lowest and highest should be actual numbers, based on the value of the two parameters.)

After the user's first input, the function must do input validation, forcing them to re-enter repeatedly until they give a valid number.

Once a valid number has been entered, the function must return the number entered.

What to to in main():

- Tell the user they can order 1 to 8 slices of pizza, at a cost of $0.75 per slice. 

- Call the InputWithinRange function to handle the input, then report the cost for the number of slices the user chose.

**Function name: AskQuestion**

Specification: This function handles asking the user a multiple-choice question with 3 possible answers. 

It has 4 parameters, representing

- a question

- 1st possible answer

- 2nd possible answer

- 3rd possible answer

When it runs, it must present the user with the question and a numbered menu of answers, matching this format:

Question

1) answer

2) answer

3) answer

After that, it must prompt the user to pick one of the answers by entering a number from 1 to 3. Include input validation. One the user has entered a valid number, return the number they entered.
 
What to do in main(): By calling the AskQuestion function, present the user with a trivia question along with 3 possible answers, only one of which is correct. 

After the function returns, use the result to report "correct!" or "wrong!" to the user.

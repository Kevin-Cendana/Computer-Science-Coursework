# Summary

Based on user input, I had to:
- Report the area of a pizza
- Print a movie theater receipt of child and adult tickets
- Create a simple Mad Libs game
- Produce a bank account report with their interest rate, principal, etc.
- Create a dice roll game

# Instructions (Copy Pasted from Canvas and Formatted)

For this assignment, you must use output manipulators to make numeric and money output "line up" nicely.

**Task 1**

Ask the user for three pieces of information:

- The pizza flavor they want to order
 
- The diameter of pizza they want (in inches)

- How many slices to divide it into.

Then, report back the area of each slice, including the flavor name. The form of the report should be:

*Each slice of that sausage pizza is 7.32 square inches.*

You will need to use the fact that: area of a circle = pi r^2

**Task 2**

Ask the user for a movie name and the number of child tickets ($5 each) and adult tickets ($8) each that were sold in one night. 

Assuming the theater's profit is 23% of the total sales, report back all information given along with the profit.

Your report should look similar to this:

- Movie Name:             Titanic

- Adult Tickets Sold:	    100

- Child Tickets Sold:	     50

- Total Sales Amount:    $1050.00

- Profit:	               $ 241.50

**Task 3**

Create a simple "Mad Libs" game. 

Ask the user for at least 7 words or phrases, storing each answer in a variable. 

Examples: "Give me a song name", "Give me a location", "Give me an adjective", "Give me a color", etc. 

Use the values in these variables to print out a short story (at least 3-5 sentences), with the user's answers in place of some of the text. For instance: 

Yesterday, in (location), I saw a (color) and very (adjective) (animal). It was eating some (food), and had (number) (plural noun) on its (body part). ....

**Task 4**

Help the user produce a bank account report, as follows:


Ask what their initial deposit is.

Ask what the interest rate is.

Calculate their final amount after one year with the formula given in class.

Print a report that matches the form below.
(Note: This assumes the user entered 1000 for the initial deposit and 4.25 for the interest rate.)


- Interest Rate:           4.25%

- Principal:          $ 1000.00

- Final Amount:       $ 1043.34

- Amount Gained:      $   43.34

**Task 5**

Using random number generation, simulate a simple dice rolling game. The player is trying to roll as high a total as possible, but without going over 21. This portion of the program should behave as follows:


First, roll THREE separate six-sided dice. Report each roll along with the sum of the rolls.

Ask the user "Roll again (y/n)?"

If the user enters "y", repeat the process of rolling THREE six-sided dice. Report each roll, and then the overall total of both sets of rolls.

Whether they rolled a second time or not, print a final output based on the final total:
* If it is over 21, print "You lose, sorry."
* If it 16 through 21, print "You get a gold trophy!"
* If it 10 through 15, print "You get a silver trophy!"
* Otherwise, print "You get a bronze trophy!"

HINT: Use if / else if / else for this!

Example run: (User input is in bold)

- Rolling three dice....
- You rolled: 3, 1, 2
- Current total: 6

- Roll again (y/n)? y

- Rolling again...
- You rolled: 6, 2, 4
- Final total: 18

You win a gold trophy!

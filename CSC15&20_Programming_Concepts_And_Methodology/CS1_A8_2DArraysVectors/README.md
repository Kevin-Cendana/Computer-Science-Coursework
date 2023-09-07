# Summary

For this assignment, I had to create functions that...
- Used a 2D array to track information about user ratings for restaurants and display it
- Used a 2D array to simulate a game of tic tac toe
- Determined whether or not a word contained another word anywhere inside of it

# Instructions (Copy and Pasted from Canvas and Formatted)

Each task below, specifies on separate function to write. The prototypes are provided for you. Make sure you read the specifications carefully. Some of the functions call previous functions on the list, and they are in a deliberate order.

Two additional things to consider:

While working on a specific task, you should also temporarily add code to your main to test the function (by calling it) before moving on.

In some cases, it will probably help to create additional functions to help break these tasks down into smaller pieces.

**Task 1**

void RestaurantData();

(a) In this function, set up three arrays to track information about the user's ratings of various restaurants.

- A 2-D array of ints with:

   - 4 rows, representing 4 different restaurants

   - 3 columns, representing three rating categories (examples: food, service, decor)

- A 1-D array with 4 elements, initialized to contain 4 specific restaurant names

- A 1-D array with 3 elements, initialized to contain 3 category names

(b) Using a standard 2-D array loop, prompt the user to enter ratings following this pattern:

- Rate the food at In-N-Out: 

- Rate the service at In-N-Out:

- Rate the decor at In-N-Out:

- Rate the food at BJ's:

- Rate the service at BJ's:

- Rate the decor at BJ's:

(etc.)

*Note: Assume the user will enter values between 1 and 10, but you do not have to include input validation.*

(c) Display a well-formatted table of the information entered, including row and column labels.

**Task 2**

void TicTacToe();

- In the body of the function, create a 2-dimensional array of strings representing the squares on a tic-tac-toe board. It is 3 rows by 3 columns, and each one is either "-", "X", or "O". The initial values should all be "-", representing available spaces.

- Then, use one while loop to do the following sequence repeatedly:

- Display the whole board as a grid of symbols

*(Note: This requires nested for loops that are inside of the overall while loop.)*

- Ask the user for a row number and column number

- If those numbers are invalid, tell the user why: either "Not on the board." or "Position already played."

- If the move is valid, change the corresponding cell in the array to an "X" or "O". Each time a valid move is played, alternate between X and O.

*(Hint: This will require an additional variable that tracks which symbol is the current symbol.)*

- If 9 valid moves have been played, stop the overall game loop, then display the board one additional time, and print "Game over."

**Task 3**

bool Contains(string text, string target);

This function must return true or false depending on whether the string target occurs anywhere inside the string text.

(Hint: Remember the .find() function returns an integer. What range would that integer be when the target string is successfully found?)

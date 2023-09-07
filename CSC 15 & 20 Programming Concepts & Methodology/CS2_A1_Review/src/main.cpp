#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

int RollDice(int numSides, int numDice);	//returns int, takes two ints

int main() {

//	(1) Write a program that reads in a temperature in Celcius
//		and displays the corresponding temperature in Fahrenheit.
//		The mathematical formula for converting is:
//		F = C*(9/5) + 32

	cout << "Question 1: " << endl;
	double celsius = 0;

	cout << "Please enter a temperature in Celsius: ";
	cin >> celsius;
	cout << celsius << " Celsius = " << ((celsius * 9) / 5) + 32 << " Fahrenheit" << endl;
	cout << endl;

//	(2) Write a program that:
//	Asks the user to input a length in meters.
//	Reports the corresponding distance in feet and inches.
//	(It is okay to round down to the nearest inch)

	cout << "Question 2: " << endl;
	double meters = 0;
	double inches = 0;
	int feet = 0;
	int remInches = 0;

	cout << "Enter a length in meters: ";
	cin >> meters;
	inches = meters * 39.37;
	feet = inches / 12;
	remInches = inches - feet*12;
	cout << "In non-metric units: " << feet << " feet and " << remInches << " inches" << endl;
	cout << endl;

//	(3) Write a program that reads in a list of integers from
//		the user until the user enters the value 0.
//		When the 0 is entered, display the sum and
//		average of all the numbers entered.

	cout << "Question 3:" << endl;
	int userNumber = 0;
	int counter = 0;
	double sum = 0;

	while (true)
	{
		cout << "Please enter a number (0 to stop): " << endl;
		cin >> userNumber;
		if (userNumber == 0)
		{
			break;
		}
		sum+=userNumber;
		counter++;
	}

	cout << "The sum of all of those numbers is " << sum << "." << endl;
	cout << "The average of all of those numbers is " << sum / counter << "." << endl;
	cout << endl;

//	(4a) Write the prototype and definition of a function named RollDice
//	that calculates the result of rolling a set of dice has the following specification:
//
//	It has two parameters, both ints.
//	The first specifies the number of sides per dice, and
//	the second one specifies the number of dice.
//	It calculates and returns the sum of all rolls.
//
//	(4b) In your main() function, ask the user for a number of sides
//	and a number of dice, then use this information to call the RollDice()
//	function. Then report its return value to the user.

	cout << "Question 4: " << endl;
	srand (time(NULL));
	int sides = 0;
	int dice = 0;

	cout << "Please enter a number of sides for the dice. " << endl;
	cin >> sides;
	cout << "Please enter how many dice you would like to use. " << endl;
	cin >> dice;
	cout << "You rolled a total of " << RollDice(sides,dice) << "." << endl;
	cin.ignore();
	cout << endl;

//	(5) Write a program that reads in a list of words from the
//		user until the user enters the word “END”.
//		Then, display a list of word lengths, from 1 to 10,
//		and how many words of each length were entered.

	cout << "Question 5: " << endl;
	vector <string> wordBank;
	string userWord;
	unsigned int letterCount[10] = {0};

	while(true)
	{
		cout << "Please enter a word (Enter END to stop): " << endl;
		getline(cin, userWord);
		if (userWord == "END")
		{
			break;
		}
		wordBank.push_back(userWord);
	}

	for (unsigned int i = 1; i <= 10; i++)
	{
		for (unsigned int j = 0; j < wordBank.size(); j++)
		{
			if (wordBank[j].size() == i)
			{
				letterCount[i - 1]++;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << "Number of words with length " << i + 1 << ": ";
		cout << letterCount[i] << endl;
	}


	cout << "Goodbye :)" << endl;
}

//Definition for Question 4a
int RollDice(int numSides, int numDice)
{
	int diceSum = 0;
	for (int i = 0; i < numDice; i++)
	{
		int rng = rand()%numSides + 1;
		diceSum += rng;
	}
	return diceSum;

}

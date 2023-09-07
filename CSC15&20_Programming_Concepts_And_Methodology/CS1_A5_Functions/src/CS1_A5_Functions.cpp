//============================================================================
// Name        : CS1_A5_Functions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

void RollDice(int numRolls);
void FallingDistance(int numSeconds);
void SaveAccountInfo(string fileName, int accountNum, double money);
double Diagonal(double width, double height);
int InputWithinRange(int lowest, int highest);
int AskQuestion(string question, string a1, string a2, string a3);

int main()
{
	//Function 1: RollDice
	srand(time(NULL));
	int numRolls = 0;
	int numSeconds = 0;
	cout << "How many times would you like to roll the dice? ";
	cin >> numRolls;
	RollDice(numRolls);

	//Function 2: FallingDistance
	int height = 0;
	int width = 0;
	cout << "How many seconds? ";
	cin >> numSeconds;
	FallingDistance(numSeconds);

	//Function 3: SaveAccountInfo
	SaveAccountInfo("Data.txt", 126124, 5.00);

	//Function 4: Diagonal
	cout << "Entering dimensions of the screen... " << endl;
	cout << "Width: ";
	cin >> width;
	cout << "Height ";
	cin >> height;
	cout << Diagonal(width, height) << endl;

	//Function 5: InputWithinRange
	cout << "You can order 1 - 8 slices of pizza. " << endl;
	cout << "How many would you like? ";
	double totalCost = (InputWithinRange(1,8)*0.75);
	cout << "Your total is " << totalCost << endl;

	//Function 6: AskQuestion
	int userAnswer = AskQuestion("What color is a banana?", "red", "yellow", "blue");
	if (userAnswer == 2)
	{
		cout << "Correct! " << endl;
	}
	else
		cout << "Wrong! " << endl;
}

void RollDice(int numRolls)
{
	int rng = 0;
	int total = 0;
	for (int i = 0; i < numRolls; i++)
	{
		rng = rand() % 20 + 1;
		cout << rng << " ";
		total += rng;
	}
	cout << endl;
	cout << "Total: " << total << endl;
}

void FallingDistance(int numSeconds)
{
	cout << "Time Distance" << endl;
	for (int i = 0; i < numSeconds; i++)
	{
		double secondsSquared = (i + 1)*(i + 1);
		double distance = 4.9*(secondsSquared);
		cout << i + 1 << " s  " << distance << " m" << endl;
	}
}

void SaveAccountInfo(string fileName, int accountNum, double money)
{
	ofstream file;
	file.open(fileName.c_str());
	if (file.fail())
	{
		cout << "** Could not open data file!" << endl;
	}
	else
	{
		cout << "Successfully created Data.txt." << endl;
		file << accountNum << " " << money;
		file.close();
	}
}

double Diagonal(double width, double height)
{
	return (width*width) + (height*height);
}

int InputWithinRange(int lowest, int highest)
{
	int userInput = 0;
	while (true)
	{
		cin >> userInput;
		if (userInput < lowest || userInput > highest)
		{
			cout << "Please enter a number between " << lowest << " and " << highest << ". ";
		}
		else
			return userInput;
	}
}

int AskQuestion(string question, string a1, string a2, string a3)
{
	int userChoice = 0;
	cout << question << endl;
	cout << "1) " << a1 << endl;
	cout << "2) " << a2 << endl;
	cout << "3) " << a3 << endl;

	while (userChoice < 1 || userChoice > 3)
	{
		cin >> userChoice;
		if (userChoice < 1 || userChoice > 3)
		{
			cout << "Invalid input.";
		}
	}
	return userChoice;

}

#include <iostream>
using namespace std;

void RestaurantData();
void TicTacToe();
bool Contains(string text, string target);
void CountWords(string text);

int main() {

	RestaurantData();

	TicTacToe();

	cout << Contains("Example sentence", "sen");
	cout << "If 1 was printed, 'sen' was found in 'Example sentence'." << endl;

	return 0;
}

void RestaurantData()
{
	int ratings[4][3];
	string restaurants[4] = {"In n Out", "McDonalds", "IHOP", "Taco Bell"};
	string categories[3] = { "food", "service", "atmosphere" };

	//Gather data
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Rate the " << categories[j] << " at " << restaurants[i] << ": ";
			cin >> ratings[i][j];
		}
	}

	//Display data
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << restaurants[i] << "'s " << categories[j] << " rating: " << ratings[i][j] << endl;
		}
	}
}

void TicTacToe()
{
	char grid[3][3] = {'-','-','-','-','-','-','-','-','-'};
	int moveCount = 0;
	char currentLetter = 'O';
	int borderCounter = 0;

	while (true)
	{
		int row = 0;
		int column = 0;

		//Row Border
		cout << "   ";
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << "  ";
		}
		cout << endl;

		//Display game board
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if(j == 0) //Column border
				{
					cout << borderCounter + 1 << " ";
					borderCounter++;
					if (borderCounter == 3)
					{
						borderCounter = 0;
					}
				}
				cout << "[" << grid[i][j] << "]";
				if (j == 2)
				{
					cout << endl;
				}
			}
		}
		if (moveCount == 9)
			break;

		//Turn prompt
		cout << endl;
		cout << "Turn " << moveCount + 1 << "! " << currentLetter << "'s turn. " << endl;
		while (row > 3 || row < 1 || column > 3 || column < 1)
		{
			cout << "Enter a row and column (1-3). " << endl;
			cout << "Row: ";
			cin >> row;
			cout << "Column: ";
			cin >> column;
			if (row > 3 || row < 1 || column > 3 || column < 1)
			{
				cout << "**Invalid input. " << endl;
			}
		}
		if (grid[row - 1][column - 1] == 'O' || grid[row - 1][column - 1] == 'X')
		{
			cout << "Spot is already taken." << endl;
		}
		else
		{
			grid[row - 1][column - 1] = currentLetter;
			moveCount++;

			if (currentLetter == 'O')
				currentLetter = 'X';
			else
				currentLetter = 'O';
		}
		cout << endl;
	}
	cout << "Game over! " << endl;
}

bool Contains(string text, string target)
{
	if (text.find(target) == -1)
	{
		return false;
	}
	else
		return true;
}

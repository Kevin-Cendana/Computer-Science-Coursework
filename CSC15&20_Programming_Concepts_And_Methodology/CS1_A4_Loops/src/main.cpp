#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

int main() {

	int selection = 0;
	while (selection < 1 or selection > 6)
	{
		cout << "1) Trivia" << endl;
		cout << "2) Temperature Table" << endl;
		cout << "3) Distance Table" << endl;
		cout << "4) Voting Counter" << endl;
		cout << "5) Price Calculator" << endl;
		cout << "6) Movie Ratings" << endl;
		cin >> selection;
	}
	while (selection < 1 or selection > 6);

	//TASK 1 - Trivia
	if (selection == 1)
	{
		int skycounter = 1;
		string skycolor = "";
		cout << "What color is the sky? " << endl;
		cout << "(hint: the sky is blue) " << endl;
		cin >> skycolor;

		while (skycolor != "blue")
		{
			cout << "Incorrect. You have " << skycounter << " wrong answer(s). " << endl;
			cin >> skycolor;
			skycounter++;
		}
		if (skycolor == "blue")
		{
			cout << "Congratulations! You are correct. " << endl;
		}
	}

	//TASK 2 - Temperature Table
	if (selection == 2)
	{
		double celsius = 0.0;
		double fahrenheit = 0.0;

		cout << "Celsius 	Fahrenheit" << endl;

		for (int i = 0; i < 100; i++)
		{
			fahrenheit = ((celsius * 9) / 5) + 32;
			cout << celsius << "		" << fahrenheit << endl;
			celsius++;
		}
	}

	//TASK 3 - Distance Table
	if (selection == 3)
	{
		double totaldistance = 0.0;
		double distance = 0.0;
		double speed = 0.0;
		int time = 1; //AKA Hours

		cout << "How far are you going (in miles)? " << endl;
		cin >> totaldistance;
		cout << "How fast are you driving (in mph)? " << endl;
		cin >> speed;
		cout << "Hours	Distance " << endl;

		while (distance < totaldistance)
		{
			distance = time * speed;
			cout << time << "	" << distance << endl;
			time++;
		}
	}

	//TASK 4 - Voting Counter
	if (selection == 4)
	{
		string vote = "";
		int vanilla = 0;
		int chocolate = 0;
		int strawberry = 0;

		while (true)
		{
			cout << "Vanilla, Chocolate, or Strawberry? ('DONE' when finished)" << endl;
			cin >> vote;
			if (vote == "vanilla" or vote == "Vanilla")
			{
				vanilla++;
			}
			else if (vote == "chocolate" or vote == "Chocolate")
			{
				chocolate++;
			}
			else if (vote == "strawberry" or vote == "Strawberry")
			{
				strawberry++;
			}
			else if (vote == "DONE")
			{
				break;
			}
			else
				cout << "Sorry, what was that? " << endl;
		}
		cout << "------" << endl;
		cout << "Vanilla: " << vanilla << endl;
		cout << "Chocolate: " << chocolate << endl;
		cout << "Strawberry: " << strawberry << endl;
	}
	//TASK 5 - Price Calculator
	if (selection == 5)
	{
		double total = 0.0;
		double price = 0.0;
		double aftertax = 0.0;

		for (int i = 0; i < 5; i++)
		{
			cout << "Name price #" << i + 1 << ": ";
			cin >> price;
			aftertax = price * 1.09;
			total += aftertax;
			cout << "After tax, your price is $" << aftertax << "." << endl;
		}
		cout << "The total of all the prices is $" << total << endl;
		cout << "The average of all the prices is $" << total / 5 << endl;
	}

	//TASK 6 - Movie Ratings
	if (selection == 6)
	{
		string movie = "";
		double total = 0.0;
		double decent = 0.0;
		int rating = 0;

		for (int i = 0; i < 5; i++)
		{
				cout << "Name movie #" << i + 1 << ": ";
				cin.ignore();
				getline(cin, movie);
				cout << "What would you rate it out of 5?";
				cin >> rating;
				total += rating;
				if (rating >= 3)
				{
					decent++;
				}
				while (rating < 1 or rating > 5)
				{
					cout << "Invalid input. Please rate again." << endl;
					cin >> rating;
				}
		}
		cout << "Out of all of your ratings, the average is " << total / 5 << "." << endl;
		cout << "You rated " << decent << " titles above 3 stars. " << endl;
	}
}

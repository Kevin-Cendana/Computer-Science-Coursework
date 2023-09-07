#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	string selection = "";

	do
	{
		cout << "A) Arithmetic Tutor" << endl;
		cout << "B) Astronaut Weight Report" << endl;
		cout << "C) Speed Check" << endl;
		cout << "D) CS Club" << endl;
		getline(cin, selection);
	}
	while ( !(selection == "a" || selection == "b" || selection == "c" || selection == "d" || selection == "A" || selection == "B" || selection == "C" || selection == "D" ) );

	if (selection == "a" or selection == "A") //Task A
	{
		double number1 = 0.0;
		double number2 = 0.0;
		double number3 = 0.0;
		double solution = 0.0;

		srand(time(0));

		number1 = rand() % 899 + 100;
		number2 = rand() % 899 + 100;
		number3 = number1 + number2;

		cout << "  $" << number1 << endl;
		cout << "+ $" << number2 << endl;
		cout << "------" << endl;
		cout << "   ???" << endl;
		cin >> solution;

		if (solution == number3)
		{
			cout << "Correct!" << endl;
		}
		else
		{
			cout << "Incorrect." << endl;
	}
	}
	else if (selection == "b" or selection == "B") //Task B
	{
		string name = "";
		double pounds = 0.0;
		cout << "What is your name?" << endl;
		cin >> name;
		cin.ignore(1000, '\n');

		cout << "Hello, " << name << "." << endl;
		cout << "What is your weight in pounds?" << endl;
		cin >> pounds;
		cin.ignore(1000, '\n');

		//input validation
		while (pounds < 1)
		{
			cout << "Invalid input." << endl;
			cout << "Please pick a number greater than zero.";
			cin >> pounds;
			cin.ignore(1000, '\n');
		}
		double venusweight = pounds * 0.907;
		double marsweight = pounds * 0.377;
		double jupiterweight = pounds * 2.364;

		cout << "Mission report for " << name << endl;
		cout << "Weight on Earth: " << pounds << endl;
		cout << "Weight on Venus: " << venusweight<< endl;
		cout << "Weight on Mars: " << marsweight<< endl;
		cout << "Weight on Jupiter: " << jupiterweight<< endl;
	}
	else if (selection == "c" or selection == "C") //Task C
	{
		double speedlimit = 0.0;
		double miles = 0.0;
		double minutes = 0.0;
		cout << "What is the speed limit? " << endl;
		cin >> speedlimit;
		cout << "How far did you drive your car (in miles)? " << endl;
		cin >> miles;
		cout << "How long did it take to drive that distance (in minutes)?";
		cin >> minutes;

		double speed = miles / (minutes / 60);
		cout << "Your speed was " << speed << " MPH." << endl;

		if (speed < speedlimit)
		{
			cout << "You were traveling under the speed limit. " << endl;
		}
		else if (speed > speedlimit)
		{
			cout << "You were traveling over the speed limit." << endl;
		}
		else if (speed == speedlimit)
		{
			cout << "You were traveling exactly at the speed limit. " << endl;
		}
	}
	else if (selection == "d" or selection == "D") //TASK D
	{
		double age = 0.0;
		string password = "";
		cout << "How old are you? " << endl;
		cin >> age;
		cout << "What is the password? " << endl;
		cin >> password;

		if (age >= 18)
		{
			if (password == "compiler" or password == "Compiler")
			{
			cout << "You may enter. " << endl;
			}
			else
			{
			cout << "You are old enough, but you must know the password to enter." << endl;
			}
		}
		else
		{
			cout << "You are not old enough to enter. " << endl;
		}
	}
	return 0;
}


#include "Task.h"

//constructors
Task::Task(string t, string l, int p)
{
	title = t;
	location = l;
	priority = p;

	if (p > 5)
	{
		cout << "*Warning: " << p << " is too big (greater than 5). Rounding to nearest whole number. " << endl;

		while (p > 5)
		{
			p = p - 1;
		}

		cout << "Now, priority has been set to " << p << ". " << endl;
		priority = p;

	}

	if (p < 1)
	{
		cout << "Warning: " << p << " is too small (smaller than 1). Rounding to nearest whole number. " << endl;

		while (p < 1)
		{
			p = p + 1;
		}

		cout << "Now, priority has been set to " << p << ". " << endl;
		priority = p;
	}

}

//methods
void Task::ChangePriority(int newPriority)
{
	if (newPriority > 5)
	{
		cout << "*Warning: " << newPriority << " is too big (greater than 5). Rounding to nearest whole number. " << endl;

		while (newPriority > 5)
		{
			newPriority = newPriority - 1;
		}

		cout << "Now, priority has been set to " << newPriority << ". " << endl;
		priority = newPriority;
	}

	if (newPriority < 1)
	{
		cout << "Warning: " << newPriority << " is too small (smaller than 1). Rounding to nearest whole number. " << endl;

		while (newPriority < 1)
		{
			newPriority = newPriority + 1;
		}

		cout << "Now, priority has been set to " << newPriority << ". " << endl;
	}

	cout << "Changing priority to " << newPriority << ". " << endl;
	priority = newPriority;
}

string Task::Description() const
{
	string newLocation = "";
	newLocation+= "[";
	newLocation+= location;
	newLocation+= "] ";
	newLocation+= title;
	newLocation += " ";

	for (int i = 0; i < priority; i++)
	{
		newLocation+="*";
	}

	return newLocation;
}

//"getter" methods for user
string Task::GetTitle() const
{
	return title;
}
string Task::GetLocation() const
{
	return location;
}
int Task::GetPriority() const
{
	return priority;
}

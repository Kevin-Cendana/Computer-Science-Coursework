#include "TaskList.h"
#include "Task.h"
#include <iostream>
using namespace std;

//constructors
TaskList::TaskList(string lName)
{

	listName = lName;	//string
	numTasks = 0;	//int
	for (int i = 0; i < 100; i++)
	{
		allTasks[i] = { NULL };
	}
}

//methods
void TaskList::AddTask(string taskTitle, string taskLocation, int taskPriority)
{
	for (int i = 0; i < 100; i++)	//Loop entire array (100)
	{
		//Validation - If allTask[i]'s title equals taskTitle...
		if (allTasks[i] != NULL)
		{
			if (allTasks[i]->GetTitle() == taskTitle)	//if task is already on the list
			{
				cout << "Whoops! That task is already on this list. '"
				<< taskTitle << "' is not being added. " << endl;
				break;
			}
		}

		if (allTasks[i] == 0)	//if allTasks[i] is empty
		{

			//Otherwise, add dynamic array to allTasks[i]
			allTasks[i] = new Task(taskTitle, taskLocation, taskPriority);

			cout << allTasks[i]->Description() << " has been added to task list, "
					<< "being # " << numTasks << " in the array. ";

			numTasks++;

			cout << "(# of tasks: " << numTasks << ") "<< endl;

			break;
 		}
	}
}

void TaskList::CompleteTask(string taskTitle)
{
	cout << "Task '" << taskTitle << "' has been completed, searching...";
	int found = 0;

	for (int i = 0; i < 100; i++)
	{
		if (allTasks[i] != NULL)
		{
			//Not really needed. Just shows the process of searching each array.
//			cout << "Searching array number " << i << ": ";	//
//			cout << allTasks[i]->GetTitle() << endl;	//

			string usedTask = allTasks[i]->GetTitle();

			if (usedTask == taskTitle)
			{
				found = 1;
				cout << "Found! Deleting '" << taskTitle << "'. " << endl;
				delete allTasks[i];
				numTasks--;
			}

		}

		//Moving everything down
		if (found == 1)
		{
			allTasks[i] = allTasks[i+1];
		}

	}

	if (found == 0)
	{
		cout << "Error. Task '" << taskTitle << "' not found. " << endl;
	}
}



void TaskList::CompleteTask(int index)
{
	if (index >= 0 and index <= numTasks-1)
	{
		cout << "Task #'" << index << "'has been completed, searching.... ";
		int found = 0;

		for (int i = 0; i < 100; i++)
		{
			if (allTasks[i] != NULL)
			{
				if (i == index)
				{
					string usedTask = allTasks[index]->GetTitle();
					found = 1;
					cout << "Found! Deleting Task in Array #'" << index << "': " << usedTask << endl;
					delete allTasks[index];
					numTasks--;
				}

			}

			//Moving everything down
			if (found == 1)
			{
				allTasks[i] = allTasks[i+1];
			}

		}
	}
	else
	{
		cout << "*Error. # given is out of range. " << endl;
	}
}

void TaskList::ShowAll() const
{
	cout << "My Tasks: (" << numTasks << ")" << endl;
	for (int i = 0; i < 100; i++)
	{
		if (allTasks[i] != NULL)
		{
			string usedTask = allTasks[i]->Description();
			cout << i << ") ";
			cout << usedTask << endl;
		}
		else
		{
			break;
		}

	}
}

void TaskList::ShowByPriority(int minPriority, int maxPriority) const
{
	cout << "My Tasks w/ Priority between " << minPriority << " and " << maxPriority << ": " << endl;
	for (int i = 0; i < 100; i++)
	{
		if (allTasks[i] != NULL)
		{
			int taskPriority = allTasks[i]->GetPriority();

			if (minPriority <= taskPriority and maxPriority >= taskPriority)
			{
				string usedTask = allTasks[i]->Description();
				cout << i << ") ";
				cout << usedTask << endl;
			}

		}
		else
		{
			break;
		}

	}
}

void TaskList::ShowByLocation(string location) const
{
	cout << "My Tasks located at  '" << location << "':" << endl;
	for (int i = 0; i < 100; i++)
	{
		string usedLocation = allTasks[i]->GetLocation();

		if (usedLocation == location)
		{
			if (allTasks[i] != NULL)
			{
				string usedTask = allTasks[i]->Description();
				cout << i << ") ";
				cout << usedTask << endl;
			}
		}
		else
		{
			break;
		}

	}
}

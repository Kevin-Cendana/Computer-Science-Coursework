#include "Task.h"
#include "TaskList.h"
#include <iostream>
using namespace std;


TaskList::TaskList()
{
	// Constructor
	// - This doesn't actually need to do anything.
	//vector <Task *> allTasks;
}


void TaskList::AddTask(string taskTitle, string taskLocation)
{
	// AddTask: Add a task to the TaskList.
	// - Dynamically allocate a new Task object, using the information given,
	//     and append a pointer to it to the allTasks vector.
	// - It *IS* okay for the task to have a title that matches another task on the list.

	Task *nT = new Task(taskTitle, taskLocation);
	allTasks.push_back(nT);
	//cout << allTasks[0];


}

void TaskList::CompleteTask(int taskIndex)
{
// CompleteTask: Record a given task as complete by deallocating the corresponding
// Task object and removing the given element of the allTasks vector.
// - PRINT AN ERROR (and do nothing else) if the index is out of range.
// - Before removing a task, if it has a prereq, STOP AND PRINT AN ERROR,
//    telling the user the title of the task that must be completed first.
// - Before removing the task, also check ALL tasks on the list to see if
//    the task is the prereq of any other tasks. If any of them do, call
//    RemovePrereq() on those tasks.

	cout << "Running CompleteTask... ";
	if (taskIndex < 0 or taskIndex > allTasks.size() - 1)	// -1 because if they send the max vector size doesn't start at 0 but taskIndex should
	{
		cout << "*Error. '" << taskIndex << "' is out of range. " << endl;
		return;
	}

	if (allTasks[taskIndex]->getPrereqTask() != NULL)	//had to make a new function because prereqTask is private
	{
		cout << "*Error. PrereqTask '" << allTasks[taskIndex]->getPrereqTask() << "' has not been completed for this class. " << endl;
		return;
	}

	for (int i = 0; i < allTasks.size(); i++)
	{
		if (allTasks[taskIndex]->getPrereqTask() == allTasks[i]->getPrereqTask())
		{
			cout << "This task is a prereq of " << allTasks[i]->getTitle() << ". Removing " << allTasks[i]->getTitle() << "... " << endl;
			allTasks[taskIndex]->RemovePrereq();
			allTasks.erase(allTasks.begin() + i);	//oh boy i sure hope this works
			return;
		}
	}

	//myvector.erase(myvector.begin() + i);
}
void TaskList::AddTags(int taskIndex, string tagsToAdd[], int size)
{
// AddTags: Add a set of tags to a task on the list.
// - You may assume the tagsToAdd array is already filled with string elements,
//    and the number of elements is given by the size parameter.
// - This method needs to:
//   1) PRINT AN ERROR (and do nothing else) if the index is out of range.
//   2) PRINT AN ERROR (and do nothing ele) if the task already has tags specified.
//   3) Otherwise, add the given set of tags to the specified task.

	if (taskIndex > allTasks.size() - 1 or taskIndex < 0)
	{
		cout << "*Error. Index is out of range. " << endl;
		return;
	}

	for (int i = 0; i < allTasks[i]->getNumTags(); i++)
	{
//		for (int j = 0; j < size; j++)			//totally forgot that HasTags function exists...
//		{
//			if (allTasks[taskIndex]->getTag(i) == tagsToAdd[j])
//			{
//				cout << "*Error. Task already has one of these tags. " << endl;
//				return;
//			}
//		}
		{
			for (int j = 0; j < size; j++)
			{
				if (allTasks[i]->HasTag(tagsToAdd[j]))
				{
					cout << "*Error. Task already has one of these tags. " << endl;
					return;
				}
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << "Adding tags to allTasks[" << taskIndex << "].. " << endl;
		allTasks[taskIndex]->AddTags(tagsToAdd, size);
	}

}

void TaskList::AddPrereq(int taskIndex, int prereqIndex)
{
// AddPrereq: Add a prereq to a task already on the list.
// - taskIndex is the index of the task to add a prereq to.
// - prereqIndex is the index of the prereq task.
// - PRINT AN ERROR (and do nothing else) if any of these are true:
//    * either index is out of range
//    * the two index numbers are equal (you can't make a task a prereq of itself)
//    * the specified task already has a prereq

	if (taskIndex < 0 or taskIndex > allTasks.size() - 1)
	{
		cout << "*Error. taskIndex is out of range. " << endl;
		return;
	}

	if (prereqIndex < 0 or prereqIndex > allTasks.size() - 1)
	{
		cout << "*Error. prereqIndex is out of range. " << endl;
		return;
	}

	if (prereqIndex == taskIndex)
	{
		cout << "*Error. taskIndex and prereqIndex are the same number. Can't make a prereqTask of itself. " << endl;
		return;
	}

	if (allTasks[taskIndex]->getPrereqTask() != NULL)
	{
		cout << "*Error. allTasks[" << taskIndex << "] already has a prereqTask. " << endl;
		return;
	}

	allTasks[taskIndex]->AddPrereq(allTasks[prereqIndex]);
}
void TaskList::RemovePrereq(int taskIndex)
{
// RemovePrereq: Remove the prereq of the task at the given index.
// - PRINT AN ERROR (and do nothing else) if the index is out of range,
//     or the specified task does not have a prereq.

	if (taskIndex < 0 or taskIndex > allTasks.size() - 1)
	{
		cout << "*Error. taskIndex is out of range. " << endl;
		return;
	}

	allTasks[taskIndex]->RemovePrereq();

}

void TaskList::ShowAll() const
{
// ShowAll: Loop through all entries in the allTasks vector and
//  print the Description() for each task

	for (int i = 0; i < allTasks.size(); i++)
	{
		cout << allTasks[i]->Description() << endl;
	}
}
void TaskList::ShowByTag(string theTag) const
{
// ShowByTag: Do the same as ShowAll(), but only show tasks
//  that have tags specified and whose tags include the given tag.

	for (int i = 0; i < allTasks.size(); i++)
	{
		if (allTasks[i]->HasTag(theTag))
		{
			cout << allTasks[i]->Description() << endl;
		}
	}
}
TaskList::~TaskList()
{
// Destructor
// - This needs to deallocate anything that will no longer be used now that
//     the current object itself is going away.
// - Think carefully!! Which things need to be deallocated?

	for (int i = 0; i < allTasks.size(); i++)
	{
		if (allTasks[i] != NULL)
		{
			delete allTasks[i];
		}
	}
}

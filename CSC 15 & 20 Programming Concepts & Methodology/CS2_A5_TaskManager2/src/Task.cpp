#include "Task.h"
#include "TaskList.h"
#include <iostream>
using namespace std;

Task::Task(string title, string location)
{
	// Constructor: Initializes all instance variables.
	// A newly-created task has no tags and no prereq task.

	cout << "Regular constructor called. New task created: ";
	this->title = title;
	this->location = location;
	this->numTags = 0;
	this->tags = new string[numTags];
	this->prereqTask = NULL;
	cout << "'" << this->title << "'" << endl;
}


Task::Task(const Task& otherTask)
{
	// Copy constructor: Initializes the current task as a copy of an existing task.
	// - If the existing task has an array of tags, the current
	//     task should end up with its own tags pointer pointing to
	//     a complete copy (newly allocated) of the same array.

cout << "Copy constructor created! Variable sent is now a copy of '" << otherTask.title << "'" << endl;

	this->title = otherTask.title;								//putting all info from otherClass manually
	this->location = otherTask.location;
	this->numTags = otherTask.numTags;

			this->tags = NULL;
			if (numTags > 0)			//for tags, have to do em one by one
			{
				for (int i = 0; i < numTags; i++)
				{
					this->tags[i] = otherTask.tags[i];
				}
			}

	this->prereqTask = otherTask.prereqTask;
}

void Task::AddTags(string tagsToAdd[], int size)
{
	// AddTags: Add a set of tags to the task.
	// - You may assume the tagsToAdd array is already filled with string elements,
	//     and the number of elements is given by the size parameter.
	// - This method needs to:
	//   1) PRINT AN ERROR (and do nothing else) if the task already has tags specified
	//   2) Otherwise, allocate a new dynamically allocated array and set its
	//        elements to be copies of the elements in tagsToAdd.

	cout << "Starting addTags function... ";

	if (this->numTags > 0)			//if there are tags
	{
		cout << "It appears that there are already " << this->numTags << " tags. Checking for duplicates... ";

		for (int i = 0; i < size; i++)	//loop through tagsToAdd
		{
			if (*this->tags == tagsToAdd[i])		//if the value pointed by tags are in tagsToAdd array
			{
				cout << "Error. Tags already exist. " << endl;
				return;
			}
		}

		cout << " No duplicates found! " << endl;
	}

	bool checkedForTags = false;

	if (numTags == 0)	//if we don't have any tags yet and this is the first time we are adding any
	{
		this->tags = new string[size];	//tags, formally a pointer to string, is now a pointer to an array of strings

		for (int i = 0; i < size; i++)	//loops through all of tags array
		{
			this->tags[i] = tagsToAdd[i];

			cout << this->title << "[" << i << "] now equals " << tagsToAdd[i] << ". ";

			this->numTags++;

			//cout << "Increasing numTags of " << this->title << " by 1. It is now " << this->numTags << "." << endl;

		}
		checkedForTags = true;
	}


	if (numTags > 0 and checkedForTags == false)	//if we already have tags and we are adding more
	{
		this->tags = new string[numTags + size];


		cout << "Creating a new array and adding more tags to the existing ones. Previously, there were " << this->numTags;
		this->numTags = this->numTags + size;
		cout << " tags and now there are " << size << " more. (" << this->numTags << " total) " << endl;

		for (int i = 0; i < this->numTags; i++)
		{
			//cout << "Looping through tags array. i is currently " << i  << " and numTags is " << this->numTags << endl;


			this->tags[i] = tagsToAdd[i];	//for example, if we have 2 tags already and i = 0, [0 + numTags already in array + 1] 	=	 tags[3]

			cout << this->title << "[" << i << "] now equals " << tagsToAdd[i] << ". " << endl;

//			this->numTags++;
//			cout << "numTags is now " << this->numTags << endl;
		}
	}
}

void Task::AddPrereq(Task * otherTask)
{
	// AddPrereq: Set the prereq task of the current task.
	// - You may assume otherTask is already set and points to a valid Task object.
	// - This should PRINT AN ERROR if the task already has a prereq.
	// - Otherwise, is must set the prereqTask pointer to point to the same Task object
	//    that otherTask points to.


	//cout << "Starting AddPrereq function... " << endl;

	if (this->prereqTask != NULL)
	{
		cout << "Error. Prereq already exists. " << endl;
 	}
	else
	{
		this->prereqTask = otherTask;
		cout << "'" << this->title << "'" << " now has prereqTask: '" << otherTask->title << "'" << endl;
	}
}

void Task::RemovePrereq()
{
	// RemovePrereq: Remove the prereq for the current task.
	// - PRINT AN ERROR (and do nothing else) if the current task doesn't have a prerequisite.
	// - Otherwise, set this this task to no longer have a prerequisite.
	if (this->prereqTask != NULL)
	{
		cout << "Prereq task found in '" << this->title << "'. Now removing: '" << this->prereqTask->title << "'" << endl;
		this->prereqTask = NULL;
	}
	else
	{
		cout << "Error. Task given does not have a prerequisite. " << endl;
	}
}

string Task::Description() const
{
	// Description: Return a short description string for the current Task object.
	// - Including its name, location, a list of tags (if there are any)
	//      and the title of the prereq task (if there is one).

	string entireDescription = "";

	if (this->numTags == 0 and this->prereqTask == NULL)		//if Task has neither a tag or a prereqTask
	{
		entireDescription = this->title + "@" + this->location;
	}

	else if (this->numTags > 0 and this->prereqTask == NULL)	//if Task has tags, but has no preneqTask
	{
		string allTags = "";

		for (int i = 0; i < this->numTags; i++)
		{
			allTags += this->tags[i];

			if (i < numTags - 1)
			{
				allTags += "/";
			}
		}

		entireDescription = this->title + "@" + this->location + "(" + allTags + ")";
	}

	else if (this->numTags == 0 and this->prereqTask != NULL)	//if Task has no tags, but has a prereqTask
	{
		entireDescription = this->title + "@" + this->location + " [*PrereqTask: " + this->prereqTask->title + "]";
	}

	else if (this->numTags > 0 and this->prereqTask != NULL)	//if Task has both a tag and a prereqTask
	{
		string allTags = "";

		for (int i = 0; i < this->numTags; i++)
		{
			allTags += this->tags[i];

			if (i < numTags - 1)
			{
				allTags += "/";
			}
		}

		entireDescription = this->title + "@" + this->location + "(" + allTags + ")" + " [*PrereqTask: " + this->prereqTask->title + "]";
	}

	return entireDescription;
}


bool Task::HasTag(string theTag) const
{
        // HasTag: Check if the task has theTag among its set of tags.
        // - If the task has no tags at all, you can return false immediately.
	if (this->numTags == 0)
	{
		cout << "There doesn't seem to be any tags to search through at all. " << endl;
		return false;
	}
	else
	{
		for (int i = 0; i < this->numTags; i++)
		{
			if (this->tags[i] == theTag)
			{
				cout << "Found " << theTag << "! " << endl;
				return true;
			}
		}
		cout << "It appears that this word is not one of the tags in '" << this->title << "' "<< endl;
		return false;
	}
}

Task::~Task()
{
	cout << "Deconstructor running.... " << endl;

	if (tags != NULL)
	{
		delete[] tags;
	}

//	if (prereqTask != NULL)		nvm only delete "new" stuff, not pointers
//	{
//		delete prereqTask;
//	}
}

//FUNCTIONS I MADE MYSELF TO ACCESS PRIVATE VARIABLES FROM OUTSIDE THE CLASS ------------------------------------

Task* Task::getPrereqTask()
{
	return prereqTask;
}

string Task::getTitle()
{
	return title;
}

string Task::getTag(int index)
{
	return tags[index];
}

int Task::getNumTags()
{
	return numTags;
}

//void Task::setTags(string word, int arrayNumber)
//{
//	tags[arrayNumber] = word;
//}

#ifndef TASKLIST_H_
#define TASKLIST_H_
#include "TaskList.h"
#include "Task.h"
#include <iostream>
using namespace std;

class TaskList {
private:
	//variables
	string listName;	//name for entire list
	int numTasks;	//current number of tasks on the list
	Task *allTasks[100];	//array of pointers to Task
					//each array starts out as null

public:
	//constructors
	TaskList(string lName);

	//methods
	void AddTask(string taskTitle, string taskLocation, int taskPriority);
	void CompleteTask(string taskTitle);
	void CompleteTask(int index);
	void ShowAll() const;
	void ShowByPriority(int minPriority, int maxPriority) const;
	void ShowByLocation(string location) const;
	//~TaskList();
};

#endif /* TASKLIST_H_ */

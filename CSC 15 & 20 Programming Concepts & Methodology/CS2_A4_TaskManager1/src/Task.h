#ifndef TASK_H_
#define TASK_H_
#include <iostream>
using namespace std;

class Task {
private:
	string title;
	string location;
	int priority;

public:
	//constructors
	Task(string t, string l, int p);

	//methods
	void ChangePriority(int newPriority);
	string Description() const;

	//"getter" methods for user
	string GetTitle() const;
	string GetLocation() const;
	int GetPriority() const;
};

#endif /* TASK_H_ */

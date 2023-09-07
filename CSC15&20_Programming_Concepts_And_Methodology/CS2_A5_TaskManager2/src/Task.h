
#ifndef TASK_H
#define TASK_H

#include <iostream>
using namespace std;

class Task
{
private:
	string title;
	string location;
  // These three member variables store the basic information about a task

  // The "tags" pointer will point to a dynamically-allocated array
  // of strings. Each element is a text "tag" associated with the task
  // The "tags" pointer should start out set to NULL.
  string *tags;
  // This integer stores the number of elements in the tags array.
  int numTags;

  // This pointer specifies a "prereq" task, which is a task that
  //  must be completed BEFORE this one.
  // It should start out set to NULL.
  Task *prereqTask;
public:
    // Constructor: Initializes all instance variables.
    // A newly-created task has no tags and no prereq task.
    Task(string title, string location);

    // Copy constructor: Initializes the current task as a copy of an existing task.
    // - If the existing task has an array of tags, the current
    //     task should end up with its own tags pointer pointing to
    //     a complete copy (newly allocated) of the same array.
    Task(const Task& otherTask);

    // AddTags: Add a set of tags to the task.
    // - You may assume the tagsToAdd array is already filled with string elements,
    //     and the number of elements is given by the size parameter.
    // - This method needs to:
    //   1) PRINT AN ERROR (and do nothing else) if the task already has tags specified
    //   2) Otherwise, allocate a new dynamically allocated array and set its
    //        elements to be copies of the elements in tagsToAdd.
    void AddTags(string tagsToAdd[], int size);

    // AddPrereq: Set the prereq task of the current task.
    // - You may assume otherTask is already set and points to a valid Task object.
    // - This should PRINT AN ERROR if the task already has a prereq.
    // - Otherwise, is must set the prereqTask pointer to point to the same Task object
    //    that otherTask points to.
    void AddPrereq(Task * otherTask);

    // RemovePrereq: Remove the prereq for the current task.
    // - PRINT AN ERROR (and do nothing else) if the current task doesn't have a prerequisite.
    // - Otherwise, set this this task to no longer have a prerequisite.
    void RemovePrereq();

    // Description: Return a short description string for the current Task object.
    // - Including its name, location, a list of tags (if there are any)
    //      and the title of the prereq task (if there is one).
    string Description() const;

    // HasTag: Check if the task has theTag among its set of tags.
    // - If the task has no tags at all, you can return false immediately.
    bool HasTag(string theTag) const;

    // Destructor
    // - This needs to deallocate anything that will no longer be used now that
    //     the current object itself is going away.
    // - Think carefully!! Which things need to be deallocated?
    ~Task();

    //FUNCTIONS THAT I MADE MYSELF-------------------------------------------

    Task* getPrereqTask();
    string getTitle();
    string getTag(int index);
    //void setTags(string word, int arrayNumber);
    int getNumTags();
};


#endif // TASK_H

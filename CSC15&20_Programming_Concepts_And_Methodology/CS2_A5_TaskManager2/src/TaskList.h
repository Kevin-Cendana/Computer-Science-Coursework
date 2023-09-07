#ifndef TASKLIST_H
#define TASKLIST_H

#include <iostream>
#include <vector>
#include "Task.h"
using namespace std;

class TaskList
{
private:
    vector <Task *> allTasks;

public:

    // Constructor
    // - This doesn't actually need to do anything.
    TaskList();

    // AddTask: Add a task to the TaskList.
    // - Dynamically allocate a new Task object, using the information given,
    //     and append a pointer to it to the allTasks vector.
    // - It *IS* okay for the task to have a title that matches another task on the list.
    void AddTask(string taskTitle, string taskLocation);

    // CompleteTask: Record a given task as complete by deallocating the corresponding
    // Task object and removing the given element of the allTasks vector.
    // - PRINT AN ERROR (and do nothing else) if the index is out of range.
    // - Before removing a task, if it has a prereq, STOP AND PRINT AN ERROR,
    //    telling the user the title of the task that must be completed first.
    // - Before removing the task, also check ALL tasks on the list to see if
    //    the task is the prereq of any other tasks. If any of them do, call
    //    RemovePrereq() on those tasks.
    void CompleteTask(int taskIndex);

    // AddTags: Add a set of tags to a task on the list.
    // - You may assume the tagsToAdd array is already filled with string elements,
    //    and the number of elements is given by the size parameter.
    // - This method needs to:
    //   1) PRINT AN ERROR (and do nothing else) if the index is out of range.
    //   2) PRINT AN ERROR (and do nothing ele) if the task already has tags specified.
    //   3) Otherwise, add the given set of tags to the specified task.
    void AddTags(int taskIndex, string tagsToAdd[], int size);

    // AddPrereq: Add a prereq to a task already on the list.
    // - taskIndex is the index of the task to add a prereq to.
    // - prereqIndex is the index of the prereq task.
    // - PRINT AN ERROR (and do nothing else) if any of these are true:
    //    * either index is out of range
    //    * the two index numbers are equal (you can't make a task a prereq of itself)
    //    * the specified task already has a prereq
    void AddPrereq(int taskIndex, int prereqIndex);

    // RemovePrereq: Remove the prereq of the task at the given index.
    // - PRINT AN ERROR (and do nothing else) if the index is out of range,
    //     or the specified task does not have a prereq.
    void RemovePrereq(int taskIndex);

    // ShowAll: Loop through all entries in the allTasks vector and
    //  print the Description() for each task
    void ShowAll() const;

    // ShowByTag: Do the same as ShowAll(), but only show tasks
    //  that have tags specified and whose tags include the given tag.
    void ShowByTag(string theTag) const;

    // Destructor
    // - This needs to deallocate anything that will no longer be used now that
    //     the current object itself is going away.
    // - Think carefully!! Which things need to be deallocated?
    ~TaskList();
};


#endif // _H_TaskList_

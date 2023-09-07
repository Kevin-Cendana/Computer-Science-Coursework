#ifndef ROOM_H
#define ROOM_H

#include "Thing.h"
#include <string>
#include <vector>
using namespace std;

class Room
{
private:
  string name;
  string description;

  // This is the list of things in this room (possibly none)
  vector<Thing *> contents;

 public:
  // Constructor
  Room(string name, string description);

  // Accessor method: Describe
  // (1) Print the location's name in ALL CAPS (i.e converted to uppercase)
  // (2) Print The location's description, using the
  //      Utility::PrintWrappedString() method
  // (3) Call ListContents()
  void Describe() const;

  // Method: AddThing
  // Add the given pointer to the end of the contents vector
  // You may assume the pointer already points to a valid  object.
  void AddThing(Thing* thingPtr);

  // Method: ExamineThing
  // This has one parameter, representing the NAME of a thing
  //   that may be in this location.
  // It should respond one of two ways:
  // (a) If there is no thing with the given name, print "There is no ___ here.",
  //       with the ___ replaced by the parameter value.
  // (b) If there is a matching item, call that item's Describe() method.
  void ExamineThing(string thingName) const;

  // Method: TakeThing
  // This has one parameter, representing the NAME of a thing
  //   that may be in this location.
  // It should respond one of three ways:
  // (a) If there is no thing with the given name, print "There is no ___ here.",
  //       with the ___ replaced by the parameter value.
  // (b) If there is a matching thing, but it is not an Item,
  //       print "The __ cannot be picked up."
  // (c) If there is a matching thing and it is an Item,
  //       call that object's Take method.
  void TakeThing(string thingName) const;

  // Method: DropThing
  // This has one parameter, representing the NAME of a thing
  //   that may be in this location.
  // It should respond one of three ways:
  // (a) If there is no thing with the given name, print "There is no ___ here.",
  //       with the ___ replaced by the parameter value.
  // (b) If there is a matching thing, but it is not an Item,
  //       print "The __ cannot be dropped."
  // (c) If there is a matching thing and it is an Item,
  //       call that object's Drop method.
  void DropThing(string thingName) const;

  // Method: EatThing
  // This has one parameter, representing the NAME of a thing
  //   that may be in this location.
  // It should respond in one of three ways:
  // (a) If there is no thing with the given name, print "There is no ___ here."
  // (b) If there is a matching thing but it is not a Food,
  //       print "The ___ is not edible."
  // (c) If there is a matching thing and it is a Food,
  //       call that food's Eat() method,
  //       then remove the corresponding entry from the contents vector.
  void EatThing(string thingName);

 protected:

  // Helper method: FindThing
  // This has one parameter, representing the NAME of a thing
  //   that may be in this location.
  // If something in the contents array has the given name, return the index of that element.
  // Otherwise, return -1.
  int FindThing(string thingName) const;

  // Helper method: ListContents
  // Loop through all elements (if any) of the contents vector.
  // For each element:
  //  - Check if the corresponding object is is an Item or not. (Hint: Use dynamic_cast<>)
  //  - If it is an Item, also check if it is pickedUp
  // Using additional temporary vectors as needed, prints the following output:
  // (a) A message in the form "In this room you see __ thing(s):"
  //       - Replace __ with the total number of Thing objects in the room
  //       - Do not print this at all if the number of objects is 0
  // (b) The names of all Thing objects in the room, one per line.
  // (c) A message in the form "You are holding:"
  //       - Do not print this at all if the number of pickedUp items is 0
  // (d) The names of all Item objects in the room that are pickedUp, one per line.
  void ListContents() const;

};

#endif // ROOM_H

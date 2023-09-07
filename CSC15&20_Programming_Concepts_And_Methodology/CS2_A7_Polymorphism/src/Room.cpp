#include "Room.h"
#include "Thing.h"
#include "Item.h"
#include "Food.h"
#include "Utility.h"
#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

// Constructor
Room::Room(string name, string description)
{
	//cout << "Room constructor called.. ";
	this->name = name;
	this->description = description;
	vector<Thing *> contents;
}

// Accessor method: Describe
// (1) Print the location's name in ALL CAPS (i.e converted to uppercase)
// (2) Print The location's description, using the
//      Utility::PrintWrappedString() method
// (3) Call ListContents()
void Room::Describe() const
{
	string newUpper = Utility::Uppercase(name);
	cout << newUpper << endl;

	Utility::PrintWrappedString(description);
	cout << endl;

	ListContents();
}

// Method: AddThing
 // Add the given pointer to the end of the contents vector
 // You may assume the pointer already points to a valid  object.
 void Room::AddThing(Thing* thingPtr)
 {
	 contents.push_back(thingPtr);

	 //TESTING CODE GET RID OF THIS ////////
	 //cout << "Added " << thingPtr->GetName() << " to the vector. Printing out vector..." << endl;
//	 for (int i = 0; i < contents.size(); i++)
//	 {
//		 cout << contents[i]->GetName() << " ";
//	 }
//	 cout << endl;
 }

 // Method: ExamineThing
 // This has one parameter, representing the NAME of a thing
 //   that may be in this location.
 // It should respond one of two ways:
 // (a) If there is nothing with the given name, print "There is no ___ here.",
 //       with the ___ replaced by the parameter value.
 // (b) If there is a matching item, call that item's Describe() method.
 void Room::ExamineThing(string thingName) const
 {
	 for (int i = 0; i < contents.size(); i++)
	 {
		 if (contents[i] == NULL)
		 {
			 cout << "There is no " << thingName << " here. " << endl;	//idk why i put this here tbh
		 }

		 if (contents[i]->GetName() == thingName)
		 {
			contents[i]->Describe();
			return;
		 }
	 }
	 cout << "There is no " << thingName << " here. " << endl;
 }

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
 void Room::TakeThing(string thingName) const
 {
	 for (int i = 0; i < contents.size(); i++)
	 {
		 if (contents[i] == NULL)
		 {
			 cout << "There is no " << thingName << " here. " << endl;	//just in case i guess? loop shouldn't reach null anyway
		 }

		 if (contents[i]->GetName() == thingName)
		 {
			 Item* testItem;
			 testItem = dynamic_cast<Item*>(contents[i]);

			 if (testItem != NULL)
			 {
				 testItem->Item::Take();
			 }
			 else
			 {
				 cout << "The " << thingName << " cannot be picked up. " << endl;
			 }
			return;
		 }
	 }
	 cout << "There is no " << thingName << " here. " << endl;
 }

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
 void Room::DropThing(string thingName) const
 {
	 for (int i = 0; i < contents.size(); i++)
	 {
		 if (contents[i] == NULL)
		 {
			 cout << "There is no " << thingName << " here. " << endl;	//just in case i guess? loop shouldn't reach null anyway
		 }

		 if (contents[i]->GetName() == thingName)
		 {
			 Item* testItem;
			 testItem = dynamic_cast<Item*>(contents[i]);

			 if (testItem != NULL)
			 {
				 testItem->Item::Drop();
			 }
			 else
			 {
				 cout << "The " << thingName << " cannot be dropped. " << endl;
			 }
			return;
		 }
	 }
	 cout << "There is no " << thingName << " here. " << endl;
 }

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
 void Room::EatThing(string thingName)
 {
	 for (int i = 0; i < contents.size(); i++)
	 {
		 if (contents[i] == NULL)
		 {
			 cout << "There is no " << thingName << " here. " << endl;	//just in case i guess? loop shouldn't reach null anyway
		 }

		 if (contents[i]->GetName() == thingName)
		 {
			 Food* testFood;
			 testFood = dynamic_cast<Food*>(contents[i]);

			 if (testFood != NULL)
			 {
				 testFood->Food::Eat();
				 contents.erase(contents.begin()+i);
			 }
			 else
			 {
				 cout << "The " << thingName << " is not edible. " << endl;
			 }
			return;
		 }
	 }
	 cout << "There is no " << thingName << " here. " << endl;
 }

 // Helper method: FindThing
 // This has one parameter, representing the NAME of a thing
 //   that may be in this location.
 // If something in the contents array has the given name, return the index of that element.
 // Otherwise, return -1.
 int Room::FindThing(string thingName) const
 {
	 for (int i = 0; i < contents.size(); i++)
	 {
		 if (contents[i]->GetName() == thingName)
		 {
			 return i;
		 }
	 }
	 return -1;
 }

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
 void Room::ListContents() const
 {
	 vector<Item*>pickedUpItems;

	 for (int i = 0; i < contents.size(); i++)
	 {
		 Item* testItem;
		 testItem = dynamic_cast<Item*>(contents[i]);

		 if (testItem != NULL)
		 {
			 if (testItem->IsPickedUp())
			 {
				 pickedUpItems.push_back(testItem);
			 }
		 }
	 }

	 if (contents.size() > 0)
	 {
		 cout << "In this room you see " << contents.size() << " things. " << endl;
	 }

	 for (int i = 0; i < contents.size(); i++)
	 {
		 cout << contents[i]->GetName() << endl;
	 }

	 if (pickedUpItems.size() > 0)
	 {
		 cout << endl;
		 cout << "You are holding: " << endl;
		 for (int i = 0; i < pickedUpItems.size(); i++)
		 {
			 cout << pickedUpItems[i]->GetName() << endl;
		 }
	 }
 }

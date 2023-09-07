#include "Room.h"
#include "Thing.h"
#include "Item.h"
#include "Food.h"
#include "Utility.h"
#include <iostream>
using namespace std;

// Constructor
// Note: when an Item is first created, it's pickedUp value
//  must be set to false
Item::Item(string name, string description)
	: Thing(name, description)
{
	//cout << "Item constructor called... ";
	pickedUp = false;
}

// Accessor method: IsPickedUp
// This is just an accessor. It must return the value of pickedUp
bool Item::IsPickedUp() const
{
	return pickedUp;
}

// Mutator method: Take
// If the item is already picked up, print "You are already holding the ___.",
//   with ___ replaced by the item's name.
// Otherwise, set pickedUp to true. Then print "Ok, picked up."
void Item::Take()
{
	if (pickedUp == true)
	{
		cout << "You are already holding the " << name << ". " << endl;
	}
	else
	{
		pickedUp = true;
		cout << "Ok, picked up " << this->name << ". " << endl;
	}
}

// Mutator method: Drop
// If the item is not picked up, print "You are not holding the ___.",
//   with ___ replaced by the item's name.
// Otherwise, set pickedUp to false. Then print "Ok, dropped."
void Item::Drop()
{
	if (pickedUp == false)
	{
		cout << "You are not holding the " << name << ". " << endl;
	}
	else
	{
		pickedUp = false;
		cout << "Ok, dropped " << this->name << ". " << endl;
	}
}

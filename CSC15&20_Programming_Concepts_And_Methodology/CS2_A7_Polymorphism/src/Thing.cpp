#include "Room.h"
#include "Thing.h"
#include "Item.h"
#include "Food.h"
#include "Utility.h"
#include <iostream>
using namespace std;

// Constructor
Thing::Thing(string name, string description)
{
	//cout << "Thing constructer called...";
	this->name = name;
	this->description = description;
}

// Method: GetName
// This is just an accessor. It must return this item's name.
string Thing::GetName() const
{
	return name;
}

// Method: Describe
// Print this item's description, using the
//      Utility::PrintWrappedString() method
void Thing::Describe() const
{
	Utility::PrintWrappedString(description);
}

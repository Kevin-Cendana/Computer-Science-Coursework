#include "Room.h"
#include "Thing.h"
#include "Item.h"
#include "Food.h"
#include "Utility.h"
#include <iostream>
using namespace std;

Food::Food(string name , string description, string taste, bool isGood)
	:Item(name, description)
{
	//cout << "Food constructor called... ";
	this->taste = taste;
	this->isGood = isGood;
}

void Food::Eat() const
{
	  // Accessor method: Eat
	  // Print "You eat the ___, which tastes ___.",
	  //  with the blanks filled in with the name and taste of this food.
	  // Then print "Yum!" or "Yuck!" depending on whether isGood is true or false.

	 cout << "You eat the " << name << ", which tastes " << taste << ". ";
	 	 if (isGood == true)
	 	 {
	 		 cout << "Yum!" << endl;
	 	 }
	 	 else
	 	 {
	 		 cout << "Yuck! " << endl;
	 	 }

}

void Food:: Describe() const
{
	  // Accessor method: Describe
	  // First, call the Item::Describe() method.
	  // Then, print "It looks delicious." or "It looks gross." depending on
	  //  whether isGood is true or false.
               Thing::Describe();
               if(isGood)
               {
            	   cout << "It looks delicious."<< endl;
               }

               else
               {
            	   cout << "It looks gross." << endl;
               }

}

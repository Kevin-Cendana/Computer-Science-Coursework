#ifndef FOOD_H
#define FOOD_H

#include "Item.h"
#include <string>
using namespace std;

class Food : public Item
{
 protected:
  string taste;
  bool isGood;

 public:
  // Constructor
  Food(string name, string description, string taste, bool isGood);

  // Accessor method: Eat
  // Print "You eat the ___, which tastes ___.",
  //  with the blanks filled in with the name and taste of this food.
  // Then print "Yum!" or "Yuck!" depending on whether isGood is true or false.
  virtual void Eat() const;  
  
  // Accessor method: Describe
  // First, call the Item::Describe() method.
  // Then, print "It looks delicious." or "It looks gross." depending on
  //  whether isGood is true or false.
  virtual void Describe() const;
};

#endif // FOOD_H

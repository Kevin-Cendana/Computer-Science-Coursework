#ifndef ITEM_H
#define ITEM_H

#include "Thing.h"
#include <string>
using namespace std;

class Item : public Thing
{
 protected:
  bool pickedUp;

 public:
  // Constructor
  // Note: when an Item is first created, it's pickedUp value
  //  must be set to false
  Item(string name, string description);

  // Accessor method: IsPickedUp
  // This is just an accessor. It must return the value of pickedUp
  bool IsPickedUp() const;

  // Mutator method: Take
  // If the item is already picked up, print "You are already holding the ___.",
  //   with ___ replaced by the item's name.
  // Otherwise, set pickedUp to true. Then print "Ok, picked up."
  void Take();

  // Mutator method: Drop
  // If the item is not picked up, print "You are not holding the ___.",
  //   with ___ replaced by the item's name.
  // Otherwise, set pickedUp to false. Then print "Ok, dropped."
  void Drop();
};

#endif // ITEM_H

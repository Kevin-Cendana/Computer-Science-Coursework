#ifndef THING_H
#define THING_H

#include <string>
using namespace std;

class Thing
{
 protected:
  string name;
  string description;

 public:
  // Constructor
  Thing(string name, string description);

  // Method: GetName
  // This is just an accessor. It must return this item's name.
  string GetName() const;

  // Method: Describe
  // Print this item's description, using the
  //      Utility::PrintWrappedString() method
  virtual void Describe() const;

};

#endif // THING_H

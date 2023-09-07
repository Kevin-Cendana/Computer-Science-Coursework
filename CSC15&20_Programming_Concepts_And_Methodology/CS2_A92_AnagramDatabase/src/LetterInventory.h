#ifndef LETTERINVENTORY_H
#define LETTERINVENTORY_H

#include <map>
#include <string>
using namespace std;

class LetterInventory
{
 private:
  map<char, int> counts;
  int totalCount;
  
 public:
  LetterInventory(string data = "");
  bool IsEmpty() const;
  void Show() const;
  void Insert(const LetterInventory& other);
  bool CanRemove(const LetterInventory& other);
  void Remove(const LetterInventory& other);
};

#endif

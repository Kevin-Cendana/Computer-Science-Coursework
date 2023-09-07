 #ifndef ANAGRAMSOLVER_H
#define ANAGRAMSOLVER_H
#include <vector>
#include <map>
#include "LetterInventory.h"
using namespace std;

class AnagramSolver
{
 private:
  vector<string> words;
  vector<LetterInventory> inventories;

 public:
  AnagramSolver(string filename);
  void GenerateAnagrams(string phrase, int maxWordCount);

 private:
  void RecursiveSolver(vector<string> & result, LetterInventory& remaining, int maxWordCount); 
};

#endif

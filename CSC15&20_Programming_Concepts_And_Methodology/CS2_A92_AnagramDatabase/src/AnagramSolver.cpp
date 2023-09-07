#include "AnagramSolver.h"
#include <fstream>
#include <iostream>
using namespace std;

void AnagramSolver::RecursiveSolver(vector<string> & result, LetterInventory& remaining,
		int maxWords)
{
//	result represents the current sequence of words built up so far.
//	remaining represents the remaining "supply" of letters,
//	in the form of a LetterInventory object.
//	It is this object your code needs to act on when it makes and unmakes choices.
//	maxWordCount is the maximum number of words that should make up a completed anagram.
//	If this is 0, then there is no limit on the number of words.

	if (remaining.IsEmpty() != true)
	{
		if (maxWords !=0 and result.size() == maxWords)
		{
			return;
		}
		else
		{
		for (unsigned int i = 0; i< inventories.size(); i++)
		{
			if (remaining.CanRemove(inventories[i]) == true)
			{
				result.push_back(words[i]);
				remaining.Remove(inventories[i]);
				RecursiveSolver(result,remaining,maxWords);
				remaining.Insert(inventories[i]);
				result.pop_back();
			}
		}
		}
	}
	else
	{
		for (unsigned int i = 0; i < result.size(); i++)
		{
			cout << result[i] << " ";
		}
		cout << " " << endl;
	}
}

void AnagramSolver::GenerateAnagrams(string phrase, int maxNumWords)
{
  // Note: This method is ALREADY COMPLETE.

  LetterInventory phraseInventory(phrase);
  vector<string> words;
  RecursiveSolver(words, phraseInventory, maxNumWords);
}

AnagramSolver::AnagramSolver(string filename)
{
  // Note: This method is ALREADY COMPLETE.

  ifstream fin;
  fin.open(filename.c_str());
  if (fin.fail())
    throw string("Could not open file '") + filename + "'";

  string line;
  do
    {
      getline(fin, line);
      if (line != "")
	{
	  LetterInventory obj(line);
	  inventories.push_back(obj);
	  words.push_back(line);
	}
    }
  while (!fin.eof());
}


#include "LetterInventory.h"
#include <cctype>
#include <stdio.h>
#include <ctype.h>
#include <locale>
#include <iostream>
#include <map>
using namespace std;

LetterInventory::LetterInventory(string data)
{
//	Constructor: This must initialize the new LetterInventory object,
//	containing data about the counts of each letter of the alphabet
//	found in the data string. Ignore anything that isn't a letter,
//	and treat upper and lowercase letters as equivalent.


	totalCount = 0;
	//loop to convert string to lowercase
	for (unsigned int i = 0; i < data.length(); i++)
	{
		data[i] = tolower(data[i]);
	}

	//check if char in string is alpha, and if so, add to a new string
	for (unsigned int i = 0; i < data.length(); i++)
	{
	map<char,int>::iterator iter = counts.find(data[i]);
	if (iter == counts.end() and isalpha(data[i]))
	{
		counts[data[i]] = 1;
		totalCount++;
	}
	else
	{
		if(isalpha(data[i])){
			counts[data[i]]++;
			totalCount++;
		}
	}
	}

}

void LetterInventory::Show() const
{
  // Note: This is ALREADY COMPLETE.
  // You can call it to help you test the rest of your code,
  //  as you get different methods in the LetterInventory class working.

  for (map<char, int>::const_iterator iter = counts.begin(); iter != counts.end(); iter++)
    {
      for (int k = 1; k <= iter->second; k++)
	cout << iter->first;
      if (iter->second)
	cout << " ";
    }
  cout << "\n";
}

bool LetterInventory::IsEmpty() const
{
  return (totalCount == 0);
}

void LetterInventory::Insert(const LetterInventory& other)
{
	this->totalCount += other.totalCount;
	for (map<char,int>::const_iterator iter = other.counts.begin(); iter != other.counts.end(); iter++)
	{
		this->counts[iter->first] += iter->second;
	}
}

bool LetterInventory::CanRemove(const LetterInventory& other)
{
	if (this->totalCount - other.totalCount < 0)
	{
		return false;
	}
	else
	{
		for (map<char,int>::const_iterator i = other.counts.begin(); i != other.counts.end(); i++)
		{
			if ((this->counts[i->first] - i->second) < 0)
			{
				return false;
			}
		}
		return true;
	}

}

void LetterInventory::Remove(const LetterInventory& other)
{
	if (this->CanRemove(other) != true)
	{
		throw string ("Attempt to call Remove that would yield a negative count, not possible!");
	}
	else
	{
		this->totalCount -= other.totalCount;

		for (map<char,int>::const_iterator i = other.counts.begin(); i != other.counts.end(); i++)
		{
			this->counts[i->first] -= i->second;
		}
	}
}

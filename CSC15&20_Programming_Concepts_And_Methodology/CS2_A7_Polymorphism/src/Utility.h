#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
using namespace std;

/***

 ABOUT THIS FILE

 The Utility class provides a set of STATIC utility functions
 that are likely to be useful for this project.

***/

class Utility
{
  public:
	// Returns a version of the given string with all
	// characters converted to lowercase.
	static string Lowercase(string s);

	// Returns a version of the given string with all
	// characters converted to uppercase.
	static string Uppercase(string s);

	// Returns a version of the given string converted to
	// capitalized form (first character uppercase, remaining characters lowercase)
	static string Capitalized(string s);

	// Returns a string that is equivalent to the given string,
	// but with newlines added so it is divided into lines within
	// a reasonable width.
	static void PrintWrappedString(string text);
};


#endif // UTILITY_H

/***

 ABOUT THIS FILE
 ---------------

 This code is the implementation (definitions) of all the functions
 listed in utils.h.

 THERE IS NO NEED TO READ ANY OF THIS. If anything is broken, it is my
 fault and I will fix it. You should leave all of this code alone.

***/

#include "Utility.h"
#include <cctype>
#include <cstdio>
#include <cstdlib>
using namespace std;

string Utility::Lowercase(string s)
{
  for (unsigned int i = 0; i < s.length(); i++)
    {
      s[i] = tolower(s[i]);
    }
  return s;
}

string Utility::Uppercase(string s)
{
  for (unsigned int i = 0; i < s.length(); i++)
    {
      s[i] = toupper(s[i]);
    }
  return s;
}

string Utility::Capitalized(string s)
{
  if (s.length() > 0)
    s[0] = toupper(s[0]);
  for (unsigned int i = 1; i < s.length(); i++)
    {
      s[i] = tolower(s[i]);
    }
  return s;
}

void Utility::PrintWrappedString(string text)
{
  const int MAX_WIDTH = 60;
    string str=text;
    unsigned long pos = 0;
    unsigned long last = 0;
    while ((pos = str.find(" ", pos)) != string::npos)
    {
      if ((pos - last) > MAX_WIDTH)
        {
            str[pos] = '\n';
            last = pos;
        }
        pos++;
    }
    cout << str << endl;
}

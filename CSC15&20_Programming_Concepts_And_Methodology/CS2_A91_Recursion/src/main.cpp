#include <iostream>
using namespace std;

bool IsPowerOfTwo(int n);
string ReplaceEsWithAs(string s);
int DigitSum(int n);

int main()
{
	cout << "Hello! " << endl;
}

bool IsPowerOfTwo(int n)
/// Determines if n is an exact positive power of 2
/// (For instance: 2, 4, 8, 128, and 1024)
{
	//cout << "n is currently: " << n << endl;
	// base cases
	if (n == 2)
		return true;
	else if (n < 2 or n%2!=0)
		return false;

	// recursive step
	else
	{
		return IsPowerOfTwo(n/2);
	}
}

string ReplaceEsWithAs(string s)
{
	if (s.find('e') == std::string::npos) //if 'e' is not found in the string
	{
		return s;
	}
	else
	{
		int e = s.find('e');
		s[e] = 'a';
		return ReplaceEsWithAs(s);
	}
}

int DigitSum(int n)
{
	//get the rightmost number of n using %
	//shave off the rightmost number of n with / and send

	if (n == 0)
	{
		return 0;
	}
	return (n % 10 + DigitSum(n/10));
}

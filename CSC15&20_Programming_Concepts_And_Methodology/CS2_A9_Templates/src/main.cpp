#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

template<typename T>
T Pick(T p1, T p2, T p3);

template<typename T>
T GetChoice(string x, string y, T a, T b);

template<typename T>
class UniqueList
{
private:
	vector<T>items;
public:
	//UniqueList();
	void Insert(T item);
	int Size();
	T GetFirst();
	T GetLast();
	T GetMax();
	T GetMin();
};


template <typename T>	//you have to add template, UniqueList, and <T>
T Pick(T p1, T p2, T p3)
{
	srand (time(NULL));
	int rng = rand() % 3 + 1;
	if (rng == 1)
	{
		//cout << "Variable selected: " << p1 << endl;
		return p1;
	}
	if (rng == 2)
	{
		//cout << "Variable selected: " << p2 << endl;
		return p2;
	}
	if (rng == 3)
	{
		//cout << "Variable selected: " << p3 << endl;
		return p1;
	}

	return p1;
}

template<typename T>
T GetChoice(string x, string y, T a, T b)
{
	while (true)
	{
		string userInput;
		cout << "Please pick " << x << " or " << y << ": ";
		getline(cin, userInput);
		if (userInput == x)
		{
			return a;
		}
		else if (userInput == y)
		{
			return b;
		}
	}
}

template <typename T>	//you have to add template, UniqueList, and <T>
void UniqueList<T>::Insert(T item)
{
//	Inserts the given item (of type T) into the list.
//	If something equal to the given item
//	already exists in the list, print an error
//	and do NOT change the contents of the list.

	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (items[i] == item)
		{
			cout << "Item is already on the list. " << endl;
			return;
		}
	}

	items.push_back(item);

//	cout << "Entire Vector: ";
//	for (int i = 0; i < items.size(); i++)
//	{
//		cout << items[i] << ", ";
//	}
//	cout << endl;
}

template <typename T>	//you have to add template, UniqueList, and <T>
int UniqueList<T>::Size()
{
	//Returns the total number of items in the list.

	//cout << "Returning Total Number of Items in the List: " << items.size() << endl;
	return items.size();
}

template <typename T>	//you have to add template, UniqueList, and <T>
T UniqueList<T>::GetFirst()
{
	//Returns a copy of the first item inserted.

	if (items.size() > 0)
	{
		T copy = items.front();
		return copy;
	}
	else
	{
		string error = "There doesn't seem to be anything in the vector. ";
		return error;
	}
}

template <typename T>	//you have to add template, UniqueList, and <T>
T UniqueList<T>::GetLast()
{
	//Returns a copy of the most recent item inserted.
	if (items.size() > 0)
	{
		T copy = items[items.size() - 1];
		return copy;
	}
	else
	{
		string error = "There doesn't seem to be anything in the vector. ";
		return error;
	}
}

template <typename T>	//you have to add template, UniqueList, and <T>
T UniqueList<T>::GetMax()
{
//	Returns a copy of the maximum value item
//	among the items in the list.
//	(You can assume the type used for the items
//		in the box works with comparison operators like <, >, <= and so on.)

	if (items.size() > 0)
	{
		return *std::max_element( items.begin(), items.end() );
	}
	else
	{
		string error = "There doesn't seem to be anything in the vector. ";
		return error;
	}

}

template <typename T>	//you have to add template, UniqueList, and <T>
T UniqueList<T>::GetMin()
{
//	Returns a copy of the minimum value item
//	among the items in the list.
//	(You can assume the type used for the items
//		in the box works with comparison operators like <, >, <= and so on.)

	if (items.size() > 0)
	{
		return *std::min_element( items.begin(), items.end() );
	}
	else
	{
		string error = "There doesn't seem to be anything in the vector. ";
		return error;
	}

}

int main() {

	string word1 = "AAAAAAAAAAAAAAHHHHHHHHHHHHHH";
	string word2 = "Zimbabwe";
	string word3 = "floop";

//Part 1
	cout << "*Testing Part 1: " << endl;
	cout << "Random Variable Selected: " << Pick(word1,word2,word3) << endl;

//Part 2
	cout << "*Testing Part 2: " << endl;
	string animalNoise = GetChoice("cat","dog","meow","woof");
	cout << animalNoise << endl;

	int numChoice = GetChoice("seven", "eleven", 7, 11);
	cout << numChoice << endl;


//Part 3
	cout << "*Testing Part 3: " << endl;
	//Testing Insert -

	UniqueList<string> list;
	list.Insert(word1);
	list.Insert(word2);
	list.Insert(word3);

	//Testing Size -
	cout << "Size of List: " << list.Size() << endl;

	//Testing GetFirst -
	cout << "First Item in List: " << list.GetFirst() << endl;

	//Testing GetLast -
	cout << "Last Item in List: " << list.GetLast() << endl;

	//Testing GetMax -
	cout << "Largest Item in List: " << list.GetMax() << endl;

	//Testing GetMin -
	cout << "Smallest Item in List: " << list.GetMin() << endl;
}

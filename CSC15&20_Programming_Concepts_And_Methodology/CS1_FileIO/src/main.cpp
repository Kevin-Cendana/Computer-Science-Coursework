//============================================================================
// Name        : scratchpaper.cpp
// Author      : me
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

// function PROTOTYPES
void ReadData(string filename);
void EnterData(string filename);
void SearchData(string filename);

int main() {
	int choice;
	string whichFile = "";
	cout << "Enter a filename: ";
	getline(cin, whichFile);

	cout << "(1) Read/Display, (2) Enter, (3) Search: ";
	cin >> choice;
	cin.ignore(1000, '\n');

	if (choice == 1)
	{
		// function CALL
		ReadData(whichFile);
	}
	else if (choice == 2)
	{
		EnterData(whichFile);
	}
	else if (choice == 3)
	{
		SearchData(whichFile);
	}
}

// function DEFINITION
void ReadData(string filename)
{
	string userName = "";
	string title = "";
	int rating = 0;

	ifstream fin;
	fin.open(filename.c_str());

	if (fin.fail())
	{
		cout << "** Could not open data file!" << endl;
	}
	else
	{
		getline(fin, userName);
		cout << userName << "'s rating" << endl;
		cout << "================================" << endl;

		int counter = 0;	//
		do
		{
			getline(fin, title);
			fin >> rating;
			fin.ignore();
			cout << rating << "  " << title << endl;
			counter++; //
		}
		while (fin.eof() == false);

		cout << counter;	//
		fin.close();
	}
}
void EnterData(string filename)
{
	string userName = "";
	string title = "";
	int rating = 0;

	ofstream fout;
	fout.open(filename.c_str());

	cout << "Enter a username: " << endl;
	getline(cin, userName);

	fout << userName << endl;

	while (true)
	{
		cout << "Enter title ('done' to end): ";
		getline(cin,title);
		if (title == "done")
		{
			break;
		}
		cout << "Enter rating for " << title << ": ";
		cin >> rating;
		cin.ignore(1000, '\n');

		fout << title << endl;
		fout << rating << endl;
	}

	fout.close();
}
void SearchData(string filename)
{
	string userName = "";
	string title = "";
	int rating = 0;
	string titleSearch = "";

	cout << "Enter a title to search for. " << endl;
	getline(cin, titleSearch);

	ifstream fin;
	fin.open(filename.c_str());

	if (fin.fail())
	{
		cout << "** Could not open data file!" << endl;
	}
	else
	{
		getline(fin, userName);

		do
		{
			getline(fin, title);
			if (fin.eof())
			{
				break;
			}
			fin >> rating;
			fin.ignore();
			if (title == titleSearch)
			{
				cout << userName << " gave " << title << endl;
				cout << " a rating of " << rating << endl;
				fin.close();
				return;
			}
		}
		while (true);

		cout << "No match found. " << endl;

		fin.close();
	}
}

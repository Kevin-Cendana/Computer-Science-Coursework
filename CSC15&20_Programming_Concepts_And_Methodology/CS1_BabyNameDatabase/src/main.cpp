#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	vector <string> boyNames;
	vector <string> girlNames;
	fstream boyFile;
	fstream girlFile;
	string line = "";

	//Open boy file
	boyFile.open("names-m.txt");
	if (boyFile.fail())
	{
		cout << "File failed to open :( " << endl;
	}
	else
	{
		while (getline(boyFile, line))
		{
			boyNames.push_back(line);
		}
	}
	boyFile.close();

	//Open girl file
	girlFile.open("names-f.txt");
	if (girlFile.fail())
	{
		cout << "File failed to open :( " << endl;
	}
	else
	{
		while (getline(girlFile, line))
		{
			girlNames.push_back(line);
		}
	}
	girlFile.close();

	//User interface
	while (true)
	{
		string name = "";
		int boyRank = 0;
		int girlRank = 0;
		cout << "Enter a name (Enter nothing to terminate): ";
		getline(cin, name);

		if(name == "")
		{
			return 0;
		}

		for (unsigned int i = 0; i < boyNames.size(); i++)
		{
			if (boyNames[i] == name)
			{
				boyRank = i + 1;
			}
			if (girlNames[i] == name)
			{
				girlRank = i + 1;
			}
		}

		if (girlRank > 0)
		{
			cout << name << " was #" << girlRank << " on the list of female names. " << endl;
		}
		else
			cout << name << " was not in the top 5000 of female names. " << endl;

		if (boyRank > 0)
		{
			cout << name << " was #" << boyRank << " on the list of male names. " << endl;
		}
		else
			cout << name << " was not in the top 5000 of male names. " << endl;

		cout << endl;
	}
	return 0;
}

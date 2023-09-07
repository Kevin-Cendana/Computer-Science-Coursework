#include <iostream>
#include <vector>
using namespace std;

struct Student
{
	string name = "";
	int idNum = 0;
	double quizAverage = 0.0;
	char grade = '-';
};

int main() {

	//Phase A: Creating student data
	vector <Student> studentDatabase;
	int numStudents = 0;
	int counter = 0;
	cout << " STUDENT DATA ENTRY " << endl;
	cout << "==================== " << endl;
	cout << "Enter number of students: ";
	cin >> numStudents;

	//Loop that creates X amount of student's data
	while(counter < numStudents)
	{
		Student currentStudent;
		double quizScore = 0;
		double quizTotal = 0;

		//Gather Student Name and ID
		cout << endl;
		cout << "Enter name of student #" << counter + 1 << ": ";
		cin.ignore();
		getline(cin, currentStudent.name);
		cout << "Enter " << currentStudent.name << "'s ID number: ";
		cin >> currentStudent.idNum;

		//Calculate student average quiz score from 5 quizzes
		for (int i = 0; i < 5; i++)
		{
			cout << "Enter score for quiz #" << i + 1<< " for " << currentStudent.name << ": ";
			cin >> quizScore;
			quizTotal += quizScore;
		}
		currentStudent.quizAverage = quizTotal / 5;

		//Calculate student grade from average quiz score
		if (currentStudent.quizAverage >= 90){ currentStudent.grade = 'A'; }
		else if (currentStudent.quizAverage >= 80){ currentStudent.grade = 'B'; }
		else if (currentStudent.quizAverage >= 70){ currentStudent.grade = 'C'; }
		else if (currentStudent.quizAverage >= 60){ currentStudent.grade = 'D'; }
		else { currentStudent.grade = 'F'; }

		//Add student to student database vector and increment while counter.
		studentDatabase.push_back(currentStudent);
		counter++;
	}
	cout << "Student data entry is complete. " << endl;
	cout << endl;

	//Phase B: Search student data
	int idNum = 0;
	cout << " STUDENT DATA SEARCH " << endl;
	cout << "===================== " << endl;

	while (true)
	{
		bool found = false;
		cout << "Enter student ID to search for ('-1' to stop): ";
		cin >> idNum;

		if (idNum == -1)
		{
			break;
		}

		//Linear search through entire student database for any matching IDs
		for (unsigned int i = 0; i < studentDatabase.size(); i++)
		{
			if (studentDatabase[i].idNum == idNum)
			{
				found = true;
				cout << "Student: " << studentDatabase[i].name << endl;
				cout << "ID: " << studentDatabase[i].idNum << endl;
				cout << "Quiz Average: " << studentDatabase[i].quizAverage << endl;
				cout << "Grade: " << studentDatabase[i].grade << endl;
			}
		}

		if (found == false)
		{
			cout << "No student found with ID number: " << idNum << endl;
		}
	}

	cout << "Goodbye :) ";

	return 0;
}

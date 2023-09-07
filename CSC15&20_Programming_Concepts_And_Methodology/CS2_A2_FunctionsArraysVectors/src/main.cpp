#include <iostream>
#include <vector>
using namespace std;

void Trivia(string questions[], string answers[], int size)
{
	string userAnswer;
	double correctCounter = 0;

	for (int i = 0; i < size; i++)
	{
		cout << questions[i];
		getline(cin,userAnswer);
		if (userAnswer == answers[i])
		{
			cout << "Congratulations! You got the question correct. " << endl;
			correctCounter++;
		}
		else
		{
			cout << "Whoops, that's not right. " << endl;
		}
	}

	double percentCorrect = correctCounter/size;

	cout << "You got " << percentCorrect*100 << "% correct! " << endl;
}

vector<double> InputScores(double maxScore)
{
	vector<double>scores;
	double userScore;

	while (true)
	{
		cout << "Please enter a score between 0 and " << maxScore << " (-999 to exit). " << endl;
		cin >> userScore;

		if (userScore == -999)
		{
			break;
		}

		if (userScore < 0 or userScore > maxScore)
		{
			cout << "Error. Maybe your number is out of range?. " << endl;
			cin.ignore();
		}
		else
		{
			scores.push_back(userScore);
		}
	}

	return scores;
}

double CalculateAverage(vector<double> scores)
{
	double total = 0;

	if (scores.empty())
	{
		cout << "This vector is empty. " << endl;
		return 0;
	}
	else
	{
		for (unsigned int i = 0; i < scores.size(); i++)
		{
			total += scores[i];
		}
		return total/scores.size();
	}
}


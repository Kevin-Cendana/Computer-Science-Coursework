#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int main() {

	//Task 1
	string pizza = "";
	double diameter = 0.0;
	double slices = 0.0;

	cout << "Hello! What kind of pizza do you want?" << endl;
	cin >> pizza;
	cout << "In inches, what is the diameter of the pizza you want?" << endl;
	cout << "(Basically, how long it would be from end to end in inches?):" << endl;
	cin >> diameter;
	cout << "How many slices would you like?" << endl;
	cin >> slices;
	cin.ignore();

	double radius = diameter/2;
	double area = 3.14*radius*radius;
	double perslice = area/slices;

	cout << "Each slice of that " << pizza << " pizza should be " << perslice << " square inches." << endl;
	cout << endl;

	//Task 2

	string movie = "";
	double childtickets = 0.0;
	double adulttickets = 0.0;

	cout << "What movie would you like to watch? " << endl;
	cin >> movie;
	cout << "How many child tickets would you like to purchase? " << endl;
	cin >> childtickets;
	cout << "How many adult tickets would you like to purchase? " << endl;
	cin >> adulttickets;

	double childticketprice = 5*childtickets;
	double adultticketprice = 8*adulttickets;
	double total = childticketprice + adultticketprice;
	double profit = total*.23;

	cout << "Movie Name: 		" << movie << endl;
	cout << "Child Tickets Sold:	" << childtickets << endl;
	cout << "Adult Tickets Sold:	" << adulttickets << endl;
	cout << "Total Sales Amount:	$" << total << endl;
	cout << "Profit:			$" << profit << endl;
	cout << endl;

	//Task 3

	cout << "Let's play a Mad Libs game!" << endl;

	string color = "";
	string adjective = "";
	string object = "";
	string animal = "";
	string videogame = "";
	string celebrity = "";
	string spell = "";

	cin.clear();
	cin.ignore();
	cout << "Name a color." << endl;
	getline(cin, color);
	cout << "Name an adjective." << endl;
	getline(cin, adjective);
	cout << "Name an object." << endl;
	getline(cin, object);
	cout << "Name an animal." << endl;
	getline(cin, animal);
	cout << "Name a video game." << endl;
	getline(cin, videogame);
	cout << "Name a celebrity." << endl;
	getline(cin, celebrity);
	cout << "Name a magical spell." << endl;
	getline(cin, spell);
	cout << endl;

	cout << "The other day, I was wearing my favorite " << color << " shirt when I came across a " << adjective << " looking " << animal << "!" << endl;
	cout << "I took it home as a pet and let it use my " << object << " as a toy. " << endl;
	cout << "I jumped onto the couch and loaded up my favorite RPG, " << videogame << ". "<< endl;
	cout << "I tried their online game mode and managed to queue into " << celebrity << ". " << endl;
	cout << "It was a close match but I hit him with the ol' " << spell << " and defeated them. " << endl;
	cout << endl;

	//Task 4

	double deposit = 0.0;
	double interest = 0.0;

	cout << "What is your initial deposit? " << endl;
	cin >> deposit;
	cout << "What is your interest rate? " << endl;
	cin >> interest;

	double amountone = 1 + interest/1200;
	double amounttwo = pow(amountone, 12);
	double amountthree = amounttwo*deposit;
	double amountfour = amountthree - deposit;

	cout << "Interest Rate:	" << interest << "% " << endl;
	cout << "Principal:	" << "$" << deposit << endl;
	cout << "Final Amount:	" << "$" << amountthree << endl;
	cout << "Amount gained:	" << "$" << amountfour << endl;
	cout << endl;

	//Task 5

	string answer = "";
	int number1 = 0;
	int number2 = 0;
	int number3 = 0;
	int number4 = 0;
	int number5 = 0;
	int number6 = 0;
	int number7 = 0;
	int number8 = 0;
	int number9 = 0;
	srand(time(0));
	number1 = 1 + rand()%6;
	number2 = 1 + rand()%6;
	number3 = 1 + rand()%6;
	number4 = number1 + number2 + number3;
	number5 = 1 + rand()%6;
	number6 = 1 + rand()%6;
	number7 = 1 + rand()%6;
	number8 = number5 + number6 + number7;
	number9 = number8 + number4;

	cout << "Rolling three dice...." << endl;
	cout << "You rolled: " << number1 << ", " << number2 << ", " << number3 << endl;
	cout << "Current total: " << number4 << endl;
	cout << "Roll again? (y/n) " << endl;
	getline (cin, answer);
	cin >> answer;

	if (answer == "y")
	{
		cout << "Rolling again... " << endl;
		cout << "You rolled: " << number5 << ", " << number6 << ", " << number7 << endl;
		cout << "Final total: " << number9 << endl;

		if (number9 > 21){
			cout << "You lose, sorry. " << endl;}
		if (number9 >= 16 and number9 <= 21){
			cout << "You get a gold trophy! " << endl;}
		if (number9 >= 10 and number9 <= 15){
			cout << "You get a silver trophy! " << endl;}
		if (number9 < 10){
			cout << "You get a bronze trophy! " << endl;}
		}
		else
		{
			if (number4 > 21){
				cout << "You lose, sorry. " << endl;}
			if (number4 >= 16 and number4 <= 21){
				cout << "You get a gold trophy! " << endl;}
			if (number4 >= 10 and number4 <= 15){
				cout << "You get a silver trophy! " << endl;}
			if (number4 < 10){
				cout << "You get a bronze trophy! " << endl;}
		}

		return 0;
}


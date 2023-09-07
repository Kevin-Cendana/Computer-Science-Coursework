#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Part A
	double userMiles = 0;
	double userGallons = 0;

	cout << "How many miles did you drive last week? ";
	cin >> userMiles;
	cout << "How many gallons of gas did you use during that time? ";
	cin >> userGallons;
	cout << "Your average gas mileage (MPG): " << userMiles / userGallons << endl;
	cout << endl;

	//Part B
	double userFeet = 0;
	double userInches = 0;

	cout << "Please enter your height in feet only: ";
	cin >> userFeet;
	cout << "Please enter the rest of your height in inches: ";
	cin >> userInches;

	double inchHeight = (userFeet*12) + userInches;
	cout << "Your height in inches: " << inchHeight << endl;
	cout << "Your height in centimeters: " << inchHeight * 2.54 << endl;
	cout << endl;

	//Part C
	string userName = "";
	string item1, item2, item3 = "";
	double price1, price2, price3 = 0;

	cout << "What is your name? ";
	cin >> userName;
	cin.ignore();
	cout << "Enter 1st item: ";
	getline(cin, item1);
	cout << "Enter price of the " << item1 << ": ";
	cin >> price1;
	cin.ignore();
	cout << "Enter 2nd item: ";
	getline(cin, item2);
	cout << "Enter price of the " << item2 << ": ";
	cin >> price2;
	cin.ignore();
	cout << "Enter 3rd item: ";
	getline(cin, item3);
	cout << "Enter price of the " << item3 << ": ";
	cin >> price3;

	double subtotal = price1 + price2 + price3;
	double tax = subtotal * 0.0925;
	double total = subtotal + tax;

	cout << setw(10) << "Receipt for " << userName << ": " << endl;
	cout << setw(10) << item1 << " $" << price1 << endl;
	cout << setw(10) << item2 << " $" << price2 << endl;
	cout << setw(10) << item3 << " $" << price3 << endl;
	cout << setw(10) << "Subtotal " << " $" << subtotal << endl;
	cout << setw(10) << "Tax " << " $" << tax << endl;
	cout << setw(10) << "TOTAL " << " $" << total << endl;

	return 0;
}

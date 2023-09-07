#include "PairValue.h"
#include <iostream>
#include <tgmath.h>
using namespace std;

//The constructor must initialize the two member variables appropriately.
//The Show() should simply prints out the x and y values. (I will mostly use this for testing, and you can use it for your own testing as you complete the rest of the assignment.)
//Then, add functionality to make the PairValue class work with each redefined operators described

PairValue::PairValue(double x, double y)
{
//	cout << "Constructer called - Pair Value being created. " << endl;
	this->x = x;
	this->y = y;
}

void PairValue::Show() const
{
	cout << "This PairValue's numbers: (" << x << ", " << y << ")" << endl;
}

PairValue PairValue::operator+(PairValue rightSide)
{
	PairValue result = *this;	//result is a PairValue equaling the current object
	result.x += rightSide.x;
	result.y += rightSide.y;
	return result;
}

PairValue PairValue::operator-(PairValue rightSide)
{
	PairValue result = *this;	//result is a PairValue equaling the current object
	result.x -= rightSide.x;
	result.y -= rightSide.y;
	return result;
}

PairValue PairValue::operator*(double rightSide)
{
	PairValue result = *this;	//result is a PairValue equaling the current object
	result.x *= rightSide;
	result.y *= rightSide;
	return result;
}

double PairValue::operator%(PairValue rightSide)
{
	//Formula: distance = sqrt((x1-x2)2 + (y1-y2)2)

	PairValue result = *this;

	result.x = pow(result.x - rightSide.x,2);
	result.y = pow(result.y - rightSide.y,2);

	double resultInDouble = sqrt(result.x + result.y);

	return resultInDouble;
}

PairValue& PairValue::operator++()
{
	PairValue oldValues(this->x,this->y);

	this->x = -(oldValues.y);
	this->y = oldValues.x;

	return *this;

}

PairValue::operator double()
{
	return (x*y);
}

ostream& operator<<(ostream& os, PairValue rightSide)
{
	os << "(" << rightSide.x << ", " << rightSide.y << ")";
	return os;
}

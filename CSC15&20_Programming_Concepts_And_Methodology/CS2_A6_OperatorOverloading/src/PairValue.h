#ifndef PAIRVALUE_H_
#define PAIRVALUE_H_
#include <iostream>
using namespace std;

class PairValue
{
 private:
  double x;
  double y;
 public:
   PairValue(double x, double y);
   void Show() const;
   PairValue operator+(PairValue rightSide);
   PairValue operator-(PairValue rightSide);
   PairValue operator*(double rightSide);
   double operator%(PairValue rightSide);
   PairValue& operator++();
   operator double();
   friend ostream& operator<<(ostream& os, PairValue rightSide);

};

#endif /* PAIRVALUE_H_ */

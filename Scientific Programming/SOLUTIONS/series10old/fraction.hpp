 #ifndef _FRACTION_
 #define _FRACTION_

#include <iostream>
#include <cmath>
#include <cassert>

class Fraction {

private:
 int p;
 int q;

 public:
 Fraction();//standard constructor
 Fraction(int, int);//constructor
 Fraction(const Fraction&);//copy constructor
 ~Fraction();//destructor
 Fraction& operator=(const Fraction&);//assignment operator

 int num() const;
 int den() const;
 double abs() const;
 void print() const;

 operator double() const;

 const Fraction operator~() const;
 const Fraction operator-() const;

 };

 std::ostream& operator<<(std::ostream& output,
const Fraction& x);
 const Fraction operator+(const Fraction&, const Fraction&);
 const Fraction operator-(const Fraction&, const Fraction&);
 const Fraction operator*(const Fraction&, const Fraction&);
 const Fraction operator/(const Fraction&, const double);
 const Fraction operator/(const Fraction&, const Fraction&);

 #endif

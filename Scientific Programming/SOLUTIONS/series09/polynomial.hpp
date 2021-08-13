#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_

#include<iostream>
#include<cassert>
#include<cmath>

using namespace std;

//the class stores polynomial of degree n
class Polynomial{
private:
  int deg;
  double* coeff;
public:
  //constructors and destructors
Polynomial();//standard constructor
Polynomial(int deg);// constructor
Polynomial(const Polynomial& rhs);//copy constructor

~Polynomial();//destructor
Polynomial& operator=(const Polynomial& rhs); //assignment operator

//method to get polynomial degree n, a natural number
int degree() const;

//operator double() const;

void print() const;

//provides access to coefficients of polynomial for constant objects
const double& operator [](int j) const;

//provides access to coefficients of polynomial for normal objects
double& operator [](int j);
};

//possibility of printing via "cout<<p"
std::ostream& operator<<(std::ostream& output, const Polynomial& p);

#endif

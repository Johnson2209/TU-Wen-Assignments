#include "fraction.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main() {
 Fraction w;
 Fraction x(1,2);
 Fraction y(2,1);
 Fraction m(5,-6);
 // Fraction k(3,0);    //Assertion fail example

 cout << "w = " << w << endl;
 cout << "x = " << x << endl;
 cout << "y = " << y << endl;
 cout << "m = " << m << endl;

 w = x;
 cout << "x = w = " << w << "\n";

 Fraction z(x);
 cout << "z = " << z << endl;

 return 0;
}

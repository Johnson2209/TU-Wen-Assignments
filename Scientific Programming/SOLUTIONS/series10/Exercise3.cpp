#include "fraction.hpp"
#include <iostream>
using std::cout;

int main() {
 Fraction x(1,2);
 Fraction y(4,3);
 double a = 0.125;
 double b = 1.187444567436;

 double c = x;
 cout << x << " = " << c << "\n";

 double d = y;
 cout << y << " = " << d << "\n";

 Fraction w = a;
 cout << a << " = " << w << "\n";

 Fraction z = b;
 cout << b << " = " << z << "\n";

 return 0;
}

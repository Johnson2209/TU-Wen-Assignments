#include "fraction.hpp"
#include <iostream>
using std::cout;

int main() {

   Fraction x(1,2);
   cout << "x = " << x;
   x.reduce();
   cout << " = " << x << "\n";
   Fraction y(3,9);
   cout << "y = " << y;
   y.reduce();
   cout << " = " << y << "\n";
   Fraction z(4,2);
   cout << "z = " << z;
   z.reduce();
   cout << " = " << z << "\n";

   return 0;
}

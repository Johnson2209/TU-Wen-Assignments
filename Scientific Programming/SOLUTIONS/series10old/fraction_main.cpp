#include "fraction.hpp"
#include <iostream>
 using std::cout;

int main() {
Fraction w;
Fraction x(1,0);
 Fraction y(0,1);
Fraction z(3,4);

 w = x + y;
 cout << w << "\n";

 w = x - y;
 cout << w << "\n";

 w = x*y;
 cout << w << "\n";

 w = x/y;
 cout << w << "\n";





 return 0;
 }

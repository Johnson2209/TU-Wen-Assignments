#include "fraction.hpp"
#include <iostream>
using std::cout;

int main() {
 Fraction x(1,2);
 Fraction y(3,5);
 Fraction z(9,20);

 FractionVector w(3,x);
 w[1] = y;
 w[2] = z;

 cout << "Before sorting \n";
 cout << w << "\n";

 w.sort();

 cout << "After sorting \n";
 cout << w << "\n";

 return 0;
}

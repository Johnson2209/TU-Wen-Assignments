#include "fraction.hpp"
#include <iostream>
using std::cout;

int main() {
 Fraction x(1,2);
 Fraction y(7,8);
 Fraction z(3,4);

 FractionVector w(3,x);
 cout << "w = " << w << "\n";

 FractionVector k(w);
 cout << "k = " << k << "\n";

 FractionVector s = w;

 cout << "Length of s : " << s.length() << "\n";

 s[0] = z;
 s[2] = y;
 cout << "s = " << s << "\n";

 return 0;
}

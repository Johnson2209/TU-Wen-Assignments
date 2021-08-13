#include "fraction.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main() {
 Fraction w;
 Fraction x(1,2);
 Fraction y(2,1);
 Fraction z(3,4);
 cout << "w = " << w << endl;
 cout << "x = " << x << endl;
 cout << "y = " << y << endl;
 cout << "z = " << z << endl;

 cout << "-w = " << -w << endl;
 cout << "-x = " << -x << endl;
 cout << "-y = " << -y << endl;
 cout << "-z = " << -z << endl;

 return 0;
}

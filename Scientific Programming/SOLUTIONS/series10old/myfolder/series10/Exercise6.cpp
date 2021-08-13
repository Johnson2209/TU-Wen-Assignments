#include "fraction.hpp"
#include <iostream>
using std::cout;

int main() {
 Fraction w;
 Fraction x(1,2);
 Fraction y(20,3);
 Fraction z(3,4);

 cout << "x = " << x << "\n";
 cout << "y = " << y << "\n";
 cout << "z = " << z << "\n";
 cout << "w = " << w << "\n\n";

 bool t1 = x==y;
 bool t2 = y!=z;
 bool t3 = x>w;
 bool t4 = z<=x;

 cout << "x == y : " << t1 << "\n";
 cout << "y != z : " << t2 << "\n";
 cout << "x > w : " << t3 << "\n";
 cout << "z <= x : " << t4 << "\n";

 return 0;
}

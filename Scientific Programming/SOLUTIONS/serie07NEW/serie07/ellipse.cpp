#include <iostream>
#include "ellipse.hpp"

using std::cin;
using std::cout;
using std::endl;

int main() {
 Ellipse ell;
 double x0, y0, a, b, x, y;
 cout << "Enter center: " << endl;
 cin >> x0 >> y0;
 cout << "Enter a and b : ";
 cin >> a >> b;
 cout << "Enter the coordinates to check" <<endl;
 cin >> x >> y;

 ell.setCenter(x0,y0);
 ell.setA(a);
 ell.setB(b);

 if (ell.isInside(x,y)) {
   cout << "The point (" << x << "," << y << ") is in the ellipse \n";
 }
 else {
   cout << "The point (" << x << "," << y << ") is not in the ellipse\n";
 }

 ell.printFocalPoints();
 cout << "The eccentricity is " << ell.getEccentricity() << endl;

 if (ell.isCircle()) {
   cout << "The ellipse is also a circle\n";
 }
 else {
   cout << "The ellipse is not a circle\n";
 }

 return 0;
}

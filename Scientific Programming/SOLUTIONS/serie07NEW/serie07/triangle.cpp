#include <iostream>
#include "triangle.hpp"

using std::cout;
using std::endl;

int main() {
 Triangle tri;
 tri.setX(0.0,0.0);
 tri.setY(1.0,0.0);
 tri.setZ(0.0,1.0);
 cout << "Area = " << tri.getArea() << endl;
 cout << "Perimeter = " << tri.getPerimeter() << endl;
 if (tri.isEquilateral()) {
   cout << " The triangle is equilateral\n";
 }
 else {
   cout << "The triangle is not equilateral\n";
 }

 return 0;
}

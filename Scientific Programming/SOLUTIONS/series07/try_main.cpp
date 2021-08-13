#include "vector_first.hpp"
 #include <iostream>

using std::cout;
int main() {
Vector vector1;
Vector vector2(20);
Vector vector3(100,4);
 cout << "Norm = " << vector1.norm() << "\n";
 cout << "Norm = " << vector2.norm() << "\n";
 cout << "Norm = " << vector3.norm() << "\n";

 return 0;
 }

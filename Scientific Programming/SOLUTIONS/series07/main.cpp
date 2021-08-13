//main.cpp
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
// Compile with
//g++ -c vector first.cpp
g++ main.cpp vector first.o
//Output:
//allocate empty vector
//allocate vector, length 20
//allocate vector, length 100
//Norm = 0
//Norm = 0
//Norm = 40
//free vector, length 100
//free vector, length 20
//free vector, length 0

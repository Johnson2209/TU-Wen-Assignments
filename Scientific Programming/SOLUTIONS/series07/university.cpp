#include <iostream>
#include "university.hpp"

using std::cout;
using std::endl;

int main() {
 University uni;
 uni.setName("Afia");
 uni.setCity("Mainz");
 uni.setNumStudents(20);
 uni.graduate();
 cout << "One student graduated -> New Num_Students: " << uni.getNumStudents() << endl;
 uni.newStudent();
 cout << "One student was admitted -> New Num_Students: " << uni.getNumStudents() << endl;

 return 0;
}

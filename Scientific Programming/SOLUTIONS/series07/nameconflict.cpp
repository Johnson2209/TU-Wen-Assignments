//Name conflicts & pointer this
#include <iostream>
#include <string>
using std::cout;
using std::string;

class Student {
private:
string lastname;
int student_id;
 public:
 Student() {
 cout << "Student generated\n";
 }
 Student(string lastname, int student_id) {
 this->lastname = lastname;
 this->student_id = student_id;
 cout << "Student (" << lastname << ", ";
 cout << student_id << ") registered\n";
 }
 };

 int main() {
 Student demo;
 Student var("Praetorius",12345678);
 return 0;
 }
// this gives a pointer to the current object
//this-> allows access to the member of the
//current object
//Name conflict in constructor (line 14)
//Input variable are called like class members
//Lines 14–16: Solution of the conflict via this->

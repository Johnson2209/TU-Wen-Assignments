//Constructor: An example
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
 Student(string name, int id) {
 lastname = name;
 student_id = id;
 cout << "Student (" << lastname << ", ";
 cout << student_id << ") registered\n";
 }
 };

 int main() {
 Student demo;
 Student var("Praetorius",12345678);
 return 0;
 }
// Constructors have no return values (lines 11+14)
//Name className(input)
//Standard constructor Student() without input
//(line 11)
// Output
//Student generated
//Student (Praetorius, 12345678) registered

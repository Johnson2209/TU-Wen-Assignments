#include<iostream>
#include<string>
using namespace std;

class University{
  string name;
  string city;
  int num_student;

public:
  string getName();
  string getCity();
  int get_num_Student();
  void setName();
  void setCity();
  void set_num_Student();
  void graduate();
  void newStudent();
};

string University::getName() {
   return name;
}

string University::getCity() {
   return city;
}

int University::get_num_Student() {
   return num_students;
}

void University::setName(string Univname) {
 name = Univname;
}

void University::setCity(string Univcity) {
  city = Univcity;
}

void University::set_num_Student(int num) {
  assert(num >= 0);
  num_students = num;
}

void University::graduate(){
  num_student=num_student--;
}

void University::newStudent(){
  num_student=num_student++;
}

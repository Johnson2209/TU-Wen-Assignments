#include<iostream>
#include<string>
using namespace std;
class University{
  string name;
  string city;
  int num_student;

public:
  void graduate();
  void newStudent();
};

void graduate(){
  num_student=num_student--;
}

void newStudent(){
  num_student=num_student++;
}

int main(){
  int n
  University student;
  cout<<"enter name of students of this University"endl;
  getline(cin,student.name)
}

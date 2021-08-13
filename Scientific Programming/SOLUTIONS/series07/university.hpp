#include <cmath>
#include <cassert>
#include <string>
using std::string;

class University {
  private:
    string name;
    string city;
    int num_students;

  public:
    string getName();
    string getCity();
    int getNumStudents();
    void setName(string);
    void setCity(string);
    void setNumStudents(int);
    void graduate();
    void newStudent();
};

string University::getName() {
   return name;
}

string University::getCity() {
   return city;
}

int University::getNumStudents() {
   return num_students;
}

void University::setName(string n) {
 name = n;
}

void University::setCity(string c) {
  city = c;
}

void University::setNumStudents(int num) {
  assert(num >= 0);
  num_students = num;
}

void University::graduate() {
  num_students--;
}

void University::newStudent() {
  num_students++;
}

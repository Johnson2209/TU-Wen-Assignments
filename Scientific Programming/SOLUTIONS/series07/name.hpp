#include <string>
using std::string;
using std::cout;
using std::endl;

class Name {
  private:
    string first_name;
    string surname;

  public:
    string getFirstName();
    string getSurName();
    void setFirstName(string);
    void setSurName(string);
    void setFullName(string);
    void printName();
};

string Name::getFirstName() {
   return first_name;
}

string Name::getSurName() {
   return surname;
}

void Name::setFirstName(string f) {
  first_name = f;
}

void Name::setSurName(string s) {
  surname = s;
}

void Name::setFullName(string fs) {
  int tmp = fs.find_last_of(' ');
  first_name = fs.substr(0,tmp);
  surname = fs.substr(tmp+1);
}

void Name::printName() {
  int i = 0;
  int n = 0;
  string fname;
  n = first_name.length();
  int tmp = first_name.find(' ');
  fname = first_name.substr(0, tmp);
  cout << fname << " ";
  for(i = tmp; i < n; i++){
    if (first_name[i] == ' '){
      cout << first_name[i+1] << ". ";
    }
  }
  cout << surname << endl;
}

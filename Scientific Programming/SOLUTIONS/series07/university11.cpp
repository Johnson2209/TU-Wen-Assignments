#include"university.hpp";

int main(){
  int n
  University univ;
  cout<<"enter name of university"endl;
  univ.getName();
  univ.setName();
  cout<<"enter city of university"endl;
  univ.getCity();
  univ.setCity();
  cout<<"enter number of students in university"endl;
  univ.get_num_Student();
  univ.set_num_Student();

 /*uni.setName("Afia");
 uni.setCity("Mainz");
 uni.setNumStudents(20);
 uni.graduate();*/
 cout << "One student graduated means we have an increase "<<endl;
 cout<<"new number of student in university is"<<univ.newStudent()<<endl;
 cout << "One student graduated means we have a decrease"<<endl;
 cout<<"new number of student in university is"<<univ.graduate()<<endl;
 return 0;
}

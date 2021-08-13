#include "upper.hpp"
#include "vector.cpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
  // construct different matrices
 //UpperTriangularMatrix upper1;
 UpperTriangularMatrix upper2(6,4);
 UpperTriangularMatrix upper3(4, 4);
 UpperTriangularMatrix upper4(upper2);

 //upper1 = upper3;

cout <<"Exercise 2; getting dimension of a matrix as well as its ijth component"<<endl;
 cout << "size of upper3 = " << upper3.size() << endl;
// cout << "size of upper1 = " << upper1.size() << endl;
 cout << "size of upper2 = " << upper2.size() << endl;
 cout << "size of upper4 = " << upper4.size() << endl;

 upper2(2,2) = 5;
 upper2(1,2) = 4;
 upper2(0,2) = 3;
 upper2(1,1) = 2;
 upper2(0,1) = 1;
 upper2(0,0) = 1;

cout <<"getting ijth component"<<endl;
 cout << "upper2(0,0) = " << upper2(0,0) << endl;
 cout << "upper2(0,1) = " << upper2(0,1) << endl;
 cout << "upper2(0,2) = " << upper2(0,2) << endl;
 cout << "upper2(1,2) = " << upper2(1,2) << endl;
 cout << "upper2(2,2) = " << upper2(2,2) << endl;
  cout << "upper2(1,0) = " << upper2(1,0) << endl;

cout <<"Exercise 3;printing matrix to the screen and finding norms"<<endl;

 cout << "upper 2 = " << upper2 << endl;
 cout << "upper 4 = " << upper4 << endl;

 cout << "||upper2||1 = " << upper2.columnSumNorm() << endl;
 cout << "||upper2||inf = " << upper2.rowSumNorm() << endl;

cout <<"Exercise 4; addition of two upper triangular  matrices"<<endl;
 cout << "upper2 + upper 4 = " << upper2+upper4 << endl;

 cout <<"Exercise 5; multiplication of two upper matrices"<<endl;
 cout << "upper2 * upper 4 = " << upper2*upper4 << endl;

cout <<"Exercise 6; matrix vector product"<<endl;
 Vector vec1(6,2);
 cout << "vec1 = " << vec1 << endl;
 cout << "upper2 * vec1 = " << upper2*vec1 << endl;

cout <<"Exercise 7; solution of linear systems"<<endl;
 Vector vec3(4,-2);
 Vector vec2 = upper3|vec3;
 cout << "upper3 | vec3 = " << vec2 << endl;
 return 0;
}

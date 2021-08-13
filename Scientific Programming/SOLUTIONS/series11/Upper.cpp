 #include "upper.hpp"
 #include <iostream>
 using std::cout;

UpperTriangularMatrix::UpperTriangularMatrix() {
 n = 0;
 u = (double*) 0;
  cout << "constructor, empty\n";
 }


 UpperTriangularMatrix::UpperTriangularMatrix(int n, double init) {
 assert(n >= 0);
 this->n = n;
 int s; // number of elements to be stored

 if (n == 0) {
 u = (double*) 0;
 }
 else {
int s;
    s = n*(n+1)/2;
    assert(u != (double*) 0);
 u = new double[s];
 for (int j=0; j<s; ++j) {
 u[j] = init;
    }
  }
  cout << "constructor, length " << n << "\n";
 }

 UpperTriangularMatrix::UpperTriangularMatrix(const UpperTriangularMatrix& rhs) {
 n = rhs.n;
 int s; // number of elements to be copied
 if (n == 0) {
  u = (double*) 0;
  }
 else {
      s = n*(n+1)/2;
   assert(u != (double*) 0);
 u = new double[s];
 for (int j=0; j<s; ++j) {
 u[j] = rhs.u[j];
    }
  }
  cout << "copy constructor, length " << n << "\n";
  }

 UpperTriangularMatrix::~UpperTriangularMatrix() {
 if (n > 0) {
 delete[] u;
 }
 cout << "free vector, length " << n << "\n";
 }


 UpperTriangularMatrix& UpperTriangularMatrix::operator=(const UpperTriangularMatrix& rhs) {
 if (this != &rhs) {
 if (n != rhs.n) {
 if (n > 0) {
 delete[] u;
 }
 n = rhs.n;
 if (n > 0) {
  int s;
   s = n*(n+1)/2;
 u = new double[s];
 }
 else {
u = (double*) 0;
 }
 }
 for (int j=0; j<n; ++j) {
 u[j] = rhs.u[j];
 }
 }
 cout << "deep copy, length " << n << "\n";
 return *this;
 }

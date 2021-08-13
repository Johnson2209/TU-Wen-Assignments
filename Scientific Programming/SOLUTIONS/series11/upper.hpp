#ifndef _UPPER_
#define _UPPER_
#include <cmath>
#include <cassert>

//The class UpperTriangularMatrix stores upper triangular matrix of dimension n

  class UpperTriangularMatrix {

  private:
  // dimension of the Matrix
  int n;
  // dynamic coefficient vector
  double* u;

  public:

  // constructors and destructor
  //UpperTriangularMatrix();
  UpperTriangularMatrix(int n=0, double init = 0);
  ~UpperTriangularMatrix();
  UpperTriangularMatrix(const UpperTriangularMatrix&);//copy constructor
  UpperTriangularMatrix& operator=(const UpperTriangularMatrix&);//assignment constructor

  //expansion of class

  // mutator functions
   int size() const;
 // read and write entries
   const double& operator()(int j, int k) const;
   double& operator() (int j, int k);

  // print and norms
    double columnSumNorm() const;
    double rowSumNorm() const;
};

 std::ostream& operator<<(std::ostream& output, const UpperTriangularMatrix& mat);

 // addition of upper triangular matricess
 const UpperTriangularMatrix operator+(const UpperTriangularMatrix&, const UpperTriangularMatrix&);
 // multiplication of upper triangular matrices
 const UpperTriangularMatrix operator*(const UpperTriangularMatrix&, const UpperTriangularMatrix&);
 const Vector operator*(const UpperTriangularMatrix&, const Vector&);
 // multiplication of upper triangular matrices
 const Vector operator|(const UpperTriangularMatrix&, const Vector&);
#endif

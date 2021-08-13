#ifndef _UPPER_
#define _UPPER_

#include <cmath>
#include <cassert>
#include <iostream>
#include "vector.hpp"

// This class stores upper triangular matrices of dimension n

 class UpperTriangularMatrix {
   private:
   // dimension of the upper triangular matrix
      int n;
   // dynamic coefficient upper triangular matrix
      double* u;

   public:

     //UpperTriangularMatrix();//standard constructor
     UpperTriangularMatrix(int n , double init = 0); // constructor
      ~UpperTriangularMatrix();//destructor
     UpperTriangularMatrix(const UpperTriangularMatrix& rhs); // copy constructor
     UpperTriangularMatrix& operator=(const UpperTriangularMatrix& rhs); //assignment operator


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

 // addition of upper triangular matrices
 const UpperTriangularMatrix operator+(const UpperTriangularMatrix&, const UpperTriangularMatrix&);

 // multiplication of upper triangular matrices
 const UpperTriangularMatrix operator*(const UpperTriangularMatrix&, const UpperTriangularMatrix&);
 const Vector operator*(const UpperTriangularMatrix&, const Vector&);

 // multiplication of upper triangular matrices
  const Vector operator|(const UpperTriangularMatrix&, const Vector&);
#endif

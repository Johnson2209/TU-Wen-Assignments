//matrix first.hpp
#ifndef _MATRIX_FIRST_
#define _MATRIX_FIRST_

#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>

// The class Matrix stores n x n matrix
class Vector {
private:
// dimension of the vector
int dim;
// dynamic coefficient vector
double* coeff;

public:
// constructors and destructor
Vector();
Vector(int dim, double init = 0);
~Vector();

// return vector dimension
int size();

// read and write vector coefficients
void set(int k, double value);
double get(int k);

// compute Euclidean norm
double norm();
};
 class Matrix {
 private:
   //nesting of class vector
   Vector vector1
 // column and row dimension of the Matrix
 int n;
 // dynamic coefficient vector
 double* coeff;
 type char;

 public:
 // constructors and destructor
 Matrix();
 Matrix(int dim1, int dim2, double init = 0);
 ~Matrix();
 };



 #endif

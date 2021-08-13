//vector first.hpp
#ifndef _VECTOR_FIRST_
#define _VECTOR_FIRST_

#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>

// The class Vector stores vectors in Rd

 class Vector {
 private:
 // dimension of the vector
 int dim, dim_1,dim_2;
 // dynamic coefficient vector
 double* coeff, coeff_1, coeff_2;

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

 #endif

//matrix first.hpp
#ifndef _MATRIX_FIRST_
#define _MATRIX_FIRST_

#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>


 class Matrix {
 private:
 // column and row dimension of the Matrix
 int dim;
 // dynamic coefficient vector
 double* coeff;
 char type;



 public:
 // constructors and destructor
 Matrix();
 Matrix(int dim, char type, double init = 0);
 ~Matrix();
//read and write matrix coefficients
 void set(int row, int column, double value);
 double get(int row, int column, char type);

//get matrix size
 int size();

 //get Euclidean norm of matrix
 double norm();
 };

 #endif

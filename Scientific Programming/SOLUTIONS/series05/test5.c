#ifndef _DYNAMICVECTORS_
#define _DYNAMICVECTORS_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// allocate + initialize dynamic double vector of length n
double* mallocVector(int n);

// free a dynamic vector and set the pointer to NULL
double* freeVector(double* vector);

// extend dynamic double vector and initialize new entries
double* reallocVector(double* vector, int n, int nnew);

// allocate dynamic double vector of length n and read
// entries from keyboard
double* scanVector(int n);

 // print dynamic double vector of length n to shell
void printVector(double* vector, int n);

 #endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double* scanVector(int length) {
int j = 0;
double* vector = NULL;
assert(length > 0);

vector = malloc(length*sizeof(double));
assert(vector != NULL);
for (j=0; j<length; ++j) {
vector[j] = 0;
printf("vector[%d] = ",j);
scanf("%lf",&vector[j]);
 }
 return vector;
}

void printVector(double* vector, int length) {
int j = 0;
assert(vector != NULL);
assert(length > 0);

for (j=0; j<length; ++j) {
printf("vector[%d] = %f\n",j,vector[j]);
  }
 }

 main() {
 double* x = NULL;
 int dim = 0;

 printf("dim = ");
 scanf("%d",&dim);

 x = scanVector(dim);
 printVector(x,dim);

 free(x);
 x = NULL;
 }

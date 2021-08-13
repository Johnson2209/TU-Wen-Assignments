include "dynamicvectors.h"

double* mallocVector(int n) {
int j = 0;
double* vector = NULL;
assert(n > 0);

vector = malloc(n*sizeof(double));
assert(vector != NULL);

for (j=0; j<n; ++j) {
vector[j] = 0;
 }
return vector;
 }

double* freeVector(double* vector) {
free(vector);
return NULL;
}

double* reallocVector(double* vector, int n, int nnew) {
int j = 0;
assert(vector != NULL);
assert(n > 0);
assert(nnew > 0);

vector = realloc(vector,nnew*sizeof(double));
assert(vector != NULL);
for (j=n; j<nnew; ++j) {
vector[j] = 0;
}
return vector;
}

double* scanVector(int n) {
int j = 0;
double* vector = NULL;
assert(n > 0);

vector = mallocVector(n);
assert(vector != NULL);

 for (j=0; j<n; ++j) {
 printf("vector[%d] = ",j);
 scanf("%lf",&vector[j]);
 }
 return vector;
 }

 void printVector(double* vector, int n) {
 int j = 0;
 assert(vector != NULL);
 assert(n > 0);

 for (j=0; j<n; ++j) {
printf("%d: %f\n",j,vector[j]);
 }
}

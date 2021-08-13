#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DIM 5

int m = 1;
int n = m+1;
int j = 0;

int* array = malloc(m*sizeof(int));
assert(array != NULL);
for (j=0; j<DIM-1; ++j){
array[j] = 0;
printf("%d: ",j);
scanf("%lf",&array[j]);
 }

array = realloc(array,n*sizeof(int));
assert(array != NULL);
for (j=m; j<n; ++j){
array[j] = array[m];
 }

for (j=0; j<m; ++j){
printf("%d ",array[j]);
}
printf("\n");
free(array);
array = NULL;
void scanVector(double input[], int dim) {
 int j = 0;
 for (j=0; j<dim; j=j+1) {

  }
 }

 void printVector(double output[], int dim) {
 int j = 0;
  printf("sorted vecctor: \n");
 for (j=0; j<dim; j=j+1) {
     printf("%f\n",output[j]);
    }
  printf("\n");
 }

 void insertSort(double vector[], int dim) {
 int j, k, argmin;
 double tmp;
 for (j=0; j<dim-1; j=j+1) {
 argmin = j;
 for (k=j+1; k<dim; k=k+1) {
 if (vector[argmin] > vector[k]) {
 argmin = k;
  }
 }
  if (argmin > j) {
  tmp = vector[argmin];
  vector[argmin] = vector[j];
 vector[j] = tmp;
    }
  }
}

 int main() {
 double x[DIM];
  for(m=1;DIM+1;++m){
 scanVector(x,DIM);
 insertSort(x,DIM);
 printVector(x, DIM);
}
}

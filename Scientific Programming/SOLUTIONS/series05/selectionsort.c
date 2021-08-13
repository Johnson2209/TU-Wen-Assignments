#include <stdio.h>
#define DIM 5

void scanVector(double input[], int dim) {
 int j = 0;
 for (j=0; j<dim; j=j+1) {
 input[j] = 0;
 printf("%d: ",j);
 scanf("%lf",&input[j]);
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

 void selectionSort(double vector[], int dim) {
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
 scanVector(x,DIM);
 selectionSort(x,DIM);
 printVector(x, DIM);
}

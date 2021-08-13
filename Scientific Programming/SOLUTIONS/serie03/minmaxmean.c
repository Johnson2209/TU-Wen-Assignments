#include <stdio.h>
#define DIM 3

void minmaxmean(double input[], int dim) {
  int j = 0;
  double total = 0;
  double min_val = input[0];
  double max_val = input[0];
  for (j=1; j<dim; j=j+1) {
    total += input[j];

    if (input[j]<min_val) {
      min_val = input[j];
    }
    if (input[j] > max_val) {
      max_val = input[j];
    }
  }
  printf("The mean value is %.2f\n",total/dim);
  printf("The minimum value is %.2f\n",min_val);
  printf("The maximum value is %.2f\n",max_val);
}


void scanVector(double input[], int dim) {
  int j = 0;
  for (j=0; j<dim; j=j+1) {
  input[j] = 0;
  printf("x_%d: ",j+1);
  scanf("%lf",&input[j]);
  }
}


int main() {
  double x[DIM];
  scanVector(x,DIM);
  minmaxmean(x, DIM);

}

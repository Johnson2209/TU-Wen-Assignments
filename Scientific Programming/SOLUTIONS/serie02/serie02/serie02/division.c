#include <stdio.h>
#include <math.h>

double division (double m, double n) {
  if (m < 0 || n <= 0) {
    return 0;
  }

  if (m < n) {
    return 0;
  }
  else {
    return 1 + division(m-n,n);
  }
}

int main() {
  double m;
  double n;

  printf("This program computes m/n \n");
  printf("m = ");
  scanf("%lf",&m);
  printf("n = ");
  scanf("%lf",&n);

  double res = division(m,n);
  printf("%.0f/%.0f = %.0f\n",m,n,res);
}

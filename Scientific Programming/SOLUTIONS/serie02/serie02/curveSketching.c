#include <stdio.h>
#include <math.h>


void curveSketching (double a, double b, double c) {
  if (c == 0) {
    printf("Straight line\n");
    printf("x-intercept = %f\n",-a/b);
    printf("y-intercept = %f\n",a);
  }
  else {
    printf("Parabola\n");
    double alm_for = (-b + mathsqrt(b*b - 4*a*c))/(2*a);
    printf("x-intercept = %f\n",alm_for);
    printf("y-intercept = %f\n",a);
  }

  if (c != 0) {
    double ext = -b/(2*c);
    printf("The extrema point is %f ",ext );

    if (2*c > 0) {
      printf("and its the Minimum\n");
    }
    else {
      printf("and its the Maximum\n");
    }
  }
  else {
      printf("An extrema point is doesn't exist\n");
  }

}

int main() {
  double a;
  double b;
  double c;
  printf("Enter the coefficients of the polynomial f(x) = a + bx + cx2\n");
  printf("a = ");
  scanf("%lf",&a);
  printf("b = ");
  scanf("%lf",&b);
  printf("c = ");
  scanf("%lf",&c);
  curveSketching(a,b,c);
}

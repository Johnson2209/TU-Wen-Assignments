#include <stdio.h>

double pi = 3.142;

double radian (double theta) {
  double red_theta = theta /*% 360*/;
  return (red_theta /* * pi */ )/180;
}

int main() {
  double t;
  printf("Enter an angle in deg: ");
  scanf("%lf",&t);
  printf("The angle is radians is : %.0f pi radians\n", radian(t) );
}

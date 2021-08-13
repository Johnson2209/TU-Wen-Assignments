#include <stdio.h>

void points (double x, double y, double u, double v, double a, double b) {
  double m1 = (y-v)/(x-u);
  double m2 = (y-b)/(x-a);
  if (m1-m2 < 1e-3) {
    printf(">>Points lie on the same line\n");
  }
  else {
    printf(">> Points don't lie on the same line\n");
  }
}

int main() {
  double x;
  double y;
  double u;
  double v;
  double a;
  double b;
  printf("Enter the points (x,y), (u,v) and (a,b)\n");
  printf("x = ");
  scanf("%lf",&x);
  printf("y = ");
  scanf("%lf",&y);
  printf("u = ");
  scanf("%lf",&u);
  printf("v = ");
  scanf("%lf",&v);
  printf("a = ");
  scanf("%lf",&a);
  printf("b = ");
  scanf("%lf",&b);
  points(x,y,u,v,a,b);
}

#include <stdio.h>

void quadrant (double x, double y) {
  if (x == 0 || y == 0) {
      printf("Point lies on the co-ordinate axis\n");
  }
  else {
    if (x > 0 && y > 0) {
      printf("Point is in Quadrant 1\n");
    }
  else if (x < 0 && y > 0) {
      printf("Point is in Quadrant 2\n");
    }
  else if (x < 0 && y < 0) {
      printf("Point is in Quadrant 3\n");
    }
  else {
      printf("Point is in Quadrant 4\n");
    }
  }
}

int main() {
  double x;
  double y;

  printf("Enter the points (x,y)\n");
  printf("x = ");
  scanf("%lf",&x);
  printf("y = ");
  scanf("%lf",&y);

  quadrant(x,y);
}

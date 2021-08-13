#include <stdio.h>
#define DIM 3

double scalarProduct(double [], double [], int);
void vectorProduct(double [], double [], double [], int);

int main() {
  double u[DIM];
  double v[DIM];
  double dot;
  double w[DIM];
  printf("Enter first vector: u = (x,y,z)\n");
  printf(">> x = ");
  scanf("%lf",&u[0]);
  printf(">> y = ");
  scanf("%lf",&u[1]);
  printf(">> z = ");
  scanf("%lf",&u[2]);
  printf("Enter second vector: v = (a,b,c)\n");
  printf(">> a = ");
  scanf("%lf",&v[0]);
  printf(">> b = ");
  scanf("%lf",&v[1]);
  printf(">> c = ");
  scanf("%lf",&v[2]);

  dot = scalarProduct(u, v, DIM);
  printf("u . v = %.2f \n", dot);

  vectorProduct(u, v, w, DIM);
}

double scalarProduct(double u[], double v[], int dim) {
  int i = 0;
  int w = 0;
  for (i = 0; i < dim; i += 1) {
    w += u[i]*v[i];
  }
  return w;
}

void vectorProduct(double u[], double v[], double w[], int dim) {
  w[0] = u[1]*v[2] - u[2]*v[1];
  w[1] = u[2]*v[0] - u[0]*v[2];
  w[2] = u[0]*v[1] - u[1]*v[0];

  printf("u x v = (%.2f,%.2f,%.2f)\n", w[0],w[1],w[2]);
}

#include <stdio.h>
#define DIM 3
#define DIMs 2

int lines(double u[], double v[], double s[]) {
    double m1 = -u[0]/u[1];
    double m2 = -v[0]/v[1];
    double c1 = u[2]/u[1];
    double c2 = v[2]/v[1];
    if ((m1 == m2) && (c1 == c2)) {
      return 0;
    }
    else if (m1 == m2) {
      return 1;
    }
    else {
      s[0] = (u[2]*v[1] - v[2] * u[1])/(u[0]*v[1] - v[0] * u[1]);
      s[1] = (u[2])/(u[1]) - ((u[0])/(u[1])*s[0]);
      return -1;
    }


}


void scanVector(double input[], int dim) {
  int j = 0;
  for (j=0; j<dim; j=j+1) {
  input[j] = 0;
  printf("%d: ",j);
  scanf("%lf",&input[j]);
  }
}


int main() {
  double u[DIM];
  double v[DIM];
  double s[DIMs];

  printf("Enter vector u = (a,b,c)\n");
  scanVector(u,DIM);
  printf("Enter vector v = (d,e,f)\n");
  scanVector(v,DIM);

  int result = lines(u,v,s);

  if (result == 0) {
    printf("Coincident\n");
  }
  else if (result == 1) {
    printf("Parallel\n");
  }
  else {
    printf("Intersecting\n");
  }

}

#include <stdio.h>
#include <math.h>

double partialSum_v1(int n) {
  if (n == 0) {
    return 4;
  }
  else {
    return (4 * pow(-1,n)) / (2*n + 1) + partialSum_v1(n-1);
  }
}

double partialSum_v2(int n) {
  int k = 0;
  double Sn = 0;

  for (k=0; k<=n; k=k+1) {
    Sn += (4 * pow(-1,k)) / (2*k + 1);
  }
  return Sn;
}


int main() {
  int n;
  printf("Enter n: ");
  scanf("%d", &n);
  printf("pi is approximately %f by version 1 and %f by version 2\n",partialSum_v1(n),partialSum_v2(n) );

}

#include <stdio.h>
#include <math.h>

int binomial (int n, int k) {
  if (k == 0 || k == n) {
    return 1;
  }
  else {
    return binomial(n-1,k) + binomial(n-1,k-1);
  }
}

int main() {
  int n;
  int k;

  printf("This will compute binom(n,k)\n");
  printf("n = ");
  scanf("%d",&n);
  printf("k = ");
  scanf("%d",&k);

  int res = binomial(n,k);
  printf("binom(%d,%d) = %d \n",n,k,res);
}

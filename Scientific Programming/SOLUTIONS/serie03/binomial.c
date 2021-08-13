#include <stdio.h>

int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  else {
    return n * factorial(n-1);
  }
}

int binomial (int n, int k, int type) {
  if (type == 1) {
    return (factorial(n))/(factorial(k)*factorial(n-k));
  }
  else if (type == 2) {
      int num = 1;
      int den = 1;
      int i;
      int j;
      for (i=n; i>n-k; i-=1) {
        num *= i;
      }
      for (j=k; j>=1; j-=1) {
        den *= j;
      }
      return num/den;
  }
    else if (type == 3) {
      if (k == 0 || k == n) {
        return 1;
      }
      else {
        return binomial(n-1,k,3) + binomial(n-1,k-1,3);
      }
  }
    else {
      printf("type must be in {1,2,3}\n");
      return 0;
    }
}

int main() {
  int n;
  int k;
  int type;

  printf("This will compute binom(n,k,type)\n");
  printf("n = ");
  scanf("%d",&n);
  printf("k = ");
  scanf("%d",&k);
  printf("type = ");
  scanf("%d",&type);

  printf("binom(%d,%d,%d) = %d \n",n,k,type,binomial(n,k,type));
}

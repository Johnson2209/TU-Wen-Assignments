#include <stdio.h>

int fibonacci (int n) {
  int i;
  int x[n];
  x[0] = 0;
  x[1] = 1;
  for (i=2; i<n; i+=1) {
    x[i] = x[i-1] + x[i-2];
  }
  return x[n-1];
}

int main() {
  int n;
  printf("This computes fib(n)\n");
  printf("n = ");
  scanf("%d",&n);

  printf("fib(%d) = %d \n",n,fibonacci(n));
}

#include <stdio.h>
#include <math.h>

int fibonacci (int n) {
  if (n == 0) {
    return 0;
  }
  else if (n == 1) {
    return 1;
  }
  else {
    return fibonacci(n-1) + fibonacci (n-2);
  }
}

int main() {
  int n;
  printf("This computes fib(n)\n");
  printf("n = ");
  scanf("%d",&n);

  int res = fibonacci(n);
  printf("fib(%d) = %d \n",n,res);
}

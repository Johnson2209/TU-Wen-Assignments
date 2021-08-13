#include <stdio.h>

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
  int row;
  int col;
  printf("Enter number n: ");
  scanf("%d",&n);

  printf("Pascal's Triangle for n = %d\n",n);
  for (row=0; row<=n; row+=1) {
    for (col=0; col<=row; col += 1) {
      printf("%d ",binomial(row, col));
    }
    printf("\n");
  }
}

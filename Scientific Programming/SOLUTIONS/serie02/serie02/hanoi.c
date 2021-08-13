#include <stdio.h>
#include <math.h>

double hanoi (int m, int i, int j) {
  if (m == 0) {
    return 0;
  }
  else {
    printf("Move a disk from rod %d to rod k\n",i);
    printf("Move a disk from rod %d to rod %d\n",i,j);
    printf("Move a disk from rod k to rod %d\n",j);

    hanoi(m-1,i,j);
  }
}

int main() {
  double m;
  double i;
  double j;

  printf("m = ");
  scanf("%lf",&m);
  printf("i = ");
  scanf("%lf",&i);
  printf("j = ");
  scanf("%lf",&j);

  hanoi(m,i,j);
}

#include <stdio.h>
#define DIM_1 10
#define DIM_2 3

int check(int x[], int y[]) {
  int i;
  int flag = -1;

  for (i=0; i<DIM_1-2; i+=1) {
    if ((y[0] == x[i]) && (y[1] == x[i+1]) && (y[2] == x[i+2])) {
      flag = 1;
    }
  }
  return flag;


}


void scanVector(int input[], int dim) {
  int j = 0;
  for (j=0; j<dim; j=j+1) {
  input[j] = 0;
  printf("%d: ",j+1);
  scanf("%d",&input[j]);
  }
}


int main() {
  int x[DIM_1];
  int y[DIM_2];
  printf("Enter vector x:\n");
  scanVector(x,DIM_1);
  printf("Enter vector y:\n");
  scanVector(y,DIM_2);

  int result = check(x,y);

  if (result == 1) {
    printf("Combination y is found in vector x\n");
  }
  else {
    printf("Combination y is not found in vector x\n");
  }



}

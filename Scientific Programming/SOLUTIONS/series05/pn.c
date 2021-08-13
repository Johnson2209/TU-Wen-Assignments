#include<stdio.h>

void test(x int){
  printf("(a) x=%d",x);
  x=43;
  printf("(b) x=%d",x);
}


main(){
  int x;
  printf("(c) x=%d", x);
  test(x);
  printf("(d)=%d",x);
}

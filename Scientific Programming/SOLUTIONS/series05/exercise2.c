/*call by reference is realized using pointer*/
/*why use call by reference?*/
/*programming is C usually access values of data using call by value*/
/*at most only one value could be returned via call by value*/
/*if we need to return more than one value of data, we use call by reference*/
/*call by reference is pretty cool in dealing with vectors*/
/*arrays are always passed to functions via call by reference!*/
#include<stdio.h>

void test(int *y){
  printf("(a) *y=%d\n", *y);
  *y=43;
  printf("(b) *y=%d\n", *y);

}
int main(){
  int x=5;
  printf("(c) x=%d\n", x)
  test(x);
  printf("(d) x=%d\n",x);
}

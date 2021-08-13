#include <stdio.h>

int main(){
  double L;
  double x;
  double y;
  printf("length of square L=\n");
  scanf("%lf", &L);

  if (L<=0){
    printf("impossible");
  }
  else{
    printf("point in the R2 plane is (x,y)\n");
    printf("x=\n");
    scanf("%lf", &x);
    printf("y=\n");
    scanf("%lf", &y);
    if(L>0 && 0<x && x<L && 0<y && y<L){
    printf("(x,y) is a point inside the square of length L\n");
  }
  else{
    if( L>0 &&( (0<=y && y<=L && 0==x) || (0==y && 0<=x && x<=L ) ||(0<=y && y<=L &&L==x) ||( L==y&& 0<=x && x<=L) )){
      printf("(x,y) is a point on the boundary of the square of length L\n");
          }
          else{
            printf("(x,y) is a point outside of the square of length L\n");
          }
  }
  }
}

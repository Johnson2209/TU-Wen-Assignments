#include <stdio.h>

int main(){
  double x;
  double y;
  int n;

   printf("prize won in Euros: x=");
  scanf("%lf",&x);

  printf("the number of my friends: n=");
  scanf("%ld",&n);
  if(x<=0){
    printf("we're not dealing with debt here! Enter a positive amount\n");
  }
  else{
    y=x/(n+1);
printf("each person gets %.2f\n",y);
}
}

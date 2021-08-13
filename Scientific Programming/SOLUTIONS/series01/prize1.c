#include <stdio.h>

int main(int argc, char const *argv[]) {
  double x;
  double y;
  int n;
  printf("amount of money won=");
  scanf("%lf",&x);
  printf("number of friends =");
  scanf("%d", &n);
  if (x<=0){
    printf("we're not dealing with debt here! Enter a positive amount\n");
  }
  else{
    y=x/(n+1);
    printf("each person earns %.2f euro\n",y);
  }
  return 0;
}

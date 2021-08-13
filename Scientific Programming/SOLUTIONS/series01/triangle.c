#include <stdio>

int main(){
  double a;
  double b;
  double c;
  printf("input the three lenghts of the trianglr\n");
  printf("input a=");
  scanf("%lf",&a);
  printf("input b");
  scanf("%lf",&b);
  printf("input c=" );
  scanf("%lf",&c);
  if(a==b && b==c){
    printf("triangle is equilateral");
  }
  if(a==b||b==c||c==a){
    printf("triangle is isosceles");
  }
  else{
    if((a*a+ b*b==c*c|| c*c +b*b==a*a|| c*c+a*a==b*b)&&(a==b||b==c||c==a)){
      printf("triangle is both isosceles and right angle");
    }
  }
  if(a!=b&&b!=c&&c!=a){
    printf("triangle is scalene" );
  }
  else{
    if((a!=b&&b!=c&&c!=a)&&(a*a+ b*b==c*c|| c*c +b*b==a*a|| c*c+a*a==b*b)){
      printf("triangle is both scalene and right angle" );
    }
      }
      if(a+b==c||b+c==a||c+a==b){
        printf("one-dimensional degenerate triangle");
              }
        if(a+b<c||b+c<a||c+a<b){
          printf("impossible");
        }
}

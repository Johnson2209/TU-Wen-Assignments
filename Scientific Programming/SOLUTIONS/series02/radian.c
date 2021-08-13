#include <stdio.h>
double rad(double theta,  double pi){
    return (double) (theta*pi)/180 ;
}

main() {
 double theta=0;
 double pi=3.14;
 printf("input theta=");
 scanf("%lf", &theta);
 printf("angle in radian= %f\n", rad(theta,pi) );
  }

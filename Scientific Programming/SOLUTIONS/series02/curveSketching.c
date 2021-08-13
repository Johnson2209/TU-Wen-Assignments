#include <stdio.h>
#include <math.h>

void curveSketching(double a, double b, double c) {

}
main(){
  double a;
  double b;
  double c;
    double x1;

  double x2;
  double curveSketching(double a, double b, double c)= a +b*x +c*(x**2);
  printf("equation of curve is 'a +b*x +c*(x**2'");
  printf("input the values of coefficients a, b, and c");
  scanf("%f",&a);
  scanf("%f",&b);
  scanf("%f",&c);
  if(c=0){
    printf("the function describes a straight line");
    print("the intersection of the curve with the y-axis=%lf\n",a);
    printf( "the intercept of  the curve with the x-axis= %g\n",x1);
    }
  else{
    if(c!=0){
      printf("the curve describes a parabola");
      print("the intersection of the curve with the y-axis=%lf\n",a);
      printf( "the first intercept of  the curve with the x-axis= %g\n",x1);
      printf( "the second intercept of  the curve with the x-axis= %g\n",x2) ;
    }
  }

}

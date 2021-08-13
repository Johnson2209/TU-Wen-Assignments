#include <stdio.h>
int main(){
double radius;
double pi;
double area_of_circle = pi*(radius*radius);
double perimeter_of_circle =2*pi*radius;
printf("value of pi=");
scanf("%lf",&pi);
printf("value of radius");
scanf("%lf",&radius);
area_of_circle = pi*(radius*radius);
perimeter_of_circle =2*pi*radius;
printf("radius of circle %f\n", radius);
printf("area of circle %f\n",area_of_circle);
printf("perimeter of circle %f\n", perimeter_of_circle);
}

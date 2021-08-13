#include <stdio.h>

main(){
  int a;
  int b;
  int c;
  printf("length1=");
  scanf("%d",&a);
  printf("length2=");
  scanf("%d",&b);
  printf("length3=");
  scanf("%d",&c);
    if( (b*b + a*a==c*c && c>a &&c>b) || (c*c + b*b==a*a && a>c &&a>b) || (c*c + a*a==b*b && b>a &&b>c) ){
    printf("the three numbers are a Pythagorean triple\n");
  }

          	else{
          		    	printf("the three numbers are not a Pythagorean triple\n");
  		}

}

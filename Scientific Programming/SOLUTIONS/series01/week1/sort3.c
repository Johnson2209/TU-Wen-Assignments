#include <stdio.h>

int main(){
  double x;
  double y;
  double z;
  double tmp1;
  double tmp2;
  printf("unsorted 3 real numbers:\n");
  printf("x=\n");
  scanf("%lf",&x);
  printf("y=\n");
  scanf("%lf",&y);
  printf("z=\n");
  scanf("%lf",&z);
  if(x<y  && y<z){
    tmp1=x;
    x=z;
    z=tmp1;
          y=y;
          printf("output sorted in descending order\n");
          printf("%f\n",x);
          printf("%f\n",y);
          printf("%f\n",z);
        }
        else{
          if(y<x  && x<z){
          tmp1=y;
          y=z;
          z=tmp1;
                x=x;
                printf("output sorted in descending order\n");
                printf("%f\n",y);
                printf("%f\n",x);
                printf("%f\n",z);
      }
      else{
        if(z<x  && x<y){
        tmp1=z;
        z=y;
        y=tmp1;
              x=x;
              printf("output sorted in descending order\n");
              printf("%f\n",z);
              printf("%f\n",x);
              printf("%f\n",y);
            }
            else{
            if(x<z  && z<y){
              tmp1=x;
              x=y;
              y=tmp1;
                    z=z;
                    printf("output sorted in descending order\n");
                    printf("%f\n",x);
                    printf("%f\n",z);
                    printf("%f\n",y);
                  }
                    else{
                      if(y<z  && z<x){
                      tmp1=y;
                      y=x;
                      x=tmp1;
                            z=z;
                            printf("output sorted in descending order\n");
                            printf("%f\n",y);
                            printf("%f\n",z);
                            printf("%f\n",x);
                  }
                  else{
                    if(z<y  && y<x){
                              printf("output sorted in descending order\n");
                          printf("%f\n",x);
                          printf("%f\n",y);
                          printf("%f\n",z);
                        }
}

        }

}
  }

}
}

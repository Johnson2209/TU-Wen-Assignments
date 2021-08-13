//DIFFERENCE BETWEEN VARIABLES AND POINTERS
//Definition
/*Variable = Symbolic name (identifier) of a
storage location (memory address) containing
some quantity of information (value) of a
specific type (data type)

 Pointer = Variable containing the address
of a storage location, usually some numbers*/

//Representation
/*if var is a variable, then &var is a pointer" and
"if ptr is a pointer, then *ptr is a variable"*/

//Usage of pointers
/*call by reference is realized using pointer*/
/*why use call by reference?*/
/*at most only one value could be returned via call by value*/
/*if we need to return more than one value of data, we use call by reference*/
/*call by reference is pretty cool in dealing with vectors*/

/*the following code defines a function which swap the contents of two
 variables x and y*/

#include<stdio.h>
void scanvec(double input[], int dim){
  int j=0;
  for(j=0;j<1; j=j+1){
    input[j]=0;
    printf("=%d\n",j);
    scanf("%lf\n", &input[j]);
    /*pointer is used here to access variable inputs*/
  }
}

void swap(double output[], int dim){
  int j=0;
  for(j=1; j>=0; j=j-1){
    printf("%f\n", output[j]);
  }
  printf("\n");
}

int main(){
  double x[2];
  scanvec(x,2);
  swap(x,2);
}

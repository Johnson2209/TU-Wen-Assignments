#include <stdio.h>
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
void swap(double*, double*);

int main(){
    double x, y;
    printf("Enter two number: ");
    scanf("%lf", &x);
    scanf("%lf", &y);

    printf("Before swapping: [%lf, %lf]\n", x, y);
    swap(&x, &y);
    printf("After swapping: [%lf, %lf]", x, y);
}

void swap2(double* x, double* y){
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void swap(double *x, double *y)
{
double tmp;
tmp = *x;
*x = *y;
*y = tmp;
}

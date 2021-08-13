#include <stdio.h>

void printSizeOf(double vector[]) {
printf("sizeof(vector) = %d\n",sizeof(vector));
 }

int main() {
 int var = 456;
 double array[12];
 double* ptr = array;

printf("sizeof(var) = %d\n",sizeof(var));
 printf("sizeof(double) = %d\n",sizeof(double));
 printf("sizeof(array) = %d\n",sizeof(array));
 printf("sizeof(ptr) = %d\n",sizeof(ptr));
 printSizeOf(array);
 }

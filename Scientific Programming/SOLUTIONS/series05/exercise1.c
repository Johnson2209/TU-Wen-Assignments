#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
int N = 5;
int Nnew = 10;
int j = 0;

int* array = malloc(N*sizeof(int));
assert(array != NULL);
for (j=0; j<N; ++j){
array[j] = j;
 }

array = realloc(array,Nnew*sizeof(int));
assert(array != NULL);
for (j=N; j<Nnew; ++j){
array[j] = 10*j;
 }

for (j=0; j<Nnew; ++j){
printf("%d ",array[j]);
}
printf("\n");
free(array);
array = NULL;
 }

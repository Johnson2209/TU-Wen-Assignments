#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int checkOccurence(char* string, char character) {
  int length = strlen(string);
  int i;
  int cnt=0;
  for (i=0;i<length;++i) {
    if (string[i] == character){ //(strcmp(string[i],character)) {
      cnt++;
    }
  }
  //cnt++ = malloc((length+1)*sizeof(char));
  return cnt;
}

int main() {
  char* s;
  char b;
  printf("Enter string to search (s) : ");
  scanf("%s",&s);
  printf("Enter character (b) : ");
  scanf("%s",&b);
  printf("%s occurs in %s %d times\n", b, s, checkOccurence(s,b));
}

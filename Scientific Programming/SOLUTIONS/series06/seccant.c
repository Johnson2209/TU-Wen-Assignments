 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <assert.h>

char* stringCopy(char* source) {
int length = 0;
char* result = NULL;
assert(source != NULL);

length = strlen(source);
result = malloc((length+1)*sizeof(char));
strcpy(result,source);
return result;
}

main() {
char* string1 = "Hello World?";
char* string2 = stringCopy(string1);
string2[11] = ’!’;
printf("%s %s\n",string1,string2);
 }
/* Output:
Hello World? Hello World!
I Declaration and initialization of strings with double
quotation marks "..." creates a static string
with null character at the end (line 18)
I Access to single characters of a string with
single quotation marks ‘...’ (line 20)
I Placeholder for strings in printf is %s (line 21)
*/

#include <iostream>
#include <string>
#include <cstdio>
using std::cout;
using std::cin;
using std::endl;
using std::string;

bool isPalindrome(string word) {
  int i,j,n;
  n = word.length();
  for (i=0, j=n-1;i<n&&j>=0;i++,j--) {
      if (word[i] != word[j]) return false;
  }
  return true;
}

int main() {
 string str3;
 cout << "Enter a word: ";
 cin >> str3;
 if (isPalindrome(str3)) {
   cout << "The word entered is a palindrome\n";
 }
 else {
   cout << "The word is not a palindrome" << endl;
 }
 return 0;
}

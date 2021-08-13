#include <iostream>
#include <string>
#include <cassert>
#include <cstdio>
using std::cout;
using std::cin;
using std::endl;
using std::string;

string int2roman(int n) {
  assert(n > 0 && n < 4000);
  string rom;
  // string rom = "";
  while (n >= 1000) { rom += "M"; n -= 1000; }
  while (n >= 900) { rom += "CM"; n -= 900; }
  while (n >= 500) { rom += "D"; n -= 500; }
  while (n >= 400) { rom += "CD"; n -= 400; }
  while (n >= 100) { rom += "C"; n -= 100; }
  while (n >= 90) { rom += "XC"; n -= 90;}
  while (n >= 50) { rom += "L"; n -= 50; }
  while (n >= 40) { rom += "XL"; n -= 40;}
  while (n >= 10) {rom += "X"; n -= 10;}
  while (n >= 9) {rom += "IX"; n -= 9;}
  while (n >= 5) {rom += "V"; n -= 5;}
  while (n >= 4) { rom += "IV";n -= 4; }
  while (n >= 1) { rom += "I"; n -= 1; }
  return rom;
}

int key(char c) {
  if (c == 'I')  return 1;
  if (c == 'V')  return 5;
  if (c == 'X')  return 10;
  if (c == 'L')  return 50;
  if (c == 'C')  return 100;
  if (c == 'D')  return 500;
  if (c == 'M')  return 1000;
  return 0;
}

int roman2int(string s) {
  int num;
  int i;
  int n = s.length();
  for (i=n-1; i>=0; i--) {
    if (key(s[i]) < key(s[i+1]) ){
      num -= key(s[i]);
    }
    else {
      num += key(s[i]);
    }
  }
  return num;
}

int main() {
 string rom, roman;
 int num, number;
 cout << "Enter a number between 1-3999" << endl;
 cin >> num;
 roman = int2roman(num);
 cout << ">> " << roman << endl;
 cout << "Enter Roman numeral betweem I and MMMCMXCIX: ";
 cin >> rom;
 number = roman2int(rom);
 cout << ">> " << number << endl;
 return 0;
}

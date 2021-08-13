#include <iostream>
#include <cstdio>
#include <cassert>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;

string dec2bin(int n) {
  string bin;
  while (n != 0) {
    bin = to_string(n%2) + bin;
    n /=  2;
  }
  return bin;
}

int bin2dec(string s) {
  int tmp,num = 1;
  int i,k=0;
  int n = s.length()-1;
  assert(n<=16);
  while (k < n) {
    if (s[k] == '1') {
      tmp = 1;
      for (i=0;i<n-k;i++) {
          tmp *= 2;
      }
      num += tmp;
    }
    k++;
  }
  return num;
}

int main() {
 string bin, binary;
 int dec, decimal;
 cout << "Enter a integer between 0-65535: ";
 cin >> dec;
 binary = dec2bin(dec);
 cout << "Binary representation: " << binary << endl;
 cout << "Enter binary number betweem 0 and 11111111111111111: ";
 cin >> bin;
 decimal = bin2dec(bin);
 cout << "Decimal form: " << decimal << endl;

 return 0;
}

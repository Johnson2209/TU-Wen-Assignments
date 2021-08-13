#include "fraction.hpp"
using std::ostream;
using std::cout;

// Standard constructors
Fraction::Fraction(int p, int q) {
  assert(q != 0);
  if (q < 0) {
    this->p = -p;
    this->q = abs(q);
  }
  else {
    this->p = p;
    this->q = q;
  }
}

// Copy constructor
Fraction::Fraction(const Fraction& rhs) {
   p = rhs.p;
   q = rhs.q;
}

Fraction::~Fraction() {
 }

Fraction& Fraction::operator=(const Fraction& rhs) {
   if (this != &rhs) {
     p = rhs.p;
     q = rhs.q;
  }
   return *this;
 }

 int Fraction::num() const {
   return p;
 }

 int Fraction::den() const {
   return q;
 }

 void Fraction::reduce() {
   int a = p;
   int b = q;
   while (b) {
     int t = b;
     b = a%b;
     a = t;
   }

   p /= abs(a);
   q /= abs(a);
 }

 Fraction::operator double() const {//type casting
   return (double)p/q;
 }

 Fraction::Fraction(double k) {//type casting from double to fraction
     this->p = (int) (k*1e9);
     this->q = (int) (1e9);
     this->reduce();
 }

// const Fraction Fraction::operator-() const {
//  return Fraction(-p,-q);
//  }
//
//  const Fraction Fraction::operator~() const {
// return Fraction(p,-q);
//  }

 const Fraction operator+(const Fraction& x,const Fraction& y){
   int p1 = x.num();
   int q1 = x.den();
   int p2 = y.num();
   int q2 = y.den();
   Fraction r = Fraction(p1*q2 + p2*q1, q1*q2);
   r.reduce();
   return r;
 }

 const Fraction operator-(const Fraction& x,const Fraction& y){
   int p1 = x.num();
   int q1 = x.den();
   int p2 = y.num();
   int q2 = y.den();
   Fraction r = Fraction(p1*q2 - p2*q1, q1*q2);
   r.reduce();
   return r;
 }

 const Fraction operator*(const Fraction& x,const Fraction& y){
   int p1 = x.num();
   int q1 = x.den();
   int p2 = y.num();
   int q2 = y.den();
   Fraction r = Fraction(p1*p2, q1*q2);
   r.reduce();
   return r;
 }

 const Fraction operator/(const Fraction& x,const Fraction& y){
   int p1 = x.num();
   int q1 = x.den();
   int p2 = y.num();
   int q2 = y.den();
   assert(p2 != 0);
   Fraction r = Fraction(p1*q2, q1*p2);
   r.reduce();
   return r;
 }

 const Fraction operator-(const Fraction& x){
   int p = x.num();
   int q = x.den();
   Fraction r = Fraction((-1)*p, q);
   r.reduce();
   return r;
 }

 std::ostream& operator<<(std::ostream& output, const Fraction& x) {
   if (x.den() == 1) {
     return output << x.num();
   }
   else if (x.num() == 0) {
     return output << 0;
   }
   else {
     return output << x.num() << "/" << x.den();
  }
}

bool operator==(const Fraction& x,const Fraction& y){
  return x.num()*y.den() == y.num()*x.den();
}

bool operator!=(const Fraction& x,const Fraction& y){
  return !(x == y);
}

bool operator<(const Fraction& x,const Fraction& y){
    return x.num()*y.den() < y.num()*x.den();
}

bool operator>(const Fraction& x,const Fraction& y){
    return !(x < y);
}

bool operator<=(const Fraction& x,const Fraction& y){
    return x.num()*y.den() <= y.num()*x.den();
}

bool operator>=(const Fraction& x,const Fraction& y){
    return !(x <= y);
}


//////////////////////////////////////////////////////////////////////////////////
// FractoinVector methods

FractionVector::FractionVector(int len, Fraction init) {
  assert(len > 0);
  this->len = len;
  fract = new Fraction[len];
  for (int j=0; j<len; ++j) {
    fract[j] = init;
  }
  // just for demonstration purposes
  // cout << "constructor, length " << len << "\n";
}

 FractionVector::FractionVector(FractionVector& rhs) {
   len = rhs.len;

   fract = new Fraction[len];
   for (int j=0; j<len; ++j) {
     fract[j] = rhs[j];
   }

   // just for demonstration purposes
   // cout << "copy constructor, length " << len << "\n";
 }

 FractionVector::~FractionVector() {
      delete[] fract;
    // just for demonstration purposes
    // cout << "free fractionvector, length " << len << "\n";
  }

  FractionVector& FractionVector::operator=(const FractionVector& rhs) {
    if (this != &rhs) {
      if (len != rhs.len) {
         delete[] fract;
         len = rhs.len;
         fract = new Fraction[len];
       }
      for (int j=0; j<len; ++j) {
        fract[j] = rhs[j];
      }
    }
    // just for demonstration purposes
    // cout << "deep copy, length " << len << "\n";
    return *this;
  }

  int FractionVector::length() const {
    return len;
  }

 const Fraction& FractionVector::operator[](int j) const {
    assert(j>=0 && j<len);
    return fract[j];
  }

  Fraction& FractionVector::operator[](int j) {
    assert(j>=0 && j<len);
    return fract[j];
  }

  void FractionVector::sort(){
      int i, k, ind;
      Fraction tmp_val;
      for(i=1;i<len;i++){
          tmp_val = fract[i];
          k = i - 1;

          while(k >= 0 && fract[k] > tmp_val){
              fract[k+1] = fract[k];
              k--;
          }
          fract[k+1] = tmp_val;
      }
  }

  std::ostream& operator<<(std::ostream& output, const FractionVector& p) {
    int len = p.length();
    if (len == 0) {
      return output << 0;
    }
    else {
      output << "(" << p[0];
      for (int i=1;i<len;i++) {
        output << " , " << p[i];
      }
      output << ")";
      return output;
   }
  }

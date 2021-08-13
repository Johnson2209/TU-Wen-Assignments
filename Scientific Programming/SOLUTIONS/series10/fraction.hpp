#ifndef _FRACTION_
#define _FRACTION_

#include <iostream>
#include <cmath>
#include <cassert>

class Fraction {
 private:
   int p;
   int q;
 public:
   Fraction(int=0, int=1);
   Fraction(const Fraction&);
   ~Fraction();
   Fraction& operator=(const Fraction&);

   int num() const;
   int denom() const;
   void reduce();

   operator double() const;
   Fraction(double);

   // const Fraction operator~() const;
   // const Fraction operator-() const;

};

 const Fraction operator+(const Fraction&, const Fraction&);
 const Fraction operator-(const Fraction&, const Fraction&);
 const Fraction operator*(const Fraction&, const Fraction&);
 const Fraction operator/(const Fraction&, const Fraction&);

 const Fraction operator-(const Fraction&);
 std::ostream& operator<<(std::ostream& output, const Fraction& x);

 bool operator==(const Fraction&, const Fraction&);
 bool operator!=(const Fraction&, const Fraction&);
 bool operator<(const Fraction&, const Fraction&);
 bool operator<=(const Fraction&, const Fraction&);
 bool operator>(const Fraction&, const Fraction&);
 bool operator>=(const Fraction&, const Fraction&);





 // The class FractionVector stores fractionvectors of length n in N
 class FractionVector {
  private:
    int len;
    Fraction* entries;

  public:
  // constructors, destructor, assignment
    // FractionVector();   No standard constructor (full of problems)
    FractionVector(int len, Fraction init);
    FractionVector(FractionVector&);
    ~FractionVector();
    FractionVector& operator=(const FractionVector&);
  // returns the length of fractionvector
    int length() const;
  // read and write entries
    const Fraction& operator[](int j) const;
    Fraction& operator[](int j);
  // Sort fractionvector using insertion sort
    void sort();
 };

  std::ostream& operator<<(std::ostream& output, const FractionVector& p);


#endif

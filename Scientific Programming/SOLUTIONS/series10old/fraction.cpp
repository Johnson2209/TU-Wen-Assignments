 #include "fraction.hpp"
 using std::cout;
 using std::ostream;

 Fraction::Fraction() {
   p=0, q=1;
    }

Fraction::Fraction(int p, int q) {
this->p = p;
this->q =q;
assert(q!=0);
  if(q<0){    q=-q;    p=-p   ;   }
   }

Fraction::Fraction(const Fraction& rhs) {
 p = rhs.p;
 q = rhs.q;
 }

 Fraction::~Fraction() {
 }

 Fraction& Fraction::operator=(const Fraction& rhs) {
 if (this != &rhs) {
 p = rhs.p;
 q= rhs.q;
 }
 return *this;
 }

 int Fraction::num() const {
 return p;
 }

 int Fraction::den() const {
return q;
 }

double Fraction::abs() const {
 return sqrt(q*q);
 }

 void Fraction::print() const {
   cout << p << " / "<< q ;
 }

 Fraction::operator double() const {
 return p;
 }


 const Fraction Fraction::operator-() const {

 return Fraction(-p,q);
  }

//aoverloading of operators
//addition
 const Fraction operator+(const Fraction& x,const Fraction& y){
int xnum = x.num();
 int xden = x.den();
 int ynum = y.num();
 int yden = y.den();
 return Fraction(xnum*yden + ynum*xden, xden*yden);
 }

//subtraction
 const Fraction operator-(const Fraction& x,const Fraction& y){
   int xnum = x.num();
   int xden = x.den();
   int ynum = y.num();
   int yden = y.den();
   return Fraction(xnum*yden - ynum*xden, xden*yden);
  }

//multiplication
 const Fraction operator*(const Fraction& x,const Fraction& y){
   int xnum = x.num();
   int xden = x.den();
   int ynum = y.num();
   int yden = y.den();
 return Fraction(xnum*ynum, xden*yden);
 }

 const Fraction operator/(const Fraction& x, const Fraction& y){
  assert(x.den() != 0);
  assert(y.den() != 0);
 return Fraction(x.num()*y.den(), x.den()*y.num());
 }

 // const Fraction operator/(const Fraction& x,const Fraction& y){
 // double norm = y.abs();
 // assert(norm > 0);
 // return x*~y / (norm*norm);
 // }

 std::ostream& operator<<(std::ostream& output,
 const Fraction& x) {
 if (x.den() == 0) {
 return output << "denominator cannot be zero";
 }
 else if (x.num() == 0) {
 return output << 0;
 }
 else {
 return output << x.num() << " / " << x.den();
 }
 }

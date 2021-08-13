#include "polynomial.hpp"
using std::ostream;

//standard constructor, empty
Polynomial::Polynomial(){
  deg=0;
  coeff=(double*)0;//null pointer, it points to no where
};

// constructor
Polynomial::Polynomial(int deg){
  this->deg=deg;
  assert (deg>=0);
    if (deg==0){
  coeff=(double*)0;
}
else{
  coeff= new double[deg+1]; // dynamic memory allocation
  for (int n=0; n<deg+1; ++n){
    coeff[n]=0;//initializes all coefficients as zeros
  }
}
  return coeff[n]*;//prints out degree of polynomial/costructor
};


//copy constructor
Polynomial::Polynomial(const Polynomial& rhs){
  deg=rhs.deg;
  if(deg==0){
    coeff=(double*)0;
  }
  else{
    coeff= new double[deg+1]   //new memory allocation for the coefficient vector of the output
    for (int n=0; n<deg+1; ++n){
      coeff[n]=rhs[n];
    }
  }
return coeff[n]*;//prints out degree of polynomial/copy constructor

};

//assignment operator
Polynomial& Polynomial::operator=(const Polynomial& rhs){
if(this!=&rhs){
  if(deg!=rhs.deg){
    if(deg>0){
      delete[] coeff;
    }
    deg=rhs.deg;
    if( deg>0){
      coeff=new double[deg+1]
    }
    else{
      coeff= (double*) 0;
    }
  }
  for (int n=0;n<deg;++n){
    coeff[n]=rhs[n];
  }
}
cout<<"deep copy"<<deg<<"\n";
return *this;
};

//destructor
Polynomial::~Polynomial(){
  if(deg>=0){
    delete[] coeff; //memory deallocation
  }
  cout<<"free lenght/degree of polynomial"<<deg<<"\n";
};

//method to get polynomial degree n, a read only method "marked with const"
int Polynomial::degree() const{
  return deg;
};

operator double() const{
  return deg;
}

//accesses the coefficients of polynomial for constant objects
const double& Polynomial::operator[](int j) const
{
assert(j>-1 && j<=n);
return coeff[j];
}

//accesses the coefficients of polynomial for normal objects
double& Polynomial::operator [](int j)
{
assert(j>-1 && j<=n);
return coeff[j];
}

//possibility of printing via "cout<<p"
std::ostream& operator<<(std::ostream& output, const Polynomial& p){
    //if(p.deg=0){
    return output<<p.print();

}

void Polynomial::print() const{
   for(int n=0; n<<deg; ++n){
  std::cout<<coeff[n]<<"*"<<"x^"<<n<<"+";
  std::cout<<coeff[0]<<" = P(x) "<<std::endl;
}
}

int main(){
  int deg=0;
  double * coeff;
  Polynomial p;

  cout<<"enter degree of polynomial:"<<endl;
  cin>>deg;
  p.degree() const;
  coeff= new double[deg+1];

  for(int n=0;n<number_of_coefficients;++n){
  cin>>coeff[n]
}
    p(deg);
    p.print();

  return 0;
}

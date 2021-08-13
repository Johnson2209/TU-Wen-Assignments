#include "upper.hpp"
using std::cout;
using std::ostream;

//UpperTriangularMatrix::UpperTriangularMatrix() {
 // n = 0;
 // u = (double*) 0;
 //  cout << "constructor, empty\n";
 // }


UpperTriangularMatrix::UpperTriangularMatrix(int n, double init) {
   assert(n>=0);
   this ->n = n;
   int s;// number of elements to be stored

   if (n == 0) {
     u = (double*) 0;
   }
   else {
     int s;
     s = n*(n+1)/2;
     assert(u != (double*) 0);
     u = new double[s];
     for (int j=0; j<s; ++j) {
       u[j] = init;
     }
  }
  cout << "constructor, length " << n << "\n";
}


UpperTriangularMatrix::UpperTriangularMatrix(const UpperTriangularMatrix& rhs) {
  n = rhs.n;
  int s; // number of elements to be copied
  if (n == 0) {
    u = (double*) 0;
  }
  else {
    s = n*(n+1)/2;
    assert(u != (double*) 0);
    u = new double[s];
    for (int j=0; j<s; ++j) {
      u[j] = rhs.u[j];
    }
  }
  cout << "copy constructor, length " << n << "\n";
  }



UpperTriangularMatrix& UpperTriangularMatrix::operator=(const UpperTriangularMatrix& rhs) {
  if (this != &rhs) {
    if (n != rhs.n) {
      // get rid of previous memory allocation
       if (n > 0) {
         delete[] u;
       }

      // allocate new memory
       n = rhs.n;
       if (n > 0) {
         int s;
          s = n*(n+1)/2;
         u = new double[s];
         // fill in with new values
          for (int j=0; j<s; ++j) {
            u[j] = rhs.u[j];
          }
       }
       else {
         u = (double*) 0;
       }
     }
  }
    cout << "deep copy, length " << n << "\n";
  return *this;
}


UpperTriangularMatrix::~UpperTriangularMatrix() {
   if (n > 0) {
     delete[] u;
   }
   cout << "free vector, length " << n << "\n";
}


int UpperTriangularMatrix::size() const {
  return n;
}

const double& UpperTriangularMatrix::operator()(int j, int k) const {
  assert(j>=0 && j<n);
  assert(k>=0 && k<n);
  if (k < j) {
    int tmp = (k*(k-1))/2;
    int l = j+k+tmp;
    int p=n*n-l;
     return u[p];    //try to fix this
  }
  else {
    int tmp = (k*(k-1))/2;
    int l = j+k+tmp;
    return u[l];
  }
}

double& UpperTriangularMatrix::operator() (int j, int k) {
  assert(j>=0 && j<n);
  assert(k>=0 && k<n);
  if (k < j) {
    int tmp = (k*(k-1))/2;
    int l = j+k+tmp;
    int p=n*n-l;
     return u[p];    //try to fix this
    // return (double*) 0;
    // return 0;      try to fix this
  }
  else {
    int tmp = (k*(k-1))/2;
    int l = j+k+tmp;
    return u[l];
  }
}


std::ostream& operator<<(std::ostream& output, const UpperTriangularMatrix& mat) {
  int n = mat.size();
  if (n == 0) {
    return output << 0;
  }
  else {
    for (int j=0;j<n;++j) {
      output << "\n";
      for (int k=0;k<n;++k) {
        if (k<j) {
          output << 0 << " ";
        }
        else {
          output << mat(j,k) << " ";
        }
      }
    }
    return output;
 }
}


double UpperTriangularMatrix::columnSumNorm() const {
  UpperTriangularMatrix mat(*this); //find a way without this
  double maxk = 0;
  for(int k = 0;k<n;k++){
    double sum = 0;
    for(int j = 0;j<n;j++){
      if (k<j) continue;
      sum += fabs(mat(j,k));
    }
    if (sum > maxk) maxk = sum;
  }
  return maxk;
}

double UpperTriangularMatrix::rowSumNorm() const{
  UpperTriangularMatrix mat(*this); //find a way without this
  double maxj = 0;
  for(int j = 0;j<n;j++){
    double sum = 0;
    for(int k = 0;k<n;k++){
      if (k<j) continue;
      sum += fabs(mat(j,k));
    }
    if (sum > maxj) maxj = sum;
  }
  return maxj;
}

const UpperTriangularMatrix operator+(const UpperTriangularMatrix& rhs1, const UpperTriangularMatrix& rhs2) {
   assert(rhs1.size() == rhs2.size());
     UpperTriangularMatrix r(rhs1);
     for (int j=0; j<r.size(); ++j) {
       for (int k=0; k<r.size(); ++k) {
         if (k<j) continue;
         r(j,k) += rhs2(j,k);
       }
     }
     return r;
   }

const UpperTriangularMatrix operator*(const UpperTriangularMatrix& rhs1, const UpperTriangularMatrix& rhs2) {
  assert(rhs1.size() == rhs2.size());
    UpperTriangularMatrix c(rhs1.size());
    for (int i=0; i<c.size(); ++i) {
      for (int j=0; j<c.size(); ++j) {
        if (j<i) continue;    //skip lower part
        for (int k=0; k<c.size(); ++k) {
          if (k<i || j<k) continue;
          c(i,j) += rhs1(i,k)*rhs2(k,j);
        }
      }
    }
    return c;
  }

const Vector operator*(const UpperTriangularMatrix& rhs1, const Vector& x) {
   assert(rhs1.size() == x.size());
   Vector b(x.size());
   for (int j=0;j<rhs1.size();++j) {
     for (int k=0;k<rhs1.size();++k) {
       if (k<j) continue;
       b[j] += rhs1(j,k)*x[k];
     }
   }
   return b;
   }

const Vector operator|(const UpperTriangularMatrix& rhs1, const Vector& b) {
  assert(rhs1.size() == b.size());
  int n = rhs1.size();
  for (int i=0;i<n;++i) {
    assert(rhs1(i,i) != 0);
  }
  Vector x(n);
  for (int j=n-1;j>=0;--j) {
    double sum = 0;
    for (int k=j+1;k<n;++k) {
      if (k<j) continue;
      sum += rhs1(j,k)*x[k];
    }
    x[j] = (1/rhs1(j,j))*(b[j]-sum);
  }
  return x;
}

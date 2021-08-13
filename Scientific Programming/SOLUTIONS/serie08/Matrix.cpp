#include "Matrix.h"
using namespace std;
Matrix::Matrix(){
    this->type = 'F';
    coeff = (double*) 0;
}

Matrix::Matrix(int n, char type){
    assert(n>0);
    this->type = type;
    int s;
    if(this->type == 'F')
        s = n*n;
    else if(this->type == 'U' || this->type =='L')
        s = n*(n+1)/2;

    assert(coeff != (double*) 0);
    coeff = (double*) malloc(s*sizeof(double));
    for (int i=0; i<s; i++) {coeff[i]= 0;}
}

Matrix::Matrix(int n, char type, double value){
    assert(n>0);
    this->type = type;
    int s;
    if(this->type == 'F')
        s = n*n;
    else if(this->type == 'U' || this->type =='L')
        s = n*(n+1)/2;

    assert(coeff != (double*) 0);
    coeff = (double*) malloc(s*sizeof(double));
    for (int i=0; i<s; i++){
        coeff[i]= value;
      }
}

Matrix::Matrix(int n, char type, double lb, double ub){
    assert(n>0);
    this->type = type;
    int s;
    if(this->type == 'F')
        s = n*n;
    else if(this->type == 'U' || this->type =='L')
        s = n*(n+1)/2;

    assert(coeff != (double*) 0);
    coeff = (double*) malloc(s*sizeof(double));
    double rnd;
    for (int i=0; i<s; i++){
        rnd = (ub - lb)*((double)rand() /(double)RAND_MAX) + lb;
        coeff[i] = rnd;
    }
}

int Matrix::getN(){
    return this->n;
}
void Matrix::setN(int n){
    assert(n>0);
    this->n = n;
}
char Matrix::getType(){
    return this->type;
}
void Matrix::setType(char type){
    this->type = type;
}
void Matrix::set(int k, double value){
    assert(k >= 0 && k < n*n);
    coeff[k] = value;
}
double Matrix::get(int k){
    assert(k >= 0 && k < n*n);
    return coeff[k];
}
Matrix::~Matrix(){ free(coeff);}

void Matrix::scanMatrix(int n, char type) {             //this funtion is perfect

std::cout<<"Enter the elements of the matrix in order: "<<std::endl;
int k = 0;
this->n = n;
this->type = type;


    if ( type == 'F') {
        len = n*n;
        vec = (double*)malloc(n*n*sizeof(double));
        coeff = (double*)malloc(n*n*sizeof(double));
        for (int i=0; i<len; i++)
            {std::cin>>vec[i];
            /*coeff[i] = vec[i];*/}
         for (int i = 0; i < n; i++)
            for ( int j = 0; j<n; j++ , k++)
            {
            coeff[j*n + i] = vec[k];
            }
        }
    else if (type == 'L') {
        len = n*(n+1)/2;
        vec = (double*)malloc(len*sizeof(double));
        coeff = (double*)malloc(n*n*sizeof(double));
        for (int i=0; i<len; i++)
            std::cin>>vec[i];
        for (int i = 0; i<n ; i++)
            for (int j = i; j<n; j++, k++)
               {
               //if (coeff[j*n+i] == 0)
               coeff[j*n+i] = vec[k];
               /*std::cout<<vec[k];*/}
            }
        else if (type == 'U')
        {
        len = n*(n+1)/2;
        //std::cout<<" haha"<<std::endl;
        vec = (double*)malloc(len*sizeof(double));
        coeff = (double*)malloc(n*n*sizeof(double));
        for (int i=0; i<len; i++)
            std::cin>>vec[i];
        for (int i = 0; i<n; i++)
            for (int j = 0; j<=i; j++, k++)
               coeff[j*n+i] = vec[k];
            }


// void Matrix::scanMatrix(int n, char type){
//     int s;
//     cout<<"enter dimension";
//     getN();
//     setN(getN());
//     cout<<"enter type";
//     getType();
//     setType(getType());
//     if(type == 'U' || type == 'L'){
//         s = n*(n+1)/2;
//         for(int i = 0; i < s;i++){
//           cout<<"enter values";
//             cin >> coeff[i];
//         }
//       }
//     else
//         s = n*n;
//     for(int i = 0; i < s;i++){
//         cin >> coeff[i];
//     }
// }

void Matrix::printMatrix(){
    if(this->type == 'L'){
        int s = n*(n+1)/2;
        int k = n;
        for(int i = 0;i < n;i++){
            for(int j=0;j<=i;j++){
                cout << setw(5) << coeff[i+j*n];
            }
cout << '\n';
        }
    }else if(this->type == 'U'){
        int s = n*(n+1)/2;
        int k =1;
        for(int i = 0;i < n;i+=k){
            for(int j=n;j<s;j++){
                cout << setw(5) << coeff[i+j];
                j++;
            }
            cout << '\n';
            k++;
                    }
    }else{
        for(int i = 0;i < n;i++){
            for(int j = n;j<n*n;j+=n){
                cout << setw(5) << coeff[i+j];
            }
            cout << '\n';
        }
    }
}

double Matrix::columnSumNorm(){
    double sum = 0;
    double max = 0;
    int j;
    if(this->type == 'U' || this->type == 'L'){
        int s = n*(n+1)/2;
        for(int i = 0;i<s;i++){
                if(j < i)   continue;
                else        sum += coeff[i+j];
            }
        }

    else{
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                sum += abs(coeff[i+j]);
            }
            if(sum > max)
                max = sum;
        }

    }
}

// double Matrix::rowSumNorm(){
//     double sum = 0;
//     if(this->type == 'U' || this->type == 'L'){
//         int s = n*(n+1)/2;
//         int j=0;
//         for(int i = 0;i<s;i++){
//                 if(j < i)   continue;
//                 else        sum += coeff[i+j];
//             }
//         }
//
//     else{
//         for(int i = 0;i<n;i++){
//             for(int j = n;j<n*n;j+=n){
//                 sum += coeff[i+j];
//             }
//             if(sum > max)
//                 max = sum;
//         }
//
//     }
// }

double Matrix::frobeniusNorm(){
    double sum = 0;
    for(int i = 0; i < n*n; i++)
        sum += pow(coeff[i], 2.0);

    return sqrt(sum);
}

double Matrix::trace(){
    double sum = 0;
    if(this->type == 'U'){

    }else if(this->type == 'L'){

    }else{
        for(int i = 0;i < n*n;i=i+n+1)
            sum += coeff[i];
    }

}
bool Matrix::isDiagonal(){
    if(this->type == 'U'){
return true;
    }
    else if(this->type == 'L'){
return true;
    }
    else{
        for(int i = 0;i < n*n;i=i+n+1){
          for(int j=0;j< n*n; ++j)
          if((i!=j)&&(coeff[i]!=0)&&(coeff[j]==0)){
          return true;
        }
    }
}
}

bool Matrix::isSymmetric(){
    if(this->type == 'U' || this->type == 'L'){
        if(isDiagonal())
            return true;
        else
            return false;
    }
    else{
        for(int i = 0;i < n*n;i=i+n+1){
          for (int j=0, k=n*n-1;j<n*n&&k>=0;j++,k--){
          if((k!=i)&&(j!=i)&&(coeff[k]==coeff[j])){
          return true;
        }
        }
    }
}
}

bool Matrix::isSkewSymmetric(){
    if(this->type == 'U' || this->type == 'L'){
        if(!isDiagonal())
            return false;
        else
              return true;
          }

    else{
        for(int i = 0;i < n*n;i=i+n+1){
          for (int j=0, k=n*n-1;j<n*n&&k>=0;j++,k--){
          if((k!=i)&&(j!=i)&&(coeff[k]==-coeff[j])){
          return true;
        }
    }
  }
}
}

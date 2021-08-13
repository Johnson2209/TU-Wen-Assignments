#include <iostream>
#include <math.h>

class Matrix {
private:
    int n;
    double *coeff;
    char type;
public:
    double *vec;
    int len;
    void scanMatrix(int n, char type);
    void printMatrix();
    double columnSumNorm();
    double rowSumNorm();
    double frobeniusNorm();
    Matrix();
    Matrix(int dim, char typ);
    Matrix(int dim, char typ, double init);
    ~Matrix();

};


double Matrix::frobeniusNorm() {
double *ele_sq;
double fnorm;
double fnorm_;

ele_sq = (double*)malloc(len*sizeof(double));
for( int i = 0; i<len; i++)
    ele_sq[i] = vec[i]*vec[i];
for( int i= 0; i<len; i++)
    fnorm +=ele_sq[i];

fnorm_ = sqrt(fnorm);
std::cout<<" test"<<fnorm_<<std::endl;

}

double Matrix::columnSumNorm() {
double *colsum;
colsum = (double*)malloc(n*sizeof(double));            //problem area
colsum[0] = 0;
//std::cout<<n<<"  asdafa "<<vec[3]<<coeff[3]<<std::endl;
int k=0;
for( int i = 0; i<n; i ++)
    for(int j = 0; j<n; j++, k++)
        colsum[i] += coeff[j*n + i];

// find max from colsum[i

double max;
max = colsum[0];
for (int i = 0; i<n ; i++)
    {
    if (colsum[i]>=max)
        max = colsum[i];
    }
//std::cout<<" column sum norm is :"<<max<<std::endl;
    return max;
        }


double Matrix::rowSumNorm() {
double *rowsum;
rowsum = (double*)malloc(n*sizeof(double));            //problem area
rowsum[0] = 0;
//std::cout<<n<<"  asdafa "<<vec[3]<<coeff[3]<<std::endl;
int k=0;
for( int i = 0; i<n; i ++)
    for(int j = 0; j<n; j++, k++)
        rowsum[i] += coeff[i*n + j];

// find max from colsum[i

double max;
max = rowsum[0];
for (int i = 0; i<n ; i++)
    {
    if (rowsum[i]>=max)
        max = rowsum[i];
    }
std::cout<<" row sum norm is :"<<max<<std::endl;
    return max;
        }


Matrix::~Matrix() {}

Matrix::Matrix() {
    n = 0;
    coeff = (double*) 0;
    std::cout<<"Standard empty vector allocated"<<std::endl;
}

Matrix::Matrix(int dim, char typ) {
    n = dim;
    type = typ;
    len = dim*dim;
    coeff = (double*)malloc(n*n*sizeof(double));            //problem area
    for (int i=0; i<dim; i++)
        coeff[i] = 0;

    std::cout<<" zero matrix initialized of size "<<dim<<std::endl;
}

Matrix::Matrix(int dim, char typ, double init) {
    int k = 0;      // problm
    n = dim;
    type = typ;
    if (type == 'F') {
        len = n*n;
        vec = (double*)malloc(n*n*sizeof(double));
        coeff = (double*)malloc(n*n*sizeof(double));
        for (int i=0; i<len; i++)
            {vec[i] = init;
            coeff[i] = vec[i];}
            }
    else if (type == 'L') {
        len = n*(n+1)/2;
        vec = (double*)malloc(len*sizeof(double));
        coeff = (double*)malloc(n*n*sizeof(double));
        for (int i=0; i<len; i++)
            vec[i] = init;
        for (int i = 0; i<n ; i++)
            for (int j = 0; j<=i; j++, k++)
               {coeff[i*n+j] = vec[k];
               /*std::cout<<coeff[i*n+j];*/}
            }
        else if (type == 'U')
        {
        len = n*(n+1)/2;
        //std::cout<<" haha"<<std::endl;
        vec = (double*)malloc(len*sizeof(double));
        coeff = (double*)malloc(n*n*sizeof(double));
        for (int i=0; i<len; i++)
            vec[i] = init;
        for (int i = 0; i<n; i++)
            for (int j = 0; j<=i; j++, k++)
               coeff[j*n+i] = vec[k];
            }
        //std::cout<<" nxn matrix initialized"<<std::endl;



};

void Matrix::printMatrix() {    // works perfect

for (int i = 0; i<n; i++)
    { for(int j = 0; j<n; j++)
        {std::cout<<coeff[i*n + j]<<" ";}
        std::cout<<std::endl;
    }
//for (int i = 0; i < len; i++)
 //   std::cout<<" Testing "<<vec[i];
}

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

 //           for (int i = 0; i<n; i++)
  //              { for(int j = 0; j<n; j++)
  //                  {std::cout<<coeff[i*n + j]<<" ";}
   //             std::cout<<std::endl;
   // }
}

using namespace std;



int main() {
//Matrix m;
//Matrix m;
//Matrix();
//Matrix m(8, 'F');
Matrix m;
m.scanMatrix(3, 'F');
//Matrix ~m();
//m.columnSumNorm();
//m.rowSumNorm();
m.frobeniusNorm();
m.printMatrix();
}

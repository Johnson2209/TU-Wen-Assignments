#include "Matrix.h"
using namespace std;

int main(){
  srand(time(NULL));
    Matrix m1,m;
    Matrix m2(3, 'F');
    Matrix m3(4, 'L', 1);
    Matrix m4(5,'F',1,10);

    cout << m.getType() << endl;
    //cout << <<"matrix is"m.printMatrix() << endl;
    // m.setN(3);
    // m.getN();
    // m.setType('F');
    // m.getType();
    // m.set(1,1.5);
    // m.set(4,.5);
    // m.set(6,0.34);
    // m.set(5,10);
    // m.set(2,10);
    // m.set(3,1);
    // m.set(7,10);
    // m.set(8,100);
    // m.set(0,8.67);
    // m.get(8);
    cout<<m.isDiagonal();
    m2.scanMatrix(3, 'F');
    m2.printMatrix();

    //m.scanMatrix(3, 'F');
    //m1.printMatrix();

}

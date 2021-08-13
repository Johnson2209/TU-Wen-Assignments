#include <iostream>
#include <math.h>
using namespace std;


class Fraction{

    private:
        int p;
        int q;

    public:
      Fraction();
      Fraction(int p, int q);
      Fraction(int dim, char typ, double init);
      ~Fraction();
};

Fraction()
Fraction(int p, int q);
Fraction(int dim, char typ, double init);
~Fraction();

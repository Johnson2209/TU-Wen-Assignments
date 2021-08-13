#include<iostream>
#include <cmath>
using namespace std;
class Triangle {
  private:
   double x[2];
   double y[2];
   double z[2];

  public:
   void setX(double, double);
   void setY(double, double);
   void setZ(double, double);
   double getArea();
   double getperimeter();
   bool isEquilateral();
 };

 void Triangle::setX(double x0, double x1) {
 x[0] = x0; x[1] = x1;
  }

 void Triangle::setY(double y0, double y1) {
  y[0] = y0; y[1] = y1;
 }

 void Triangle::setZ(double z0, double z1) {
 z[0] = z0; z[1] = z1;
 }

 double Triangle::getArea() {
 return 0.5*fabs( (y[0]-x[0])*(z[1]-x[1])
 - (z[0]-x[0])*(y[1]-x[1]) );
 }

 double Triangle::getperimeter(){
   double a=(x[0]-y[0])*(x[0]-y[0]);
   double b=(x[1]-y[1])*(x[1]-y[1]);
   double c=(x[0]-z[0])*(x[0]-z[0]);
   double d=(x[1]-z[1])*(x[1]-z[1]);
   double e=(z[0]-y[0])*(z[0]-y[0]);
   double f=(z[1]-y[1])*(z[1]-y[1]);

return sqrt(a+b)+sqrt(c+d)+sqrt(e+f); }

bool Triangle::isEquilateral(){
  double side1 =sqrt((x[0]-y[0])*(x[0]-y[0])+(x[1]-y[1])*(x[1]-y[1]));
  double side2 =sqrt((x[0]-z[0])*(x[0]-z[0])+(x[1]-z[1])*(x[1]-z[1]));
  double side3 =sqrt((y[0]-z[0])*(y[0]-z[0])+(y[1]-z[1])*(y[1]-z[1]));
    bool   var= (side1==side2) && (side2==side3) && (side1==side3);
       return var;
  }

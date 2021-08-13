#include <cmath>
#include <cassert>

class Ellipse {
  private:
    double center[2];
    double a;
    double b;

  public:
    double getCenter();
    double getA();
    double getB();
    void setCenter(double, double);
    void setA(double);
    void setB(double);
    bool isInside(double, double);
    bool isCircle();
    void printFocalPoints();
    double getEccentricity();
};

double Ellipse::getCenter() {
   return center[0];
}

double Ellipse::getA() {
   return a;
}

double Ellipse::getB() {
   return b;
}

void Ellipse::setCenter(double x0, double x1) {
 center[0] = x0; center[1] = x1;
}

void Ellipse::setA(double aa) {
  assert(aa > 0);
  a = aa;
}

void Ellipse::setB(double bb) {
  assert(bb > 0);
  b = bb;
}

bool Ellipse::isInside(double x, double y) {
  double eqn = ((x-center[0])*(x-center[0]))/(a*a) + ((y-center[1])*(y-center[1])/(b*b));
  if (eqn < 1) {
    return true;
  }
  else if (fabs(1-eqn) <= 1e-9) {
    printf("Point lies on the ellipse\n");
    return true;
  }
  else {
    return false ;
  }
}


bool Ellipse::isCircle() {
  return a == b;
}

void Ellipse::printFocalPoints() {
  double c;
  printf("The focal points are ");
  if (a>b) {
    c = sqrt(a*a-b*b);
    printf("(%.2f, %.2f) and (%.2f, %.2f)\n",center[0]+c,center[1],center[0]-c,center[1]);
  }
  else {
    c = sqrt(b*b-a*a);
    printf("(%.2f, %.2f) and (%.2f, %.2f)\n",center[0],center[1]+c,center[0],center[1]-c);
  }
}

double Ellipse::getEccentricity() {
 if (a>b) {
   return sqrt(1-(b/a)*(b/a));
 }
 else {
   return sqrt(1-(a/b)*(a/b));
 }
}

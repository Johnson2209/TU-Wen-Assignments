#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double secant(double (*f)(double), double x0, double x1, double tau) {

  double* x = malloc(3*sizeof(double));
  assert(x != NULL);
  x[0] = x0;
  x[1] = x1;

  int n = 2;

  while(1) {
    x[n] = x[n-1] - f(x[n-1])*((x[n-2]-x[n-1])/(f(x[n-2])-f(x[n-1])));
    if ((abs(f(x[n])-f(x[n-1])) <= tau)){
      printf("Warning: result is presumably wrong\n");
      return x[n];
    }
    else if (abs(x[n]) <= tau) {
      if ((abs(f(x[n])) <= tau) && (abs(x[n] - x[n-1]) <= tau)) {
        return x[n];
      }
    }
    else {
      if ((abs(f(x[n])) <= tau) && (abs(x[n] - x[n-1]) <= tau*abs(x[n]))) {
        return x[n];
      }
    }
    n++;
    x = realloc(x,n*sizeof(double));
  }
}

double f(double y) {
  //return 1+2*y;     // Change this !
  //return y*y +5*y +6;     // Change this !
return 1-(y*y)*sin(1/y); //the root is not simple, i.e, multiplicity of zero >1,
  //return 1-(1/y);     // Change this !
  //(algorithm does not converge if either x_0 or x_1 =0)
}


int main() {
  double x0;
  double x1;
  double tau;
  double zero;
  double *x;
  printf("x0 = ");
  scanf("%lf",&x0);
  printf("x1 = ");
  scanf("%lf",&x1);
  printf("tau = ");
  scanf("%lf",&tau);

  zero = secant(*f, x0, x1, tau);
  printf("Approximate zero x_n = %.4f and f(x_n) = %.4f\n", zero, f(zero));

  free(x);
}

/*C:\Users\pc\Desktop\MATHMODs\tuwien\scientific programming\series06>output
 f=1+2*y;
x0 = -2
x1 = 1
tau = 7
Warning: result is presumably wrong
Approximate zero x_n = -0.5000 and f(x_n) = 0.0000

C:\Users\pc\Desktop\MATHMODs\tuwien\scientific programming\series06>output
 f=1+2*y;
x0 = -2
x1 = 1
tau = 0.0005
Warning: result is presumably wrong
Approximate zero x_n = -0.5000 and f(x_n) = 0.0000

C:\Users\pc\Desktop\MATHMODs\tuwien\scientific programming\series06>

*/
/*
The iterates x_n of the secant method converge to a root of f,
if the initial values x_0 and x_1 are sufficiently close to the root.
 The order of convergence is φ, where  φ


is the golden ratio. In particular, the convergence is superlinear, but not quite quadratic.

This result only holds under some technical conditions, namely that  f be twice continuously differentiable and the root in question be simple (i.e., with multiplicity 1).

If the initial values are not close enough to the root, then there is no guarantee that the secant method converges. There is no general definition of "close enough",
but the criterion has to do with how "wiggly" the function is on the interval [x_0, x_1].
 For example, if f is differentiable on that interval and there is a point where f'=0 on the interval, then the algorithm may not converge.
*/

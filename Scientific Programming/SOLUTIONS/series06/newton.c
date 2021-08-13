#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double newton(double (*f)(double), double (*fprime)(double), double x0, double tau) {

  double* x = malloc(2*sizeof(double));
  assert(x != NULL);
  x[0] = x0;

  int n = 1;

  while(1) {
    x[n] = x[n-1] - (f(x[n-1])/fprime(x[n-1]));
    if (abs(fprime(x[n])) <= tau) {
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
  return y*y-5*y+6;     // Change this !
}

double fprime(double y) {
  return 2*y-5;    // Change this !

}

int main() {
  double *x;
  double x0;
  double tau;
  double zero;
  printf("x0 = ");
  scanf("%lf",&x0);
  printf("tau = ");
  scanf("%lf",&tau);

  zero = newton(*f, *fprime, x0, tau);
  printf("Approximate zero x_n = %.4f and f(x_n) = %.4f\n", zero, f(zero));
  free(x);
}
/*
FIrst, the function must be differentiable.
The method will usually converge, provided this initial guess is close
enough to the unknown zero, and that f ′(x0) ≠ 0.
for example choose x_0=100, the code will run, but there's no displayed result.
The process does not converge for this x_0!.
 Furthermore, for a zero of multiplicity 1,
 the convergence is at least quadratic (see rate of convergence) in a neighbourhood of the zero,
  which intuitively means that the number of correct digits roughly at least doubles in every step.
  More details can be found in the analysis section below.
*/

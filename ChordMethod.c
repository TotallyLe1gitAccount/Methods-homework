#include <stdio.h>
#include <math.h>

#define EPS 1e-6
#define MAX_iter 1000
#define h 1e-6

double f(double x) {
    return 2 * x - 3 * cbrt(x * x);
}

double df(double (*f)(double), double x) {
    return (f(x + h) - f(x)) / h;
}

double ChordMethod(double a, double b) {
    double x0 = a;
    double x1 = b;
    double x_new;
    int iter = 0;
	    if (df(f, a) * df(f, b) >= 0) {
        if (df(f, a) > 0 && df(f, b) > 0) {
            printf("Function is increasing on [a, b]. Min at x = a: %lf\n", a);
            return a;
        } else if (df(f, a) < 0 && df(f, b) < 0) {
            printf("Function is decreasing on [a, b]. Min at x = b: %lf\n", b);
            return b;
        } else {
            printf("Error: f'(a) and f'(b) must have opposite signs.\n");
            return NAN;
        }
    }
    while (iter < MAX_iter) {
        x_new = x1 - df(f, x1) * (x1 - x0) / (df(f, x1) - df(f, x0));

        printf("Iteration %d: x = %lf, f(x) = %lf, f'(x) = %lf\n", iter, x_new, f(x_new), df(f, x_new));

        if (fabs(df(f, x_new)) < EPS) {
            printf("Min found by %d iterations.\n", iter);
            return x_new;

        }
        x0 = x1;
        x1 = x_new;
	iter++;
    }
    printf("Method didn't work by %d iterations.\n", MAX_iter);
    return x_new;
}

int main() {
    double a = 0.0;
    double b = 2.0;
    double root = ChordMethod(a, b);
    printf("Min: %lf, f(x): %lf\n", root, f(root));
    return 0;
}




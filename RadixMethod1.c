#include <stdio.h>
#include <math.h>

#define EPS 1E-9

double f(double x) {
    return 2 * x - 3 * cbrt(x * x);
}
double Bitwise_search(double a, double b) {
    double delta = (b - a) / 4.0;
    double x0 = a;
    double x1 = x0 + delta;
    double f0 = f(x0);
    double f1 = f(x1);
    int iteration = 0;

    while (delta > EPS) {
        iteration++;
        printf("Iteration %d: x0 = %f, x1 = %f, f(x0) = %f, f(x1) = %f, delta = %f\n", iteration, x0, x1, f0, f1, delta);

        if (f1 < f0) {
            x0 = x1;
            f0 = f1;
            x1 = x0 + delta;
            f1 = f(x1);
        } else {
            delta /= 4.0;
            x1 = x0 - delta;
            f1 = f(x1);
        }

        if (x1 < a || x1 > b) {
            delta /= 4.0;

            if (x1 < a) {
                x1 = x0 + delta;
            } else {
                x1 = x0 - delta;
            }
            f1 = f(x1);
        }
    }

    return (f0 < f1) ? x0 : x1;
}

int main() {
    double a = 0.0;
    double b = 4.0;
    double result = Bitwise_search(a, b);
    printf("Min: %f, f(x): %f\n", result, f(result));
    return 0;
}

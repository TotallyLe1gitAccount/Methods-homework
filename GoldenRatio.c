#include <stdio.h>
#include <math.h>

#define PHI (sqrt(5) - 1) / 2
#define EPS 1e-6

double f(double x) {
        return 2 * x - 3 * cbrt(x * x);
}

double goldenRatio(double a, double b, double (*f)(double)) {
    double x1, x2, f1, f2;
    double tau = PHI;

    x1 = a + (1 - tau) * (b - a);
    x2 = a + tau * (b - a);
    f1 = f(x1);
    f2 = f(x2);

    int iteration = 0;

    while ((b - a) >= EPS) {
        iteration++;
        printf("Iteration: %d, a = %lf, b = %lf, x1 = %lf, x2 = %lf, f(x1) = %lf, f(x2) = %lf\n",
               iteration, a, b, x1, x2, f1, f2);

        if (f1 <= f2) {
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = a + (1 - tau) * (b - a);
            f1 = f(x1);
        } else {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = a + tau * (b - a);
            f2 = f(x2);
        }
    }
    return (a + b) / 2;
}

int main() {
    double a = 0.0;
    double b = 1.0;

    double min_point = goldenRatio(a, b, f);
    printf("Interval [%lf; %lf], Min = %lf, f(x) = %lf\n", a, b, min_point, f(min_point));

    return 0;
}

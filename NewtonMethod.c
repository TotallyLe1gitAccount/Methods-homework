#include <stdio.h>
#include <math.h>

#define TOLERANCE 1e-7
#define MAX_ITERATIONS 1000

double f(double x) {
    return 2 * x - 3 * cbrt(x * x);
}

double df(double x) {
    return 2 - 2 / cbrt(x);
}

double d2f(double x) {
    return (2.0 / 3.0) * pow(x, -4.0 / 3.0);
}

double newton_method(double initial_guess) {
    double x = initial_guess;
    int iteration = 0;

    printf("Iteration |     x      |    f'(x)   \n");
    printf("----------|------------|------------\n");

    while (iteration < MAX_ITERATIONS) {
        double dfx = df(x);
        double d2fx = d2f(x);

        printf("%9d | %10.6f | %10.6f\n", iteration, x, dfx);

        if (fabs(d2fx) < 1e-10) {
            printf("Second derivative is too close to zero. Newton's method cannot continue.\n");
            return x;
        }

        double x_new = x - dfx / d2fx;

        if (fabs(x_new - x) < TOLERANCE) {
            printf("Solution found with tolerance %e in %d iterations.\n", TOLERANCE, iteration + 1);
            return x_new;
        }

        x = x_new;
        iteration++;
    }

    printf("Maximum iterations reached. Last approximation: %f\n", x);
    return x;
}

int main() {
    double initial_guess = 2.0; 

    double root = newton_method(initial_guess);
    printf("Min: %f, f(x) = %f\n", root, f(root));

    return 0;
}

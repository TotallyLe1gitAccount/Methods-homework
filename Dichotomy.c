#include <stdio.h>
#include <math.h>

double f(double x) {
    return 2 * x - 3 * cbrt(x * x);
}

double FindMinimum(double a, double b, double epsilon) {
    double mid1, mid2;
	while( (b-a)/2 >= epsilon ) {
        mid1 = (b+a-epsilon) / 2;
        mid2 = (b+a+epsilon) / 2;

	printf("a=%.4f, b=%.4f, mid1 = %.4f, mid2 = %.4f, f(mid1) = %.4f, f(mid2) = %.4f\n", a, b, mid1, mid2, f(mid1), f(mid2));

        if (f(mid1) < f(mid2))
            b = mid2;
        else
            a = mid1;
}    
    return (a + b) / 2;
}

int main() {
    double a = 0, b = 1;   
    double epsilon = 0.05; 

    double xmin = FindMinimum(a, b, epsilon);
    double ymin = f(xmin);
    printf("Interval: {%.4f ; %.4f}\n", a, b);
    printf("Min x = %.4f\n", xmin);
    printf("Function f(x) = %.4f\n", ymin);

    return 0;
}



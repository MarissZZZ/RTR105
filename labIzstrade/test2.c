#include <stdio.h>
#include <math.h>

// Function to calculate sin^2(x) using the Taylor series
double lietotaja_sinuss_kvadrats(long double x) {
    long double a, S;
    int k = 1;

    // Correction: Initialize a using the first term of the series for sin^2(x)
    a = x; // The first term of sin(x) Taylor series is x
    S = a * a; // sin^2(x) starts with x^2

    printf("x=%.2Lf\ta1=%.2Lf\tS1=%.2Lf\n", x, a, S);

    // Iterate to calculate the terms of the Taylor series
    while (k <= 500) {
        // Correction: Calculate the next term in the Taylor series for sin(x)
        a = a * (-1) * x * x / ((2 * k) * (2 * k + 1));
        S = S + 2 * a; // Multiply by 2 because we want sin^2(x)

        // Print the penultimate and the last terms
        if (k == 499) {
            printf("x=%.2Lf\ta%d=%.2Lf\tS%d=%.2Lf\n", x, k, a, k, S);
        }
        if (k == 500) {
            printf("x=%.2Lf\ta%d=%.2Lf\tS%d=%.2Lf\n", x, k, a, k, S);
        }
        k++;
    }

    return S;
}

int main() {
    long double x, y, yy;

    printf("Calculation of sin^2(x): \nEnter the value of x: ");
    scanf("%Lf", &x);

    y = sin(x) * sin(x);
    printf("Standard function sin^2(%.2ld)=%.2ld\n", x, y);

    yy = lietotaja_sinuss_kvadrats(x);
    printf("Taylor series sin^2(%.2Ld) with sum=%.2Ld\n", x, yy);

    // Your ASCII art and additional output can remain here
    // ...

    return 0;
}

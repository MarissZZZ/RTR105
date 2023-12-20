#include <stdio.h>
#include <math.h>

double f(double x); 
double rectangleRule(double a, double b, int n);

int main() {
    double a, b;
    int n;

    printf("\nTaisnsturu metode\n");
    printf("---------------\n");

    // Dialogue with the user to obtain the value of a
    printf("Enter the lower limit of integration (a): ");
    scanf("%lf", &a);

    // Dialogue with the user to obtain the value of b
    printf("Enter the upper limit of integration (b): ");
    scanf("%lf", &b);

    // Dialogue with the user to obtain the value of precision
    printf("Enter the number of rectangles for approximation (precision): ");
    scanf("%d", &n);

    // Calculate and display the value of the area
    double area = rectangleRule(a, b, n);
    printf("The approximate area under the curve sin^2(x) from %.2f to %.2f is: %.10f\n", a, b, area);

    return 0;
}

// Function for sin^2(x)
double f(double x) {
    return sin(x) * sin(x);
}

// Function to implement the rectangle rule
double rectangleRule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;

    for (int i = 0; i < n; i++) {
        double x = a + i * h + h / 2;
        sum += h * f(x);
    }

    return sum;
}

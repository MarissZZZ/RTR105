#include <stdio.h>
#include <math.h>

double lietotaja_sinuss_kvadrats(double x) {
    double a, S;
    int k = 1;
    a = (pow(-1, k+1) * 2 * x * x) / (1. * 2);
    S = a;
    printf("%.2f\t%8.2f\t%8.2f\n", x, a, S);

    while (k < 3) {
        k++;
        a = (a * (-2) * x * x) / (k * ((2*k)-1));
        S = S + a;
        printf("%.2f\t%8.2f\t%8.2f\n", x, a, S);
    }
    return S;
}

void main() {
    double x = 1.57079633, y, yy;

    y = sin(x) * sin(x);
    printf("Standard function: y=sin(%.2f)*sin(%.2f)=%.2f\n", x, x, y);

    yy = lietotaja_sinuss_kvadrats(x);
    printf("User-defined function: y=sinuss_kvadrats(%.2f)*sinuss_kvadrats(%.2f)=%.2f\n", x, x, yy);

}

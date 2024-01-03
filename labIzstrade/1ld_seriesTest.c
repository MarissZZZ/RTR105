#include <stdio.h>
#include <math.h>

double lietotaja_sinuss_kvadrats(double x) {
    double a, S;
    int k = 1;
    a = (pow(-1, k+1) * 2 * x * x) / (1. * 2);
    S = a;
    printf("%.2f\t%8.2f\t%8.2f\n", x, a, S);

    while (k < 500) {
        k++;
        a = (a * (-2) * x * x) / (k * ((2*k)-1));
        S = S + a;
        printf("%.2f\t%8.2e\t%8.2f\n", x, a, S);
    }
    return S;
}

void main() {
    double x = 1.57079633, y, yy;

    y = sin(x) * sin(x);
    printf("Standarta funkcija: y=sin(%.2f)*sin(%.2f)=%.2f\n", x, x, y);

    yy = lietotaja_sinuss_kvadrats(x);
    printf("Lietotaaja funkcija: y=sinuss_kvadrats(%.2f)*sinuss_kvadrats(%.2f)=%.2f\n", x, x, yy);

    printf("\n%21s\n", "500");
    printf("%40s\n", "————————");
    printf("%17s%11s%7s%8s\n", "\\", "k+1", "2*k", "2*k-1");
    printf("%6s%12s%20s\n", "2", "\\", "(-1)  *  x  *  2");
    printf("y=sin(%.2Lf)=%.2Lf", x, y);
    printf("%2s%2s%50s\n", "=", ">", "————————————————");
    printf("%18s%15s\n", "/", "(2 * k)!");
    printf("%17s\n", "/");
    printf("%40s\n", "————————");
    printf("\n%21s\n", "k=1");
    printf("\n");
    printf("%38s\n", "2");
    printf("%37s\n", "(-2) * x");
    printf("rekurences reizinatajs: ");;
    printf("%50s\n", "————————————————");
    printf("%42s\n", "k * (2 * k - 1)");
    printf("\n");   

}
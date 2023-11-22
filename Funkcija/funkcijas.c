#include <stdio.h>
#include <math.h>

void main() {
    double x = 2.05, y, a1, a2, a3, S1, S2, S3;

    y = sin(x) * sin(x);
    printf("y=sin(%.2f)*sin(%.2f)=%.2f\n", x, x, y);

    a1 = (pow(-1, 2) * 2 * x * x) / 2;
    S1 = a1;
    printf("%.2f\t%8.2f\t%8.2f\n", x, a1, S1);

    a2 = pow(-1, 3) * 2 * pow(x, 2) / 6;
    S2 = a1+a2;
    printf("%.2f\t%8.2f\t%8.2f\n", x, a2, S2);

    a3 = pow(-1, 4) * 2 * pow(x, 2) / 15;
    S3 = a1+a2+a3;
    printf("%.2f\t%8.2f\t%8.2f\n", x, a3, S3);
}

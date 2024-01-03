#include <stdio.h>
#include <math.h>


double lietotaja_sinuss_kvadrats(long double x) {
    long double a, S;
    int k = 1;
    a = (pow(-1, k+1) * 2 * x * x) / (1. * 2);
    S = a;
    printf("x=%.2Lf\ta1  =%.30Lf\tS1=%.30Lf\n", x, a, S);

    while (k < 500) {
        k++;
        a = (a * (-2) * x * x) / (k * ((2*k)-1));
        S = S + a;
        if (k == 499) {
            printf("x=%.2Lf\ta%d=%.30Le\tS%d=%.30Lf\n", x, k, a, k, S);
        }
        if (k == 500) {
            printf("x=%.2Lf\ta%d=%.30Le\tS%d=%.30Lf\n", x, k, a, k, S);
        }
    }

    return S;
}

int main() {
    long double x, y, yy; // = 1.57079633

    printf("Sin * sin aprekinasana: \n");
    printf("Ievadi argumentu x: \n");
    scanf("%Lf", &x);

    y = sin(x) * sin(x);
    printf("Standarta funkcija: y=sin(%.2Lf)*sin(%.2Lf)=%.30Lf\n", x, x, y);

    yy = lietotaja_sinuss_kvadrats(x);
    printf("y=sinuss(%.2Lf)*sinuss(%.2Lf) ar summu=%.30Lf\n", x, x, yy);

    printf( "                 500                               \n"
            "                ------                             \n"
            "                \\             k+1   2*k   2*k-1   \n"
            "   2             \\        (-1)  *  x  *  2        \n"
            "sin(%.2Lf) = %.2Lf = >  -------------------------- \n"
            "                  /              (2 * k)!          \n"
            "                 /                                 \n"
            "                ------                             \n"
            "                 k = 1                             \n", x, y);


    printf( "                               2    2       \n"
            "                            (-2) * x        \n"
            "rekurences reizinatajs: ------------------- \n"
            "                          k * (2 * k - 1)   \n" );

}
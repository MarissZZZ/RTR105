#include <stdio.h>
#include <math.h>

// Funkcija, lai aprēķinātu sin(x)^2
double f(double x) {
    return sin(x) * sin(x);
}

// Taisnstūra metode 
double rectangle_method(double a, double b, int n) {
    double h = (b - a) / n;
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        area += f(a + i * h + h / 2);
    }
    return area * h;
}

// Trapeces metode 
double trapezoidal_method(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

// Simpsona metode
double simpsons_method(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += (i % 2 == 0 ? 2 : 4) * f(x);
    }
    return sum * h / 3;
}

int main() {
    double a, b;
    int n;
    
    // ievada vērtības integrācijas robežām un precizitātei
    printf("Ievadiet integrācijas apakšējo robežu [a-b] (a): ");
    scanf("%lf", &a);
    printf("Ievadiet integrācijas augšējo robežu [a-b] (b): ");
    scanf("%lf", &b);
    printf("Ievadiet dalījumu skaitu (precizitāte): ");
    scanf("%d", &n);
    
    // Aprēķina un izvada rezultātus, izmantojot dažādas metodes
    printf("Taisnstūra metode: %f\n", rectangle_method(a, b, n));
    printf("Trapeces metode: %f\n", trapezoidal_method(a, b, n));
    printf("Simpsona metode: %f\n", simpsons_method(a, b, n));
    
    return 0;
}

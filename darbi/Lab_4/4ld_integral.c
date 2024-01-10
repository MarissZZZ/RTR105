#include <stdio.h>
#include <math.h>

// Funkcija, lai aprēķinātu sin(x)^2
double f(double x) {
    return sin(x) * sin(x);
}

// Taisnstūra metode 
double taisnstura_metode(double a, double b, int n) {
    double h = (b - a) / n; // Aprēķina soli (h), kas ir intervāla [a, b] dalījums ar dalījumu skaitu (n)
    double area = 0.0; // Sākotnējā laukuma vērtība
    for (int i = 0; i < n; i++) {
        area += f(a + i * h + h / 2); // Pievieno laukumam funkcijas vērtību katrā taisnstūrī, kas aprēķināta tā vidū
    }
    return area * h; // Rezultāts tiek iegūts, reizinot summēto laukumu ar soli (h)
}

// Trapeces metode 
double trapeces_metode(double a, double b, int n) {
    double h = (b - a) / n; // Aprēķina soli (h)
    double sum = (f(a) + f(b)) / 2.0; // Sākuma un beigu punktu vidējā vērtība ir pirmā un pēdējā trapeces augstums
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h); // Summē funkcijas vērtības katrā starppunktu, kas ir trapeces augstumi
    }
    return sum * h; // Reizinot summu ar soli, iegūst tuvinājumu integrālim
}

// Simpsona metode
double simpsona_metode(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b); // Sākuma un beigu punktu summa
    for (int i = 1; i < n; i++) {
        double x = a + i * h; // Aprēķina katru x vērtību intervālā
        sum += (i % 2 == 0 ? 2 : 4) * f(x); // Pāra i vērtībām pievieno 2*f(x), nepāra - 4*f(x) (Simpsona metodes specifika)
    }
    return sum * h / 3; // Gala rezultāts iegūts, reizinot summu ar h/3
}

int main() {
    double a, b; // Definē mainīgos a un b integrācijas robežām
    int n; // Definē mainīgo n, kas ir dalījumu skaits
    
    // ievada vērtības integrācijas robežām un precizitātei
    printf("Ievadiet integrācijas apakšējo robežu [a-b] (a): ");
    scanf("%lf", &a);
    printf("Ievadiet integrācijas augšējo robežu [a-b] (b): ");
    scanf("%lf", &b);
    printf("Ievadiet dalījumu skaitu (precizitāte): ");
    scanf("%d", &n);
    
    // Aprēķina un izvada rezultātus, izmantojot dažādas metodes
    printf("Taisnstūra metode: %f\n", taisnstura_metode(a, b, n));
    printf("Trapeces metode: %f\n", trapeces_metode(a, b, n));
    printf("Simpsona metode: %f\n", simpsona_metode(a, b, n));
    
    return 0;
}

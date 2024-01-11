#include <stdio.h>
#include <math.h>

float sin_kvadrata(float x, float A);

int main() {

    printf("sin(x)^2-A sakņu meklētājs (Dihotomijas metode)\n");
    printf("---------------------------------------------------\n");

    float a, x, delta_x, b, A, fa, fb;
    int itera = 1;

    // ievada intervāla sākuma un beigu vērtības
    printf("Lūdzu ievadiet mazākās robežas 'a' vērtību: ");
    scanf("%f", &a);
    printf("Lūdzu ievadiet lielākās robežas 'b' vērtību: ");
    scanf("%f", &b);
    printf("Saknes meklēšanas intervāls [%.3f;%.3f]\n", a, b);
    printf("---------------------------------------------------\n");

    // ievada nobīdes vērtību un precizitātes vērtību
    printf("Lūdzu ievadiet nobīdes A vērtību (funkcija tiks bīdīta uz leju vai augšu) A = ");
    scanf("%f", &A);
    printf("Lūdzu ievadiet precizitātes vērtību (piem. 0.001): ");
    scanf("%f", &delta_x);
    printf("---------------------------------------------------\n");

    // Tiek aprēķinātas funkcijas vērtības intervāla galapunktos
    fa = sin_kvadrata(a, A);
    fb = sin_kvadrata(b, A);

    // Pārbauda, vai ir iespējams atrast sakni dotajā intervālā
    if ((A == 0 && A == 1 && fa * fb < 0) || (A != 0 && A != 1 && fa * fb > 0)) {
        printf("Intervālā [%.3f;%.3f] sin(x)^2 - %.3f nav sakņu vai ir pāra skaits sakņu\n", a, b, A);
        return 1;
    }

    // Iteratīvi meklē sakni intervālā
    x = a;
    while (x < b) {
        x = x + delta_x;

        // Pārbauda, vai tuvums saknei ir mazāks par delta_x
        if ((sin_kvadrata(x, A) < delta_x) && (sin_kvadrata(x, A) > -delta_x)) {
            printf("Sakne atrodas tuvu pie vērtībām: \n\t x = %.30f\n", x);
            printf("\t sin(%.4f)^2 - %.5f = %.30f\n", x, A, sin_kvadrata(x, A));
            printf("Vajadzīgais iterāciju skaits pie precizitātes %.6f ir %d", delta_x, itera);
            return 0;
        }
        itera++;
    }

    printf("Lūdzu samazināt precizitāti, lai spētu atrast tuvināto saknes vērtību\n"); // Ziņo par nepieciešamību samazināt precizitāti, ja sakne netika atrasta
    return 1;
}

// Definē funkciju sin_kvadrata

float sin_kvadrata(float x, float A) {
  return sin(x) * sin(x) - A; // Atgriež sin(x)^2 - A vērtību
}
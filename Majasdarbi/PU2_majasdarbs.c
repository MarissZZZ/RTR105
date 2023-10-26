#include <stdio.h>

int main() {
    int skaitlis;
    char i;

    do {
        printf("Ievadiet naturālu decimālu skaitli (1-255): "); //LAI IEVADITAIS SKAITLIS BUTU NATURALS
        if (scanf("%d", &skaitlis) != 1 || skaitlis <= 0 || skaitlis > 255) {
            printf("Lūdzu ievadiet naturālu decimālu skaitli no 1 līdz 255.\n");
            while (getchar() != '\n');
            skaitlis = -1;  //atgriez lai turpinatos loops
        }
    } while (skaitlis <= 0 || skaitlis > 255);

    unsigned char skaitlis_unsigned = (unsigned char)skaitlis;

    printf("Ievadītais skaitlis bināri: ");
    for (i = 7; i >= 0; i--) {
        char biti = (skaitlis_unsigned >> i) & 1;
        if (biti) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");

    return 0;
}

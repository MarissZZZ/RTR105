#include <stdio.h>

int main() {
    unsigned char skaitlis;
    char i;

    printf("Ievadiet naturālu decimālu skaitli: ");
    scanf("%hhu", &skaitlis);

    if (skaitlis < 0) {
        printf("Lūdzu ievadiet naturālu decimālu skatili (pozitīvu).\n");
        return 1;
    }

    printf("Ievadītais skaitlis bināri: ");
    for (i = 7; i >= 0; i--) {
        char biti = (skaitlis >> i) & 1;
        if (skaitlis & biti) printf("1");
        else printf("0");
    }
    printf("\n");

    return 0;
}

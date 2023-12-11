#include <stdio.h>

int main() {

    int skaitlis;
    char datuTips;

    printf("Ievadiet naturalu skaitli: "); // lietotaja ievade
    scanf("%d", &skaitlis);

    if (skaitlis < 0) { // parbuada vai ir ievadits naturals skaitlis
        printf("Faktoriāls nav definets negativiem skaitliem.\n"); 
        return 1;
    } else {
        printf("Izvelieties datu tipu (c - char, i - int, l - long long): ");
        scanf(" %c", &datuTips);
    }
    

    switch(datuTips) {
        case 'c': {
            char rezultats = 1;
            for (char i = 1; i <= skaitlis; ++i) {
                char parbRezultats = rezultats * i;
                if (parbRezultats / i != rezultats) { // Overflows
                    printf("Error: nevar aprekinat faktorialu ar char datu tipu.\n");
                    return 1;
                }
                rezultats = parbRezultats;
            }
            printf("Faktorials izmantojot datu tipu char: %hhd\n", (char)rezultats);
            break;
        }
        case 'i': {
            int rezultats = 1;
            for (int i = 1; i <= skaitlis; ++i) {
                int parbRezultats = rezultats * i;
                if (parbRezultats / i != rezultats) { // Overflows
                    printf("Error: nevar aprekinat faktorialu ar int datu tipu.\n");
                    return 1;
                }
                rezultats = parbRezultats;
            }
            printf("Faktorials izmantojot datu tipu int: %d\n", (int)rezultats);
            break;
        }
        case 'l': {
            long long rezultats = 1;
            for (long long i = 1; i <= skaitlis; ++i) {
                long long parbRezultats = rezultats * i;
                if (parbRezultats / i != rezultats) { // Overflows
                    printf("Error: nevar aprekinat faktorialu ar long long datu tipu.\n");
                    return 1;
                }
                rezultats = parbRezultats;
            }
            printf("Faktorials izmantojot datu tipu long long: %lld\n", rezultats);
            break;
        }
        default:
            printf("Nederiga datu tipa izvele. Ludzu, izvelieties c, i vai l.\n");
    }

    return 0;
}

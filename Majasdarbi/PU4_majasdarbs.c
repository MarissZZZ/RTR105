#include <stdio.h>

// Naturals skaitlis ir vesels skaitlis un lielaks par 0

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
    
    switch(datuTips) { // izpilda atbilstosi no ievaditaa
        case 'c': {
            char rezultats = 1;
            char i = 1;
            while(i <= skaitlis) {
                char parbRezultats = rezultats * i;
                if (parbRezultats / i != rezultats) { // Overflows
                    printf("Error: nevar aprekinat faktorialu ar char datu tipu.\n");
                    return 1;
                }
                rezultats = parbRezultats;
                i++;
            }
            printf("Faktorials izmantojot datu tipu char: %hhd\n", rezultats);
            break;
        }
        case 'i': {
            int rezultats = 1;
            int i = 1;
            while(i <= skaitlis) {
                int parbRezultats = rezultats * i;
                if (parbRezultats / i != rezultats) { // Overflows
                    printf("Error: nevar aprekinat faktorialu ar int datu tipu.\n");
                    return 1;
                }
                rezultats = parbRezultats;
                i++;
            }
            printf("Faktorials izmantojot datu tipu int: %d\n", rezultats);
            break;
        }
        case 'l': {
            long long rezultats = 1;
            long long i = 1;
            while(i <= skaitlis) {
                long long parbRezultats = rezultats * i;
                if (parbRezultats / i != rezultats) { // Overflows
                    printf("Error: nevar aprekinat faktorialu ar long long datu tipu.\n");
                    return 1;
                }
                rezultats = parbRezultats;
                i++;
            }
            printf("Faktorials izmantojot datu tipu long long: %lld\n", rezultats);
            break;
        }
        default:
            printf("Nederiga datu tipa izvele. Ludzu, izvelieties c, i vai l.\n");
    }

    return 0;
}

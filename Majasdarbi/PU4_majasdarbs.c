#include <stdio.h>

// Naturals skaitlis ir vesels skaitlis un lielaks par 0

long long Faktorials(int skaitlis, char datuTips);

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

    switch (datuTips) { // parbauda datu tipa ievadi
        case 'c':
        case 'i':
        case 'l':
            break;
        default:
            printf("Nederiga datu tipa izvele. Ludzu, izvelieties c, i vai l.\n");
            return 1;
    }

    long long rezultats = Faktorials(skaitlis, datuTips); //funckija faktoriala aprekinasanai

    if (rezultats == -1) {
        printf("Kluda: nevar aprekinat faktorialu ar atlasito datu tipu.\n");
    } else {
        
        switch (datuTips) { // izdrukat rezultatu, balstoties uz izveleto datu tipu
            case 'c':
                printf("Faktorials no %d ar datu tipu %char: %hhd\n", skaitlis, datuTips, (char)rezultats);
                break;
            case 'i':
                printf("Faktorials no %d ar datu tipu %cnt: %d\n", skaitlis, datuTips, (int)rezultats);
                break;
            case 'l':
                printf("Faktorials no %d ar datu tipu %cong long: %lld\n", skaitlis, datuTips, rezultats);
                break;
        }
    }

    return 0;
}

long long Faktorials(int skaitlis, char datuTips) {

    long long rezultats = 1;

    while (skaitlis > 1) {
        switch (datuTips) {
            case 'c':
                if (rezultats > 127 / skaitlis) { // char Max
                    return -1;  // Error: Overflow 
                }
                rezultats *= (char)skaitlis;
                break;
            case 'i':
                if (rezultats > 2147483647 / skaitlis) { // int Max
                    return -1;  // Error: Overflow
                }
                rezultats *= (int)skaitlis;
                break;
            case 'l':
                if (rezultats > 9223372036854775807LL / skaitlis) { // long long Max
                    return -1;  // Error: Overflow
                }
                rezultats *= (long long)skaitlis;
                break;
        }

        skaitlis--;
    }

    return rezultats;
}

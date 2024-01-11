// iet cauri no lietotaja ievadita teikuma un atrod simbolu ar vismazako ascii kodu un ar lielako izmantokot flag, atstarpes un punktus neņem vērā
// burtu ar videjo vertibu char - burtam, summai ir int, nanoapaļo un atbilstoši parada simbolu kads sanak
// jaatrod mediana (sakuma jasakarto atbilstošā secībā)
// atrod modu. kurs simbols atkartojas, (katrs simbols, cik reizes atkartojas) secibu caurskata vienu reizi
// burbuļa metode v1 > v2; v1 < v2, maina katrus divus elementus un domā vai apmainīt vai nē no elementu rindas (8 5) 25 --> 5 (8 25)
// burbuļa metode ir jaimplimentē pašiem, neizmantot gatavas funkcijas
// vins iet katrus 2 un iet talak
// pec pirma apļa pedejais elemnts bus vislielakais, sanak par vienu mazak var parbaudit
// pec otra pedejie 2

// ar gnuplot jaattelo histofgramma ar cik katrs burts tika attēlots


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // Nepieciešams priekš isalpha un tolower

#define MAX_STRING_LENGTH 256

//BUBBLE SORTING METODEI IZMANTOTIE AVOTI:
//https://www.geeksforgeeks.org/bubble-sort-in-cpp/
//https://www.softwaretestinghelp.com/bubble-sort/

// Funkcija, lai veiktu burbuļu-metodes kārtošanu ASCII vērtību un atbilstošo rakstzīmju masīvam
void bubble_sort(int ascii_vertibas[], char teksts[], int n) {
    int i, j, temp;
    char tempChar;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (ascii_vertibas[j] > ascii_vertibas[j+1]) {
                // Mainīt ASCII vērtības vietām
                temp = ascii_vertibas[j];
                ascii_vertibas[j] = ascii_vertibas[j+1];
                ascii_vertibas[j+1] = temp;

                // Mainīt atbilstošās rakstzīmes vietām
                tempChar = teksts[j];
                teksts[j] = teksts[j+1];
                teksts[j+1] = tempChar;
            }
        }
    }
}

// Funkcija, lai atrastu masīva mediānu
double find_mediana(int arr[], int n) {
    if (n % 2 == 0) {
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    }
    return arr[n/2];
}

// Funkcija, lai atrastu masīva modu
int find_moda(int arr[], int n, int* moda, int* moda_skaits) {
    int max_skaits = 0;
    *moda_skaits = 0;
    
    for (int i = 0; i < n; ++i) {
        int count = 1;
        while ((i + count) < n && arr[i] == arr[i + count]) {
            ++count;
        }
        
        if (count > max_skaits) {
            max_skaits = count;
            *moda = arr[i];
            *moda_skaits = 1;
        } else if (count == max_skaits) {
            if (*moda_skaits == 1 && *moda != arr[i]) {
                // Mēs esam atraduši vēl vienu modu ar tādu pašu skaitu
                *moda_skaits += 1;
            }
        }
        
        i += count - 1; // Pāriet uz nākamo atšķirīgo vērtību
    }
    
    return max_skaits;
}

int main() {
    char teksts[MAX_STRING_LENGTH];
    int burtu_skaits[128] = {0}; // ASCII tabulas burti

    printf("Ievadiet tekstu: ");
    fgets(teksts, MAX_STRING_LENGTH, stdin);
    teksts[strcspn(teksts, "\n")] = 0; // Noņemt jaunas rindas rakstzīmi

    int n = strlen(teksts);
    int ascii_vertibas[n];
    int summa = 0;
    int min = 127, max = 0;

    // Skaitīt katru burtu
    for (int i = 0; teksts[i] != '\0'; ++i) {
        if (isalpha(teksts[i])) {
            int index = tolower(teksts[i]) - 'a';
            burtu_skaits[index]++;
        }
    }

    printf("\nRakstzīmes un to ASCII vērtības:\n");
    for (int i = 0; i < n; ++i) {
        ascii_vertibas[i] = (int)teksts[i];
        printf("%c: %d\n", teksts[i], ascii_vertibas[i]);
        summa += ascii_vertibas[i];
        if (ascii_vertibas[i] < min) min = ascii_vertibas[i];
        if (ascii_vertibas[i] > max) max = ascii_vertibas[i];
    }
    
    double videjais = (double)summa / n;
    
    // Izmantot burbuļmetodes kārtošanu, lai kārtotu ASCII vērtības mediānas un modas aprēķinam
    bubble_sort(ascii_vertibas, teksts, n);
    
    double mediana = find_mediana(ascii_vertibas, n);
    
    int moda, moda_skaits;
    int max_moda_skaits = find_moda(ascii_vertibas, n, &moda, &moda_skaits);
    
    printf("\nStatistika:\n");
    printf("Mazākā ASCII vērtība: %d\n", min);
    printf("Lielākā ASCII vērtība: %d\n", max);
    printf("Vidējā aritmētiskā ASCII vērtība: %.2f\n", videjais);
    printf("Mediānas ASCII vērtība: %.2f\n", mediana);
    printf("Modas ASCII vērtība: %d (occurs %d times)\n", moda, max_moda_skaits);
    if (moda_skaits > 1) {
        printf("Ir vairāk nekā viena moda.\n");
    }
    
    printf("\nSakārtotas rakstzīmes un to ASCII vērtības:\n");
    for (int i = 0; i < n; ++i) {
        printf("%c: %d\n", teksts[i], ascii_vertibas[i]);
    }

    // Saglabāt datus failā
    FILE *file = fopen("burtu_skaits.dat", "w");
    for (int i = 0; i < 26; ++i) {
        if (burtu_skaits[i] > 0) {
            fprintf(file, "%c %d\n", 'a' + i, burtu_skaits[i]);
        }
    }
    fclose(file);

    return 0;

}

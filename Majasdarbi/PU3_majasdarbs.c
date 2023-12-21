#include <stdio.h>

int main() {
    
    char burts1, burts2, burts3;

    printf("Ievadiet pirmo burtu: "); // Ievada pirmo burtu
    scanf(" %c", &burts1); // ievade ir viena rakstzīme un ieraksta to vērtību --> burts1

    printf("Ievadiet otro burtu: "); // Ievada otro burtu
    scanf(" %c", &burts2);

    printf("Ievadiet tresho burtu: "); // Ievada treso burtu
    scanf(" %c", &burts3);

    char order;

    printf("Ievadiet 'A' prieksh alfabeeta seciibas vai 'P' - preteeji ievadiitaijai seciibai: "); // Izveelas secibu
    scanf(" %c", &order);

    if (order == 'A' || order == 'a') { // Alfabeta seciba
        if (burts1 <= burts2 && burts1 <= burts3) { // Alfabeta seciba
            printf("%c ", burts1);
            if (burts2 <= burts3) {
                printf("%c %c\n", burts2, burts3);
            } else {
                printf("%c %c\n", burts3, burts2);
            }
        } else if (burts2 <= burts1 && burts2 <= burts3) {
            printf("%c ", burts2);
            if (burts1 <= burts3) {
                printf("%c %c\n", burts1, burts3);
            } else {
                printf("%c %c\n", burts3, burts1);
            }
        } else {
            printf("%c ", burts3);
            if (burts1 <= burts2) {
                printf("%c %c\n", burts1, burts2);
            } else {
                printf("%c %c\n", burts2, burts1);
            }
        }
    } else if (order == 'P' || order == 'p') {
        if (burts1 >= burts2 && burts1 >= burts3) { // Preteji alfabeta secibai
            printf("%c ", burts1);
            if (burts2 >= burts3) {
                printf("%c %c\n", burts2, burts3);
            } else {
                printf("%c %c\n", burts3, burts2);
            }
        } else if (burts2 >= burts1 && burts2 >= burts3) {
            printf("%c ", burts2);
            if (burts1 >= burts3) {
                printf("%c %c\n", burts1, burts3);
            } else {
                printf("%c %c\n", burts3, burts1);
            }
        } else {
            printf("%c ", burts3);
            if (burts1 >= burts2) {
                printf("%c %c\n", burts1, burts2);
            } else {
                printf("%c %c\n", burts2, burts1);
            }
        }
    } else {
        printf("Kluuda. Luudzu ievadiet 'A' vai 'P'.\n"); // Ja neieraksta A vai P
    }

    return 0;
}
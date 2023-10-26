#include <stdio.h>

//https://stackoverflow.com/questions/40554617/while-getchar-n

int main() {
    
    long long int n1, n2, rezultats; //tā kā rezultāts pārsniedz skaitli, ko var saglabāt 32-bitu veselā skaitlī, tad jāizmanto 64-bitu vesela skaitļa datu tips

    while (1) { // bezgalīgs loops līdz ievada pareizo vērtību un izpildās break
        printf("Ievadiet pirmo skaitli (400000): ");
        if (scanf("%lld", &n1) == 1 && n1 == 400000) { //"%d" - tiek sagaidīts vesels skaitlis, &n1 - vieta, kur tiks saglabāts skenētais veselais skaitlis.
            break;  // iziet no loopa, ja ir ievadīts skaitlis 400000
        }
        printf("Nepareizi ievadīts. Lūdzu ievadiet 400000.\n");
        while (getchar() != '\n'); // ja ieraksta burtu, lai nebūtu loops	
    }

    while (1) {
        printf("Ievadiet otro skaitli (100000): ");
        if (scanf("%lld", &n2) == 1 && n2 == 100000) {
            break; 
        }
        printf("Nepareizi ievadīts. Lūdzu ievadiet 100000.\n");
	while (getchar() != '\n'); // ja ieraksta burtu, lai nebūtu loops
    }

    rezultats = n1 * n2; //reizinājums

    printf("Abu skaitļu reizinājums ir: %lld\n", rezultats);

    return 0;
}

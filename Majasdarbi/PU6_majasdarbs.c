#include <stdio.h>

// Funkciju dekleresana
void Hello();
void Skaitlis(int num);
int Atgriez();
int Saskaitisana(int a, int b);

int main() {
    // funkcija bez argumentiem un bez return
    Hello();

    // funkcija ar argumentiem un bez return
    Skaitlis(10);

    // funkcija bez argumentiem un ar return
    int a = Atgriez();
    printf("Atgrieztaa vertiba ir: %d\n", a);

    // funkcija ar argumentiem un ar return
    int summa = Saskaitisana(3, 7);
    printf("summa: 3 + 7 = %d\n", summa);

    return 0;
}

void Hello() {
    printf("Hello World!\n");
}

void Skaitlis(int sk) {
    printf("Skaitlis ir: %d\n", sk);
}

int Atgriez() {
    return 5;
}

int Saskaitisana(int a, int b) {
    return a + b;
}

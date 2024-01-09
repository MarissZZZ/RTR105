#undef __STRICT_ANSI__

#include <math.h>
#include <stdio.h>

float input(const char *ievade)
{
    float vertiba = 0;
    printf("%s", ievade);
    scanf("%f", &vertiba);
    return vertiba;
}

float modified_sin_kvadrats(float x, float A)
{
    return pow(sin(x), 2) - A;
}

int main()
{
    float a = input("Ludzu ievadiet a - apaksejo vertibu intervala:\n");
    float b = input("Ludzu ievadiet b - augsejo vertibu intervala:\n");
    const float c = input("Ludzu ievadiet c - nobiides vertibu:\n");
    const float delta = input("Ludzu ievadiet precizitati deltai (piem. 0.0001):\n");

    //float funka, funkb;

    const float sakumvert = modified_sin_kvadrats(a, c);

    //unka = sin(x) * sin(x) - A; 

    int i = 0;

    if ((modified_sin_kvadrats(a, c) * modified_sin_kvadrats(b, c)) < 0)
    {
        printf("Nav saknes sin(x)^2, c = %.3f intervalaa [%.3f;%.3f]\n", c, a, b);
        return 0;
    }

    float x = 0;
    while ((b - a) > delta)
    {
        i++;
        x = (a + b) / 2;
        if (sakumvert  * modified_sin_kvadrats(x, c) >  0)
        {
            a = x;
        }
        else
        {
            b = x;
        }
    }

    printf("\n");
    printf("Iteraciju skaits, lai sasniegtu ievadito precizitati: %d\n", i);
    printf("Sakne atrodas pie x=%.6f, jo sin(%.6f)^2 ir %.6f\n", x, x, modified_sin_kvadrats(x, c));

    return 0;
}

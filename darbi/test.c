#undef __STRICT_ANSI__

#include <math.h>
#include <stdio.h>

float input(const char *vertiba)
{
    float value = 0;
    printf("%s", vertiba);
    scanf("%f", &value);
    return value;
}

float modified_sin_kvadrats(float x, float A)
{
    return sin(x) * sin(x) - A;
}

int main()
{
    float a = input("Ludzu ievadiet a - apaksejo vertibu intervala:\n");
    float b = input("Ludzu ievadiet b - augsejo vertibu intervala:\n");
    const float c = input("Ludzu ievadiet c - nobiides vertibu [0, 1]:\n");
    const float delta = input("Ludzu ievadiet precizitati deltai (piem. 0.0001):\n");

    const float sakumvert = modified_sin_kvadrats(a, c);

    int i = 0;

    if (modified_sin_kvadrats(a, c) * modified_sin_kvadrats(b, c) > 0)
    {
        printf("Nav saknes sin(x)^2, c = %.3f intervalaa [%.3f;%.3f]\n", c, a, b);
        return 0;
    }

    float x = 0;
    while ((b - a) > delta)
    {
        i++;
        x = (a + b) / 2;
        if (sakumvert * modified_sin_kvadrats(x, c) > 0)
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
    printf("Sakne ir, kad x=%.6f, sin(%.6f)^2 - %.6f=%.6f\n", x, x, c, modified_sin_kvadrats(x, c));

    return 0;
}

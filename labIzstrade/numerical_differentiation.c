
#undef __STRICT_ANSI__

#include <stdio.h>
#include <math.h>

// Funkcija, lai aprēķinātu sin^2(x)
float sin_kvadrats(float x) {
    return pow(sin(x), 2);
}

// sin^2(x) pirmais analītiskais atvasinājums: 2sin(x)cos(x)
float pirmais_analit(float x) {
    return 2 * sin(x) * cos(x);
}

// sin^2(x) otrais analītiskais atvasinājums: 2cos^2(x) - 2sin^2(x)
float otrais_analit(float x) {
    return 2 * pow(cos(x), 2) - 2 * sin_kvadrats(x);
}

// Pirmā atvasinājuma tiešās atšķirības aproksimācija
float pirmais_parnest(float x, float delta_x) {
    return (sin_kvadrats(x + delta_x) - sin_kvadrats(x)) / delta_x;
}

// Otrā atvasinājuma tiešās atšķirības aproksimācija
float otrais_parnest(float x, float delta_x) {
    return (sin_kvadrats(x + delta_x) - 2 * sin_kvadrats(x) + sin_kvadrats(x - delta_x)) / pow(delta_x, 2);
}

int main(){
    float a, b, delta_x;
    printf("Ievadi a vērtību: ");
    scanf("%f", &a);
    printf("Ievadi b vērtību: ");
    scanf("%f", &b);
    printf("Ievadi precizitāti (delta_x): ");
    scanf("%f", &delta_x);

    FILE *file = fopen("derivative.dat", "w");
    if (file == NULL) {
        printf("Error: Nevar atvērt failu!\n");
        return 1;
    }

    fprintf(file, "\tx\t\tsin^2(x)\tsin^2'(x) a.\tsin^2'(x) par.\tsin^2''(x) a.\tsin^2''(x) par.\n");

    for(float x = a; x <= b; x += delta_x){
        // Aprēķina vērtības
        float f = sin_kvadrats(x);
        float f_vien_analit = pirmais_analit(x);
        float f_vien_parnest = pirmais_parnest(x, delta_x);
        float f_otr_analit = otrais_analit(x);
        float f_otr_parnest = otrais_parnest(x, delta_x);

        // Izdrukā konsolē
        printf("%f\t%f\t%f\t%f\t%f\t%f\n", x, f, f_vien_analit, f_vien_parnest, f_otr_analit, f_otr_parnest);

        // Ieraksta failā
        fprintf(file, "%f\t%f\t%f\t\t%f\t\t%f\t\t%f\n", x, f, f_vien_analit, f_vien_parnest, f_otr_analit, f_otr_parnest);
    }

    fclose(file);
    return 0;
}

#undef __STRICT_ANSI__

#include <stdio.h>
#include <math.h>

int main(){
    float a = 0., b = 2 * M_PI, x, delta_x = 1.e-2;
    FILE *file = fopen("derivative.dat", "w"); // Open a file for writing

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "\tx\t\tsin^2(x)\tsin^2'(x)\n"); // Write the header to the file

    for(x = a; x <= b; x += delta_x){
        float sin_squared = sin(x) * sin(x); // sin^2(x)
        float derivative = (sin(x + delta_x) * sin(x + delta_x) - sin_squared) / delta_x; // Forward difference

        // Print to console
        printf("%10.2f\t%10.2f\t%10.2f\n", x, sin_squared, derivative);

        // Write to file
        fprintf(file, "%10.2f\t%10.2f\t%10.2f\n", x, sin_squared, derivative);
    }

    fclose(file); // Close the file
    return 0;
}

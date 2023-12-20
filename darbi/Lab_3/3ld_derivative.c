#undef __STRICT_ANSI__

#include <stdio.h>
#include <math.h>

// Function to calculate sin^2(x)
float sin_squared(float x) {
    return pow(sin(x), 2);
}

// Analytical first derivative of sin^2(x): 2sin(x)cos(x)
float first_derivative_analytical(float x) {
    return 2 * sin(x) * cos(x);
}

// Analytical second derivative of sin^2(x): 2cos^2(x) - 2sin^2(x)
float second_derivative_analytical(float x) {
    return 2 * pow(cos(x), 2) - 2 * sin_squared(x);
}

// Forward difference approximation of the first derivative
float first_derivative_forward_difference(float x, float delta_x) {
    return (sin_squared(x + delta_x) - sin_squared(x)) / delta_x;
}

// Forward difference approximation of the second derivative
float second_derivative_forward_difference(float x, float delta_x) {
    return (sin_squared(x + delta_x) - 2 * sin_squared(x) + sin_squared(x - delta_x)) / pow(delta_x, 2);
}

int main(){
    float a, b, delta_x;
    printf("Enter the value for a: ");
    scanf("%f", &a);
    printf("Enter the value for b: ");
    scanf("%f", &b);
    printf("Enter the value for precision (delta_x): ");
    scanf("%f", &delta_x);

    FILE *file = fopen("derivative.dat", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "x\t\t\tsin^2(x)\tsin^2'(x) a.\tsin^2'(x) f.d.\tsin^2''(x) a.\tsin^2''(x) f.d.\n");

    for(float x = a; x <= b; x += delta_x){
        // Calculate values
        float f = sin_squared(x);
        float f_prime_analytical = first_derivative_analytical(x);
        float f_prime_forward_diff = first_derivative_forward_difference(x, delta_x);
        float f_double_prime_analytical = second_derivative_analytical(x);
        float f_double_prime_forward_diff = second_derivative_forward_difference(x, delta_x);

        // Print to console
        printf("%f\t%f\t%f\t%f\t%f\t%f\n", x, f, f_prime_analytical, f_prime_forward_diff, f_double_prime_analytical, f_double_prime_forward_diff);

        // Write to file
        fprintf(file, "%f\t%f\t%f\t%f\t%f\t%f\n", x, f, f_prime_analytical, f_prime_forward_diff, f_double_prime_analytical, f_double_prime_forward_diff);
    }

    fclose(file);
    return 0;
}

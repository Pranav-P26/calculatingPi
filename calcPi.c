#include <stdio.h>
#include <math.h>

// Defining the radius
int radius = 1;
float calculatedPi;

// Semicircle equation, which is sqrt(r^2-x^2)
double semicircle (double x) {
    return sqrt(pow(radius, 2) - pow(x, 2));
}

// Function to get the area of the semicircle
double integral (double (*func)(double), double a, double b, int n) {
    // dx, aka the step size
    double dx = (b - a) / n;
    double sum = 0;
    
    // For each step, increment the sum by evaulating the distance between each subinterval
    for (int i = 0; i < n; i++) {
        sum += semicircle(a + i * dx) + semicircle(a + (i + 1) * dx);
    }
    
    // Return the area of each trapezoid using the trapezoid rule
    return sum * dx / 2;
}

int main() {
    // Lower limit
    double a = -1;
    // Upper limit
    double b = 1;
    // Subintervals
    int n = 1000000;
    // Area of semicircle
    double result = integral(semicircle, a, b, n);
    // Area of full circle, or pi
    double calculatedPi = 2 * result;

    // Printing result
    printf("Calculated Pi: %f\n", calculatedPi);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    double A = 0.0;
    double B = 0.0;
    double C = 0.0;

    fscanf(stdin, "%lf %lf %lf", &A, &B, &C);

    fprintf(stdout, "TRIANGULO: %.3lf\n", A * C / 2.0);
    fprintf(stdout, "CIRCULO: %.3lf\n", PI * C * C);
    fprintf(stdout, "TRAPEZIO: %.3lf\n", (C * (A + B) / 2.0));
    fprintf(stdout, "QUADRADO: %.3lf\n", B * B);
    fprintf(stdout, "RETANGULO: %.3lf\n", A * B);

    return 0;
}

#include <stdio.h>

#define calculate(a, b, c) ((a * 2.0) + (b * 3.0) + (c * 5.0)) / 10

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    fscanf(stdin, "%lf%*c", &a);
    fscanf(stdin, "%lf%*c", &b);
    fscanf(stdin, "%lf%*c", &c);

    fprintf(stdout, "MEDIA = %.1lf\n", calculate(a, b, c));

    return 0;
}

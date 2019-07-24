#include <stdio.h>

#define calculate(a, b) ((a * 3.5) + (b * 7.5)) / 11

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    double a = 0.0;
    double b = 0.0;

    fscanf(stdin, "%lf%*c", &a);
    fscanf(stdin, "%lf%*c", &b);

    fprintf(stdout, "MEDIA = %.5lf\n", calculate(a, b));

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159
#define calculate(radius) 4.0/3.0 * PI * (radius * radius * radius)

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    double radius = 0.0;

    fscanf(stdin, "%lf%*c", &radius);

    fprintf(stdout, "VOLUME = %.3lf\n", calculate(radius));

    return 0;
}

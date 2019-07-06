#include <stdio.h>

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    double radius = 0.0;

    fscanf(stdin, "%lf", &radius);

    fprintf(stdout, "A=%.4lf\n", radius * radius * 3.14159);

    return 0;
}

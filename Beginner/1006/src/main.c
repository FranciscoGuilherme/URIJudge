#include <stdio.h>

#include "headers/average.h"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    input(&a, &b, &c);

    fprintf(stdout, "%s", output(average(&a, &b, &c)));

    return 0;
}

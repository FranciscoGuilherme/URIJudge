#include <stdio.h>
#include <stdlib.h>

#include "headers/average.h"

void input(double *a, double *b, double *c)
{
    fscanf(stdin, "%lf%*c", a);
    fscanf(stdin, "%lf%*c", b);
    fscanf(stdin, "%lf%*c", c);

    return;
}

double average(double *a, double *b, double *c)
{
    return calculate((*a), (*b), (*c));
}

char *output(double average)
{
    char *buffer = (char *) calloc(25, sizeof(char));

    sprintf(buffer, "MEDIA = %.1lf\n", average);

    return buffer;
}

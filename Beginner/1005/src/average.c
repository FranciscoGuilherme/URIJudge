#include <stdio.h>
#include <stdlib.h>

#include "headers/average.h"

void input(double *a, double *b)
{
    fscanf(stdin, "%lf%*c", a);
    fscanf(stdin, "%lf%*c", b);

    return;
}

double average(double *a, double *b)
{
    return calculate((*a), (*b));
}

char *output(double average)
{
    char *buffer = (char *) calloc(25, sizeof(char));

    sprintf(buffer, "MEDIA = %.5lf\n", average);

    return buffer;
}

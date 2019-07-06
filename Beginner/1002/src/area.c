#include <stdio.h>
#include <stdlib.h>

#include "headers/area.h"

void input(double *pradius)
{
    fscanf(stdin, "%lf", pradius);
}

double area(double *pradius)
{
    return (*pradius) * (*pradius) * N;
}

char *output(double area)
{
    char *buffer = (char *) calloc(1, sizeof(char) * 15);

    sprintf(buffer, "A=%.4lf\n", area);

    return buffer;
}

#include <stdio.h>
#include "headers/area.h"

void input(double *pradius)
{
    fscanf(stdin, "%lf", pradius);
}

void area(double *pradius)
{
    fprintf(stdout, "A=%.4lf\n", (*pradius) * (*pradius) * N);
}

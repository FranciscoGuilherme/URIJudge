#include <stdio.h>
#include "headers/sum.h"

void sum(void)
{
    int a = 0;
    int b = 0;

    fscanf(stdin, "%d%*c", &a);
    fscanf(stdin, "%d%*c", &b);

    fprintf(stdout, "X = %d\n", a + b);

    return;
}

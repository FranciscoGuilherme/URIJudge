#include <stdio.h>
#include <stdlib.h>

#include "headers/sub.h"

void input(int *a, int *b, int *c, int *d)
{
    fscanf(stdin, "%d%*c", a);
    fscanf(stdin, "%d%*c", b);
    fscanf(stdin, "%d%*c", c);
    fscanf(stdin, "%d%*c", d);

    return;
}

int sub(int *a, int *b, int *c, int *d)
{
    return calculate((*a), (*b), (*c), (*d));
}

char *output(int result)
{
    char *buffer = (char *) calloc(30, sizeof(char));

    sprintf(buffer, "DIFERENCA = %d\n", result);

    return buffer;
}

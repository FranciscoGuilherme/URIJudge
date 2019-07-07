#include <stdio.h>
#include <stdlib.h>

#include "headers/simple_sum.h"

void input(int *a, int *b)
{
    fscanf(stdin, "%d%*c", a);
    fscanf(stdin, "%d%*c", b);

    return;
}

int sum(int *a, int *b)
{
    return (*a) + (*b);
}

char *output(int sum)
{
    char *buffer = (char *) calloc(15, sizeof(char));

    sprintf(buffer, "SOMA = %d\n", sum);

    return buffer;
}

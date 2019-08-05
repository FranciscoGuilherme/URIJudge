/**
 * @~portuguese
 * @file sun.c
 * @author Francisco Guilherme A. S. Bessa
 * @date 2019/08/05
 * @brief
 *      - Contém a lógica de soma de dois inteiros
 */

#include <stdio.h>
#include <stdlib.h>

#include "headers/sum.h"

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

char *output(int total)
{
    char *buffer = (char *) calloc(1, sizeof(char) * 15);

    sprintf(buffer, "X = %d\n", total);

    return buffer;
}

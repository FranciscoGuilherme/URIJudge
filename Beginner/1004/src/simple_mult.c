/**
 * @~portuguese
 * @file simple_mult.c
 * @author Francisco Guilherme A. S. Bessa
 * @date 2019/08/07
 * @brief
 *      - Contém a lógica de multiplicação de dois inteiros
 *
 * @~english
 * @file simple_mult.c
 * @author Francisco Guilherme A. S. Bessa
 * @date 2019/08/07
 * @brief
 *      - Contains two integer multiplication logic
 */

#include <stdio.h>
#include <stdlib.h>

#include "headers/simple_mult.h"

void input(int *a, int *b)
{
    fscanf(stdin, "%d%*c", a);
    fscanf(stdin, "%d%*c", b);

    return;
}

int mult(int *a, int *b)
{
    return (*a) * (*b);
}

char *output(int mult)
{
    char *buffer = (char *) calloc(15, sizeof(char));

    sprintf(buffer, "PROD = %d\n", mult);

    return buffer;
}

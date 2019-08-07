/**
 * @~portuguese
 * @file average.c
 * @author Francisco Guilherme A. S. Bessa
 * @date 2019/08/07
 * @brief
 *      - Contém a lógica de cálculo da média ponderada
 *
 * @~english
 * @file average.c
 * @author Francisco Guilherme A. S. Bessa
 * @date 2019/08/07
 * @brief
 *      - Contains weighted average calculation logic
 */

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

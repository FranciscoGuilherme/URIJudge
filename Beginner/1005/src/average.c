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

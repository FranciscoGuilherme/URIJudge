/**
 * @~portuguese
 * @file area.c
 * @author Francisco Guilherme A. S. Bessa
 * @date 2019/08/07
 * @brief
 *      - Contém a lógica do cálculo da área dado o raio
 *
 * @~english
 * @file area.c
 * @author Francisco Guilherme A. S. Bessa
 * @date 2019/08/07
 * @brief
 *      - Contains the logic of calculating the area given the radius
 */

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

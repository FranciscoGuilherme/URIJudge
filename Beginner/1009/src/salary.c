/**
 * @~portuguese
 * @file salary.c
 * @author Francisco Guilherme A. S. Bessa
 * @date 2019/07/27
 * @brief
 *      - Contém a lógica de cálculo do salário de um funcionário
 *      - Manipulando os dados através de funções por responsabilidades
 */

#include <stdio.h>
#include <stdlib.h>

#include "headers/salary.h"

void input(char **name, double *number, double *sales)
{
    *name = (char *) calloc(100, sizeof(char));

    fscanf(stdin, "%s%*c", *name);
    fscanf(stdin, "%lf%*c", number);
    fscanf(stdin, "%lf%*c", sales);

    return;
}

double salary(double *number, double *sales)
{
    return calculate((*number), (*sales));
}

char *output(double salary)
{
    char *buffer = (char *) calloc(1, sizeof(char *));

    sprintf(buffer, "TOTAL = R$ %.2lf\n", salary);

    return buffer;
}

void destroy(struct employee *employee, char *buffer)
{
    free(employee);
    free(buffer);

    return;
}

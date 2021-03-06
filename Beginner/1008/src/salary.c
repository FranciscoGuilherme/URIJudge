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

void input(int *number, int *hours, double *value)
{
    fscanf(stdin, "%d%*c", number);
    fscanf(stdin, "%d%*c", hours);
    fscanf(stdin, "%lf%*c", value);

    return;
}

double salary(int *hours, double *value)
{
    return calculate((*hours), (*value));
}

char **output(int *number, double salary)
{
    char **buffer = (char **) calloc(2, sizeof(char *));

    buffer[0] = (char *) calloc(20, sizeof(char));
    buffer[1] = (char *) calloc(30, sizeof(char));

    sprintf(buffer[0], "NUMBER = %d\n", (*number));
    sprintf(buffer[1], "SALARY = U$ %.2lf\n", salary);

    return buffer;
}

void destroy(struct employee *employee, char **buffer)
{
    free(employee);
    free(buffer[0]);
    free(buffer[1]);
    free(buffer);

    return;
}

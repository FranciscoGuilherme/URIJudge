/**
 * @~portuguese
 * @file main.c
 * @author Francisco Guilherme A. S. Bessa
 * @date 2019/11/21
 * @brief
 *      - Ponto de entrada da aplicação
 */

#include <stdio.h>
#include <stdlib.h>

#include "headers/salary.h"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    char *buffer;
    struct employee *employee = calloc(1, sizeof(struct employee));

    input(
        &employee->name,
        &employee->number,
        &employee->sales
    );

    buffer = output(salary(
        &employee->number,
        &employee->sales
    ));

    fprintf(stdout, "%s", buffer);

    destroy(employee, buffer);

    return 0;
}

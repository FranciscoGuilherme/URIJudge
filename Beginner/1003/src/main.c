/**
 * @~portuguese
 * @file main.c
 * @author Francisco Guilherme A. S. Bessa
 * @date 2019/08/07
 * @brief
 *      - Ponto de entrada da aplicação
 *
 * @~english
 * @file main.c
 * @author Francisco Guilherme A. S. Bessa
 * @date 2019/08/07
 * @brief
 *      - Entrypoint
 */

#include <stdio.h>
#include <stdlib.h>

#include "headers/simple_sum.h"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    int a = 0;
    int b = 0;
    char *message = NULL;

    input(&a, &b);

    message = output(sum(&a, &b));

    fprintf(stdout, "%s", message);

    free(message);

    return 0;
}

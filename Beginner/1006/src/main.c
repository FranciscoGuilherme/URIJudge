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

#include "headers/average.h"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    char *message = NULL;

    input(&a, &b, &c);

    message = output(average(&a, &b));

    fprintf(stdout, "%s", message);

    free(message);

    return 0;
}

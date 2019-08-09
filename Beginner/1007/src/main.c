/**
 * @~portuguese
 * @file main.c
 * @author Francisco Guilherme A. S. Bessa
 * @date 2019/08/09
 * @brief
 *      - Ponto de entrada da aplicação
 *
 * @~english
 * @file main.c
 * @author Francisco Guilherme A. S. Bessa
 * @date 2019/08/09
 * @brief
 *      - Entrypoint
 */

#include <stdio.h>
#include <stdlib.h>

#include "headers/sub.h"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    char *message = NULL;

    input(&a, &b, &c, &d);

    message = output(sub(&a, &b, &c, &d));

    fprintf(stdout, "%s", message);

    free(message);

    return 0;
}

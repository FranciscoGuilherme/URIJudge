#include <stdio.h>

#include "headers/simple_sum.h"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    int a = 0;
    int b = 0;

    input(&a, &b);

    fprintf(stdout, "%s", output(sum(&a, &b)));

    return 0;
}

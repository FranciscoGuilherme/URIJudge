#include <stdio.h>

#include "headers/sub.h"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    input(&a, &b, &c, &d);

    fprintf(stdout, "%s", output(sub(&a, &b, &c, &d)));

    return 0;
}

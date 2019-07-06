#include <stdio.h>
#include "headers/area.h"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    double radius = 0.0;

    input(&radius);

    fprintf(stdout, "%s", output(area(&radius)));

    return 0;
}

#include <stdio.h>

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    int d = 0;
    float c = 0.0;

    fscanf(stdin, "%d%*c", &d);
    fscanf(stdin, "%f%*c", &c);

    fprintf(stdout, "%.3f km/l\n", d / c);

    return 0;
}
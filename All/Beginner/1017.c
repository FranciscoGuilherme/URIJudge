#include <stdio.h>

#define liters(h, km) ((h * km) / 12.0)

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    int h = 0;
    int km = 0;

    fscanf(stdin, "%d%*c", &h);
    fscanf(stdin, "%d%*c", &km);

    fprintf(stdout, "%.3f\n", liters(h, km));

    return 0;
}
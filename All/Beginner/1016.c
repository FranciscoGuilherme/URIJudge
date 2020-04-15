#include <stdio.h>

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    int km = 0;

    fscanf(stdin, "%d%*c", &km);

    fprintf(stdout, "%d minutos\n", km * 2);

    return 0;
}
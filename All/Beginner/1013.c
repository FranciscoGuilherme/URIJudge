#include <stdio.h>
#include <stdlib.h>

#define module(x, y) ((x - y > 0) ? x - y : y - x)
#define bigger(x, y) (x + y + module(x, y)) / 2

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    int a = 0;
    int b = 0;
    int c = 0;

    fscanf(stdin, "%d %d %d", &a, &b, &c);

    fprintf(stdout, "%d eh o maior\n", bigger(bigger(a, b), c));

    return 0;
}

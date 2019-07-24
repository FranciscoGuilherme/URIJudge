#include <stdio.h>

#define calculate(a, b, c, d) (a * b) - (c * d)

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    fscanf(stdin, "%d%*c", &a);
    fscanf(stdin, "%d%*c", &b);
    fscanf(stdin, "%d%*c", &c);
    fscanf(stdin, "%d%*c", &d);

    fprintf(stdout, "DIFERENCA = %d\n", calculate(a, b, c, d));

    return 0;
}

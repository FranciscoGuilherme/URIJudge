#include <stdio.h>

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argc;

    int a = 0;
    int b = 0;

    fscanf(stdin, "%d%*c", &a);
    fscanf(stdin, "%d%*c", &b);

    fprintf(stdout, "PROD = %d\n", a * b);

    return 0;
}

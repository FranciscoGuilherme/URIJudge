#include <stdio.h>
#include <stdlib.h>

#define calculate(number, sales) number + (0.15 * sales)

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    char *name = (char *) calloc(100, sizeof(char));
    double number = 0.0;
    double sales = 0.0;

    fscanf(stdin, "%s%*c", name);
    fscanf(stdin, "%lf%*c", &number);
    fscanf(stdin, "%lf%*c", &sales);

    fprintf(stdout, "TOTAL = R$ %.2lf\n", calculate(number, sales));

    return 0;
}

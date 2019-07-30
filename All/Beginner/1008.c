#include <stdio.h>

#define calculate(hours, value) hours * value

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    int number = 0;
    int hours = 0;
    double value = 0.0;

    fscanf(stdin, "%d%*c", &number);
    fscanf(stdin, "%d%*c", &hours);
    fscanf(stdin, "%lf%*c", &value);

    fprintf(stdout, "NUMBER = %d\n", number);
    fprintf(stdout, "SALARY = U$ %.2lf\n", calculate(hours, value));

    return 0;
}

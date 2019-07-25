#include <stdio.h>
#include <stdlib.h>

#include "headers/salary.h"

void input(int *number, int *hours, float *value)
{
    fscanf(stdin, "%d%*c", number);
    fscanf(stdin, "%d%*c", hours);
    fscanf(stdin, "%f%*c", value);

    return;
}

float salary(int *hours, float *value)
{
    return calculate((*hours), (*value));
}

char **output(int *number, float salary)
{
    char **buffer = (char **) calloc(2, sizeof(char *));

    buffer[0] = (char *) calloc(20, sizeof(char));
    buffer[1] = (char *) calloc(30, sizeof(char));

    sprintf(buffer[0], "NUMBER = %d\n", (*number));
    sprintf(buffer[1], "SALARY = U$ %.2f\n", salary);

    return buffer;
}

void destroy(struct employee *employee, char **buffer)
{
    free(employee);
    free(buffer[0]);
    free(buffer[1]);
    free(buffer);

    return;
}

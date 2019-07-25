#include <stdio.h>
#include <stdlib.h>

#include "headers/salary.h"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    char **buffer;
    struct employee *employee = calloc(1, sizeof(struct employee));

    input(
        &employee->number,
        &employee->hours,
        &employee->value
    );

    buffer = output(&employee->number, salary(
        &employee->hours,
        &employee->value
    ));

    fprintf(stdout, "%s", buffer[0]);
    fprintf(stdout, "%s", buffer[1]);

    destroy(employee, buffer);

    return 0;
}

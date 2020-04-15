#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define calculation(a, b) (powf(a, 2) + powf(b, 2))
#define distance(pxa, pxb, pya, pyb) sqrt(calculation(pxb - pxa, pyb - pya))

struct abscissa
{
    float a;
    float b;
};

struct ordinate
{
    float a;
    float b;
};

struct plan
{
    struct abscissa x;
    struct ordinate y;
};

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    struct plan *plan = calloc(1, sizeof(struct plan));

    fscanf(stdin, "%f %f%*c", &plan->x.a, &plan->y.a);
    fscanf(stdin, "%f %f%*c", &plan->x.b, &plan->y.b);

    fprintf(stdout, "%.4f\n", distance(
        plan->x.a,
        plan->x.b,
        plan->y.a,
        plan->y.b
    ));

    return 0;
}
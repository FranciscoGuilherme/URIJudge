#include <stdio.h>
#include <stdlib.h>

struct piece
{
    int code;
    int amount;
    float price;
};

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    short int inputs = 0;
    struct piece *pieces = (struct piece *) calloc(2, sizeof(struct piece));

    for ( ; inputs < 2; inputs++)
    {
        fscanf(stdin, "%d %d %f",
            &pieces[inputs].code,
            &pieces[inputs].amount,
            &pieces[inputs].price
        );
    }

    fprintf(stdout, "VALOR A PAGAR: R$ %.2f\n",
        (pieces[0].amount * pieces[0].price) +
        (pieces[1].amount * pieces[1].price)
    );

    return 0;
}

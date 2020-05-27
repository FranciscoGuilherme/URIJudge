#include <stdio.h>
#include <stdlib.h>

/*
 * ------------------------------------
 * ----- DEFINIÇÃO DAS ESTRUTURAS -----
 * ------------------------------------
 */

typedef struct __attribute__((__packed__)) partial
{
    unsigned int months: 5;
    unsigned int days: 5;
} partial;

typedef struct __attribute__((__packed__)) time
{
    int years;
    struct partial partial;
} time;

/*
 * ---------------------------------
 * ----- PROTÓTIPO DAS FUNÇÕES -----
 * ---------------------------------
 */

struct time *_gettime(int *);
void output(struct time *);
void destroy(struct time *);

/*
 * --------------------------------
 * ----- ROTINA DE ENTRYPOINT -----
 * --------------------------------
 */

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    int days = 0;
    struct time *time = NULL;

    if (!fscanf(stdin, "%d%*c", &days)) exit(0);

    time = _gettime(&days);

    output(time);
    destroy(time);

    return 0;
}

/*
 * --------------------------------------------
 * ----- ROTINA DE PROCESSAMENTO DOS DIAS -----
 * --------------------------------------------
 */

struct time *_gettime(int *days)
{
    struct time *time = calloc(1, sizeof(struct time));

    for (; *days >= 30; *days -= 30)
    {
        time->partial.months += 1;

        if (time->partial.months == 12)
        {
            *days -= 5;
            time->years += 1;
            time->partial.months = 0;
        }
    }

    time->partial.days = *days;

    return time;
}

/*
 * ----------------------------------
 * ----- ROTINA DE APRESENTAÇÃO -----
 * ----------------------------------
 */

void output(struct time *time)
{
    fprintf(stdout, "%d ano(s)\n", time->years);
    fprintf(stdout, "%d mes(es)\n", time->partial.months);
    fprintf(stdout, "%d dia(s)\n", time->partial.days);

    return;
}

/*
 * ------------------------------------------
 * ----- ROTINA DE LIBERAÇÃO DE MEMÓRIA -----
 * ------------------------------------------
 */

void destroy(struct time *time)
{
    free(time);

    return;
}
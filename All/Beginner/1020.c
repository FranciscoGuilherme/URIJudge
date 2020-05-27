#include <stdio.h>
#include <stdlib.h>

struct time
{
    int years;
    short int months;
    short int days;
};

struct time *_gettime(int *);
void output(struct time *);

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    int days = 0;

    if (!fscanf(stdin, "%d%*c", &days)) exit(0);

    output(_gettime(&days));

    return 0;
}

struct time *_gettime(int *days)
{
    struct time *time = calloc(1, sizeof(struct time));

    for (; *days >= 30; *days -= 30)
    {
        time->months += 1;

        if (time->months == 12)
        {
            time->years += 1;
            time->months = 0;
        }
    }

    time->days = *days;

    return time;
}

void output(struct time *time)
{
    fprintf(stdout, "%d ano(s)\n", time->years);
    fprintf(stdout, "%d mes(es)\n", time->months);
    fprintf(stdout, "%d dia(s)\n", time->days);

    return;
}
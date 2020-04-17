#include <stdio.h>
#include <stdlib.h>

struct time
{
    int hours;
    short int minutes;
    short int seconds;
};

struct time *_gettime(int *);

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    int seconds = 0;
    struct time *time = NULL;

    if (!fscanf(stdin, "%d%*c", &seconds)) exit(0);

    time = _gettime(&seconds);

    fprintf(stdout, "%d:%d:%d\n", 
        time->hours,
        time->minutes,
        time->seconds
    );

    return 0;
}

struct time *_gettime(int *seconds)
{
    struct time *time = calloc(1, sizeof(struct time));

    for (; *seconds >= 60; *seconds -= 60)
    {
        time->minutes += 1;

        if (time->minutes == 60)
        {
            time->hours += 1;
            time->minutes = 0;
        }
    }

    time->seconds = *seconds;

    return time;
}
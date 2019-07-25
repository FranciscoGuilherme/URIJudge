#ifndef _salary_h_
#define _salary_h_

struct employee
{
    int number;
    int hours;
    float value;
};

#define calculate(hours, value) hours * value

void input(int *, int *, float *);
float salary(int *, float *);
char **output(int *, float);
void destroy(struct employee *, char **);

#endif

#include "CppUTest/TestHarness.h"
#include "../../src/headers/average.h"

#define AMOUNT 3

TEST_GROUP(average)
{
    typedef struct
    {
        double a;
        double b;
        double c;
        double average;
        const char *output;
    } test;

    test *tests;

    void setup()
    {
        tests = (test *) calloc(AMOUNT, sizeof(test));

        initialize(&tests[0], 5.0, 6.0, 7.0, 6.3, "MEDIA = 6.3\n");
        initialize(&tests[1], 5.0, 10.0, 10.0, 9.0, "MEDIA = 9.0\n");
        initialize(&tests[2], 10.0, 10.0, 5.0, 7.5, "MEDIA = 7.5\n");
    }

    void teardown()
    {
        free(tests);
    }

    void initialize(test *ptest, double a, double b, double c, double average, const char *output)
    {
        ptest->a = a;
        ptest->b = b;
        ptest->c = c;
        ptest->average = average;
        ptest->output = output;

        return;
    }

    char *precision(double number)
    {
        char *buffer = (char *) calloc(10, sizeof(char));

        sprintf(buffer, "%.1lf", number);

        return buffer;
    }
};

TEST(average, calc)
{
    for (int index = 0; index < AMOUNT; index++)
    {
        char *t_average = precision(tests[index].average);
        char *r_average = precision(average(
            &tests[index].a,
            &tests[index].b,
            &tests[index].c
        ));

        STRCMP_EQUAL(t_average, r_average);
    }
}

TEST(average, output)
{
    for (int index = 0; index < AMOUNT; index++)
    {
        STRCMP_EQUAL(tests[index].output, output(tests[index].average));
    }
}

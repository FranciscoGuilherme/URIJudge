#include "CppUTest/TestHarness.h"
#include "../../src/headers/simple_sum.h"

#define AMOUNT 3

TEST_GROUP(simple_sum)
{
    typedef struct
    {
        int a;
        int b;
        int sum;
        const char *output;
    } test;

    test *tests;

    void setup()
    {
        tests = (test *) calloc(AMOUNT, sizeof(test));

        initialize(&tests[0], 30, 10, 40, "SOMA = 40\n");
        initialize(&tests[1], -30, 10, -20, "SOMA = -20\n");
        initialize(&tests[2], 0, 0, 0, "SOMA = 0\n");
    }

    void teardown()
    {
        free(tests);
    }

    void initialize(test *ptest, int a, int b, int sum, const char *output)
    {
        ptest->a = a;
        ptest->b = b;
        ptest->sum = sum;
        ptest->output = output;

        return;
    }
};

TEST(simple_sum, sum)
{
    for (int index = 0; index < AMOUNT; index++)
    {
        CHECK_EQUAL(tests[index].sum, sum(&tests[index].a, &tests[index].b));
    }
}

TEST(simple_sum, output)
{
    for (int index = 0; index < AMOUNT; index++)
    {
        STRCMP_EQUAL(tests[index].output, output(tests[index].sum));
    }
}

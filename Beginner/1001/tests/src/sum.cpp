#include "CppUTest/TestHarness.h"
#include "../../src/headers/sum.h"

#define AMOUNT 3

TEST_GROUP(sum)
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

        initialize(&tests[0], 10, 9, 19, "X = 19\n");
        initialize(&tests[1], -10, 4, -6, "X = -6\n");
        initialize(&tests[2], 15, -7, 8, "X = 8\n");
    }

    void teardown()
    {
        free(tests);
    }

    void initialize(test *ptest, int a, int b, int sum, const char* output)
    {
        ptest->a = a;
        ptest->b = b;
        ptest->sum = sum;
        ptest->output = output;

        return;
    }
};

TEST(sum, operation)
{
    for (int index = 0; index < AMOUNT; index++)
    {
        CHECK_EQUAL(tests[index].sum, sum(&tests[index].a, &tests[index].b));
    }
}

TEST(sum, output)
{
    for (int index = 0; index < AMOUNT; index++)
    {
        STRCMP_EQUAL(tests[index].output, output(tests[index].sum));
    }
}

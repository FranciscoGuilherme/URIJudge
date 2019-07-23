#include "CppUTest/TestHarness.h"
#include "../../src/headers/simple_mult.h"

#define AMOUNT 3

TEST_GROUP(simple_mult)
{
    typedef struct
    {
        int a;
        int b;
        int mult;
        const char *output;
    } test;

    test *tests;

    void setup()
    {
        tests = (test *) calloc(AMOUNT, sizeof(test));

        initialize(&tests[0], 3, 9, 27, "PROD = 27\n");
        initialize(&tests[1], -30, 10, -300, "PROD = -300\n");
        initialize(&tests[2], 0, 9, 0, "PROD = 0\n");
    }

    void teardown()
    {
        free(tests);
    }

    void initialize(test *ptest, int a, int b, int mult, const char *output)
    {
        ptest->a = a;
        ptest->b = b;
        ptest->mult = mult;
        ptest->output = output;

        return;
    }
};

TEST(simple_mult, mult)
{
    for (int index = 0; index < AMOUNT; index++)
    {
        CHECK_EQUAL(tests[index].mult, mult(&tests[index].a, &tests[index].b));
    }
}

TEST(simple_mult, output)
{
    for (int index = 0; index < AMOUNT; index++)
    {
        STRCMP_EQUAL(tests[index].output, output(tests[index].mult));
    }
}

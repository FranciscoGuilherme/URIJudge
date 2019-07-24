#include "CppUTest/TestHarness.h"
#include "../../src/headers/sub.h"

#define AMOUNT 3

TEST_GROUP(sub)
{
    typedef struct
    {
        int a;
        int b;
        int c;
        int d;
        int result;
        const char *output;
    } test;

    test *tests;

    void setup()
    {
        tests = (test *) calloc(AMOUNT, sizeof(test));

        initialize(&tests[0], 5, 6, 7, 8, -26, "DIFERENCA = -26\n");
        initialize(&tests[1], 0, 0, 7, 8, -56, "DIFERENCA = -56\n");
        initialize(&tests[2], 5, 6, -7, 8, 86, "DIFERENCA = 86\n");
    }

    void teardown()
    {
        free(tests);
    }

    void initialize(test *ptest, int a, int b, int c, int d, int result, const char *output)
    {
        ptest->a = a;
        ptest->b = b;
        ptest->c = c;
        ptest->d = d;
        ptest->result = result;
        ptest->output = output;

        return;
    }
};

TEST(sub, calc)
{
    for (int index = 0; index < AMOUNT; index++)
    {
        CHECK_EQUAL(tests[index].result, sub(
            &tests[index].a,
            &tests[index].b,
            &tests[index].c,
            &tests[index].d
        ));
    }
}

TEST(sub, output)
{
    for (int index = 0; index < AMOUNT; index++)
    {
        STRCMP_EQUAL(tests[index].output, output(tests[index].result));
    }
}

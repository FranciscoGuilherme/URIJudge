#include "CppUTest/TestHarness.h"
#include "../../src/headers/sum.h"

TEST_GROUP(sum)
{
    typedef struct
    {
        int a;
        int b;
        int sum;
        const char *output;
    } test;

    typedef struct
    {
        test x;
        test y;
        test z;
    } cases;

    cases tests;

    void setup()
    {
        tests =
        {
            .x =
            {
                .a = 10,
                .b = 9,
                .sum = 19,
                .output = "X = 19\n",
            },

            .y =
            {
                .a = -10,
                .b = 4,
                .sum = -6,
                .output = "X = -6\n",
            },

            .z =
            {
                .a = 15,
                .b = -7,
                .sum = 8,
                .output = "X = 8\n"
            }
        };
    }

    void teardown() {}
};

TEST(sum, operation)
{
    CHECK_EQUAL(tests.x.sum, sum(&tests.x.a, &tests.x.b));
    CHECK_EQUAL(tests.y.sum, sum(&tests.y.a, &tests.y.b));
    CHECK_EQUAL(tests.z.sum, sum(&tests.z.a, &tests.z.b));
}

TEST(sum, output)
{
    STRCMP_EQUAL(tests.x.output, output(tests.x.sum));
    STRCMP_EQUAL(tests.y.output, output(tests.y.sum));
    STRCMP_EQUAL(tests.z.output, output(tests.z.sum));
}

#include "CppUTest/TestHarness.h"
#include "../../src/headers/area.h"

#define AMOUNT 3

TEST_GROUP(circle)
{
    typedef struct
    {
        double area;
        double radius;
        const char *output;
    } test;

    test *tests;

    void setup()
    {
        tests = (test *) calloc(AMOUNT, sizeof(test));

        tests[0] =
        {
            .area = 12.5664,
            .radius = 2.00,
            .output = "A=12.5664\n"
        };

        tests[1] =
        {
            .area = 31819.3103,
            .radius = 100.64,
            .output = "A=31819.3103\n"
        };

        tests[2] =
        {
            .area = 70685.7750,
            .radius = 150.00,
            .output = "A=70685.7750\n"
        };
    }

    void teardown() {}

    char *precision(double number)
    {
        char *buffer = (char *) calloc(10, sizeof(char));

        sprintf(buffer, "%.4lf", number);

        return buffer;
    }
};

TEST(circle, area)
{
    for (int index = 0; index < 3; index++)
    {
        char *t_area = precision(tests[index].area);
        char *r_area = precision(area(&tests[index].radius));

        STRCMP_EQUAL(t_area, r_area);
    }
}

TEST(circle, output)
{
    for (int index = 0; index < 3; index++)
    {
        STRCMP_EQUAL(tests[index].output, output(tests[index].area));
    }
}

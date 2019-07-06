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

        initialize(&tests[0], 12.5664, 2.00, "A=12.5664\n");
        initialize(&tests[1], 31819.3103, 100.64, "A=31819.3103\n");
        initialize(&tests[2], 70685.7750, 150.00, "A=70685.7750\n");
    }

    void teardown()
    {
        free(tests);
    }

    void initialize(test *ptest, double area, double radius, const char* output)
    {
        ptest->area = area;
        ptest->radius = radius;
        ptest->output = output;

        return;
    }

    char *precision(double number)
    {
        char *buffer = (char *) calloc(10, sizeof(char));

        sprintf(buffer, "%.4lf", number);

        return buffer;
    }
};

TEST(circle, area)
{
    for (int index = 0; index < AMOUNT; index++)
    {
        char *t_area = precision(tests[index].area);
        char *r_area = precision(area(&tests[index].radius));

        STRCMP_EQUAL(t_area, r_area);
    }
}

TEST(circle, output)
{
    for (int index = 0; index < AMOUNT; index++)
    {
        STRCMP_EQUAL(tests[index].output, output(tests[index].area));
    }
}

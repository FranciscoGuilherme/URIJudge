#include <list>

#include "CppUTest/TestHarness.h"
#include "../../src/headers/salary.h"

#define AMOUNT 3

TEST_GROUP(salary)
{
    typedef struct
    {
        const char *number;
        const char *salary;
    } out;

    typedef struct
    {
        int number;
        int hours;
        float value;
        float salary;
        out *output;
    } test;

    test *tests;

    void setup()
    {
        tests = (test *) calloc(AMOUNT, sizeof(test));

        outputs[0].number = "NUMBER = 25\n";
        outputs[1].number = "NUMBER = 1\n";
        outputs[2].number = "NUMBER = 6\n";

        outputs[0].salary = "SALARY = U$ 550.00\n";
        outputs[1].salary = "SALARY = U$ 4100.00\n";
        outputs[2].salary = "SALARY = U$ 2254.75\n";

        initialize(&tests[0], 25, 100, 5.50, 550.00, &outputs[0]);
        initialize(&tests[1], 1, 200, 20.50, 4100.00, &outputs[1]);
        initialize(&tests[2], 6, 145, 15.55, 2254.75, &outputs[2]);
    }

    void teardown()
    {
        free(tests);
        free(outputs);
    }

    void initialize(test *ptest, int number, int hours, float value, float salary, out *outputs)
    {
        ptest->output = (const char **) calloc(2, sizeof(const char *));

        ptest->number = number;
        ptest->hours = hours;
        ptest->value = value;
        ptest->salary = salary;
        ptest->output[0] = outputs->number;
        ptest->output[1] = outputs->salary;

        return;
    }

    char *precision(float salary)
    {
        char *buffer = (char *) calloc(15, sizeof(char));

        sprintf(buffer, "%.2f", salary);

        return buffer;
    }
};

TEST(salary, calc)
{
    for (int index = 0; index < AMOUNT; index++)
    {
        char *t_salary = precision(tests[index].salary);
        char *r_salary = precision(salary(
            &tests[index].hours,
            &tests[index].value
        ));

        STRCMP_EQUAL(t_salary, r_salary);
    }
}

TEST(salary, output)
{
    for (int index = 0; index < AMOUNT; index++)
    {
        char **buffer = output(
            &tests[index].number,
            tests[index].salary
        );

        STRCMP_EQUAL(tests[index].output[0], buffer[0]);
        STRCMP_EQUAL(tests[index].output[1], buffer[1]);
    }
}

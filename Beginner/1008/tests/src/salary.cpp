#include "CppUTest/TestHarness.h"
#include "../../src/headers/salary.h"

#define AMOUNT 3
#define OUTPUT 2

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

        initialize_numbers(&tests[0], 25, 100, 5.50, 550.00);
        initialize_numbers(&tests[1], 1, 200, 20.50, 4100.00);
        initialize_numbers(&tests[2], 6, 145, 15.55, 2254.75);

        initialize_output(&tests[0], "NUMBER = 25\n", "SALARY = U$ 550.00\n");
        initialize_output(&tests[1], "NUMBER = 1\n", "SALARY = U$ 4100.00\n");
        initialize_output(&tests[2], "NUMBER = 6\n", "SALARY = U$ 2254.75\n");
    }

    void teardown()
    {
        for (int index = 0; index < AMOUNT; index++)
        {
            free(tests[index].output);
        }

        free(tests);
    }

    void initialize_numbers(test *ptest, int number, int hours, float value, float salary)
    {
        ptest->number = number;
        ptest->hours = hours;
        ptest->value = value;
        ptest->salary = salary;

        return;
    }

    void initialize_output(test *ptest, const char *number, const char *salary)
    {
        ptest->output = (out *) calloc(OUTPUT, sizeof(out));

        ptest->output->number = number;
        ptest->output->salary = salary;

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

        STRCMP_EQUAL(tests[index].output->number, buffer[0]);
        STRCMP_EQUAL(tests[index].output->salary, buffer[1]);
    }
}

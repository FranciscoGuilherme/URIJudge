#include "CppUTest/TestHarness.h"
#include "../../src/headers/salary.h"

#define AMOUNT 3
#define OUTPUT 1

TEST_GROUP(salary)
{
    typedef struct
    {
        const char *salary;
    } out;

    typedef struct
    {
        const char *name;
        double number;
        double sales;
        double salary;
        out *output;
    } test;

    test *tests;

    void setup()
    {
        tests = (test *) calloc(AMOUNT, sizeof(test));

        initialize_person(&tests[0], "JOAO", 500.00, 1230.30, 684.54);
        initialize_person(&tests[1], "PEDRO", 700.00, 0.0, 700.00);
        initialize_person(&tests[2], "MANGOJATA", 1700.00, 1230.50, 1884.58);

        initialize_output(&tests[0], "TOTAL = R$ 684.54\n");
        initialize_output(&tests[1], "TOTAL = R$ 700.00\n");
        initialize_output(&tests[2], "TOTAL = R$ 1884.58\n");
    }

    void teardown()
    {
        for (int index = 0; index < AMOUNT; index++)
        {
            free(tests[index].output);
        }

        free(tests);
    }

    void initialize_person(test *ptest, const char *name, double number, double sales, double salary)
    {
        ptest->name = name;
        ptest->number = number;
        ptest->sales = sales;
        ptest->salary = salary;

        return;
    }

    void initialize_output(test *ptest, const char *message)
    {
        ptest->output = (out *) calloc(OUTPUT, sizeof(out));

        ptest->output->salary = message;

        return;
    }

    char *precision(double salary)
    {
        char *buffer = (char *) calloc(15, sizeof(char));

        sprintf(buffer, "%.2lf", salary);

        return buffer;
    }
};

TEST(salary, calc)
{
    for (int index = 0; index < AMOUNT; index++)
    {
        char *t_salary = precision(tests[index].salary);
        char *r_salary = precision(salary(
            &tests[index].number,
            &tests[index].sales
        ));

        STRCMP_EQUAL(t_salary, r_salary);
    }
}

TEST(salary, output)
{
    for (int index = 0; index < AMOUNT; index++)
    {
        char *buffer = output(tests[index].salary);

        STRCMP_EQUAL(tests[index].output->salary, buffer);
    }
}

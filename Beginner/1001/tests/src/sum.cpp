#include <stdio.h>
#include <stdlib.h>
#include "CppUTest/TestHarness.h"
#include "CppUTest/MemoryLeakDetectorMallocMacros.h"

#define TESTS_LENGTH 3

TEST_GROUP(sum)
{
    char *results[TESTS_LENGTH];

    void setup()
    {
        results[0] = (char *) "X = 19\n";
        results[1] = (char *) "X = -6\n";
        results[2] = (char *) "X = 8\n";
    }

    void teardown()
    {
        for(int index = 0; index < TESTS_LENGTH; index++)
        {
            results[index] = NULL;
        }
    }
};

TEST(sum, results)
{
    int index = 0;
    int value = 0;
    int total = 0;

    char *output = (char *) calloc(10, sizeof(char));

    fscanf(stdin, "%d", &value);

    for(; index < value ; index++)
    {
        fscanf(stdin, "%d", &total);
        sprintf(output, "X = %d\n", total);

        STRCMP_EQUAL(results[index], output);
    }

    free(output);
}

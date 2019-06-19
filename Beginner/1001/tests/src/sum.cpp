#include <stdio.h>
#include "CppUTest/TestHarness.h"
#include "../../src/headers/sum.h"

TEST_GROUP(sum) {};

TEST(sum, test_sum)
{
    fprintf(stdin, "10\n");
    fprintf(stdin, "9\n");

    sum();

    STRCMP_EQUAL("X = 19\n", buffer->asCharString());
}

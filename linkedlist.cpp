#include <iostream>
#include "list.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

using namespace std;

TEST_GROUP(ListUnit)
{
    void setup()
    {

    }

    void teardown()
    {
        
    }
};

TEST(ListUnit, HelloWorld)
{
    printf("HelloWorld\n");
    return;
}

int main (int argc, char *argv[])
{
    return RUN_ALL_TESTS(argc, argv);
}

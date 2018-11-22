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

TEST(ListUnit, DefaultConstructor)
{
    CList myList; 
    for (int i = 0; i < 10; ++i)
    {
        CNode* myNode = new CNode;
        myNode->set(i);
        myList.push(myNode);
        myNode = nullptr; 
    }

    int i = 0;
    for(CNode* pcur = myList.getHead(); pcur != nullptr; pcur = pcur->getNext(), ++i)
    {
        CHECK_TRUE(pcur->get() == 9 - i)
    }

    return;
}

int main (int argc, char *argv[])
{
    return RUN_ALL_TESTS(argc, argv);
}

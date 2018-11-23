#include <iostream>
#include "list.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

using namespace std;

TEST_GROUP(ListUnit)
{   
   
};

TEST(ListUnit, ListCheck)
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

    CNode *myNode = myList.pop(); 
    i = 0;
    while(nullptr != myNode)
    {
        CHECK_EQUAL( 9-i, myNode->get() );
        CHECK_EQUAL( nullptr, myNode->getNext() );
        ++i;
        delete myNode;
        myNode = myList.pop();
    }
    
    return;
}


TEST_GROUP(InterviewQuestion)
{   
    CList myList;

    void setup()
    {
        for (int i = 0; i < 10; ++i)
        {
            CNode *myNode = new CNode();
            myNode->set(i);
            myList.pushTail(myNode);
            myNode = nullptr; 
        }

    }

    void teardown()
    {
        CNode *myNode = myList.pop();
        while(myNode != nullptr)
        {
            delete myNode;
            myNode = myList.pop();
        }
    }
    
};

CNode *fromEnd(CNode* node, int n, int &dist)
{
    // base case
    if (node == nullptr)
    {
        dist = -1;
        return nullptr;
    }

    // depth first
    CNode *child = fromEnd(node->getNext(), n, dist);
    dist += 1; 
    return n == dist ? node : child; 
}

CNode *fromEnd(const CList &list, int n)
{
    int distFromEnd = -1;
    return fromEnd(list.getHead(), n, distFromEnd);
}

TEST(InterviewQuestion, MthToLast1)
{
    // Efficiently find the Mth to last node in a list
    // Let's do a crappy recursive solution that can't possibly be the right answer

    CNode * first;
    for(int i = 0; i < 9; ++i)
    {
        first = fromEnd(myList, i);
        CHECK_EQUAL(9-i, first->get());
    }

}

int main (int argc, char *argv[])
{
    return RUN_ALL_TESTS(argc, argv);
}

// list.h

class CNode
{
public:
    CNode();
    ~CNode();

    int get();
    void set(int value);

    CNode* getNext();
    void setNext(CNode  *pNode);

private:
    int _value;
    CNode* _pNext;

};

class CList
{
public:
    CList();
    ~CList();

    CNode* getHead();
    CNode* getTail();

    void push(CNode* pNode);
    void pushTail(CNode* pNode);
    CNode* pop();

private:
    CNode *_pHead;
    CNode *_pTail;

};



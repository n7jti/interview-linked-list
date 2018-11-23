// list.cpp

#include "list.h"


CNode::CNode()
    : _value(0)
    , _pNext(nullptr)
{

}

CNode::~CNode()
{
    if (_pNext != nullptr)
    {
        delete _pNext;
    }
    _pNext = nullptr; 
}

int  CNode::get() const
{
    return this->_value;
}

void  CNode::set(int value)
{
    this->_value = value;
}

CNode* CNode::getNext() const
{
    return this->_pNext;
}

void CNode::setNext(CNode *pNode)
{
    _pNext = pNode;
}

CList::CList()
    : _pHead(nullptr)
    , _pTail(nullptr)
{

}

CList::~CList()
{
    delete _pHead;
    _pHead = nullptr; 
    _pTail = nullptr; 

}

CNode* CList::getHead() const
{
    return _pHead;
}

CNode* CList::getTail() const
{
    return _pTail; 
}

void CList::push(CNode* pNode)
{
    // push onto the front
    pNode->setNext(_pHead);
    _pHead = pNode;

    if (_pTail == nullptr) {
        _pTail = _pHead; 
    }
}

void CList::pushTail(CNode* pNode)
{
    // do nothing if pusshing a null node on the end of the list
    if (pNode == nullptr) {
        return ;
    }

    // if there is an existing tail, link it to the CNode
    if (_pTail != nullptr) {
        _pTail->setNext(pNode);
    }

    // set the new tail pointer; 
    _pTail = pNode;

    // if there was no head pointer previously, then set the head pointer 
    if (_pHead == nullptr) {
        _pHead = _pTail; 
    }
}

CNode* CList::pop()
{
    // get the head node
    CNode* pNode = nullptr;

    // If there is a head node, set our new head to the next pointer. 
    if (_pHead != nullptr) {
        pNode = _pHead;
        _pHead = _pHead->getNext();
        pNode->setNext(nullptr); 
    }

    // If we are poping the tail, then set it null
    if (_pTail == pNode) {
        _pTail = nullptr; 
    }

    return pNode; 
}


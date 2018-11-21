// list.cpp

#include "list.h"


    CList::CList()
        : _value(0)
        , _pNext(nullptr)
    {

    }

    CList::~CList()
    {
        if (_pNext != nullptr)
        {
            delete _pNext;
        }
    }

    int  CList::get()
    {
        return this->_value;
    }
    
    void  CList::set(int value)
    {
        this->_value = value;
    }

    CList*  CList::getNext()
    {
        return this->_pNext;
    }
// list.h

class CList
{
public:
    CList();
    ~CList();

    int get();
    void set(int value);

    CList* getNext();

private:
    int _value;
    CList* _pNext;

};



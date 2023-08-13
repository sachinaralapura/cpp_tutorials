// ------------------------------------------------------
// List.cpp : The methods of class InhomList
// ------------------------------------------------------
#include "List.h"
#include <typeinfo>

InhomList::~InhomList()
{
    Cell *pel = first;
    Cell *next = NULL;
    while (pel != NULL)
    {
        next = pel->getNext();
        delete pel;
        pel = next;
    }
}

Cell *InhomList::getPrev(const string &n)
{
    Cell *pel = first;
    Cell *prev = NULL;
    while (pel != NULL)
    {
        if (n < dynamic_cast<BaseEl *>(pel)->getName())
        {
            prev = pel;
            pel = pel->getNext();
        }
        else
            return prev;
    }

    return prev;
}

Cell *InhomList::getPos(const string &n)
{
    Cell *Ele = first;
    while (Ele != NULL && (n != dynamic_cast<BaseEl *>(Ele)->getName()))
    {
        Ele = Ele->getNext();
    }
    if (Ele != NULL && (n == dynamic_cast<BaseEl *>(Ele)->getName()))
    {
        return Ele;
    }
    else
        return NULL;
}

void InhomList::insertAfter(const string &s, Cell *prev)
{
    if (prev == NULL)
    {
        first = new BaseEl(first, s);
    }
    else
    {
        Cell *p = new BaseEl(prev->getNext(), s);
        prev->setNext(p);
    }
}

void InhomList::insertAfter(const string &s, const string &b, Cell *prev)
{
    if (prev == NULL)
    {
        first = new DerivedEl(first, s, b);
    }
    else
    {
        Cell *p = new DerivedEl(prev->getNext(), s, b);
        prev->setNext(p);
    }
}

void InhomList::insert(const string &s)
{
    Cell *prev = getPrev(s);
    insertAfter(s, prev);
}

void InhomList::insert(const string &n, const string &b)
{
    Cell *prev = getPrev(n);
    insertAfter(n, b, prev);
}

void InhomList::displayAll() const
{
    Cell *pEl = first;
    while (pEl != NULL)
    {
        pEl->display();
        pEl = pEl->getNext();
    }
    
}

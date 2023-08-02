#ifndef _LISTE_H_
#define _LISTE_H_
#include "../DateTime/DateTime.h"
#include <iostream>
#include <iomanip>
using namespace std;

class ListElement
{
private:
    Date date;
    double amount;
    ListElement *next;

public:
    ListElement(Date d = Date(1, 1, 1), double b = 0, ListElement *ll = NULL) : date(d), amount(b), next(ll) {}

    // --------------- get and set method --------------------------
    const Date &getDate() const { return date; }
    double getAmount() const { return amount; }
    void setDate() { date.setDate(); }
    bool setDate(int day, int month, int year) { return date.setDate(day, month, year); }
    void setAmount(double a) { amount = a; }

    ListElement *getNext() const { return next; }

    //------------------- friend class List ------------------------
    friend class List;
};

//------------------- Global operator function for ListElement class ----------------

ostream &operator<<(ostream &os, ListElement &listEle)
{
    os << "---------------------------------------------------------\n";
    os << "Day Time" << endl;
    os << listEle.getDate().asString() << endl;
    os << "Amount : " << fixed << setprecision(2) << setw(10) << listEle.getAmount() << endl;
    return os;
}

//========================================================================================
//-  -  -  -  -  -  -  -  -  -  -  -  -  List Class  -  - -  -  -  -  -  -  -  -  -  -  -  - -  -
//========================================================================================

// Defines the List class

class List
{
private:
    ListElement *first, *last;

public:
    List() { first = last = NULL; }
    ~List();

    // Access to the first and last elements:
    ListElement *getFirst() const { return first; }
    ListElement *getLast() const { return last; }

    // Append a new element at the end of the list:
    void pushBack(const Date &d, double b);

    // Delete an element at the beginning of the list
    void popFront();
};

// ------------------------ Implement methods of class List------------------
// Destructor of the list:
List::~List()
{
    ListElement *currentElement = first, *next = NULL;
    for (; currentElement != NULL; currentElement = next)
    {
        next = currentElement->next;
        delete currentElement;
    }
}

//--------------------------------------------------------------------
void List::pushBack(const Date &d, double b)
{
    ListElement *newElement = new ListElement(d, b);
    if (last == NULL)
    {
        first = last = newElement;
    }
    else
    {
        last->next = newElement;
        last = newElement;
    }
}

//---------------------------------------------------------------------
void List::popFront()
{
    if (first != NULL)
    {
        ListElement *firstELement = first;
        first = first->next;
        delete firstELement;
        if (first == NULL)
            last = NULL;
    }
}

//------------------------------------------------------------------------
//------------------- Global operator function for List class ----------------
// Outputs the list:
ostream &operator<<(ostream &os, List &list)
{
    ListElement *currentElement = list.getFirst();
    if (currentElement == NULL)
        os << "The list is empty!" << endl;

    for (; currentElement != NULL; currentElement = currentElement->getNext())
    {
        os << *currentElement;
    }

    return os;
}

#endif
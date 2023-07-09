// telList.h
// Class TelList to represent a list containing names and telephone numbers.
// ----------------------------------------------------
#ifndef _TelList_
#define _TelList_
#define MAX 100
#include "array.h"

struct Element
{
    string name, telNo;
};

class TelList
{
private:
    Element v[MAX];
    int count;

public:
    TelList() : count(0){};
    int getCount() const { return this->count; }
    bool append(const Element &el)
    {
        return append(el.name, el.telNo);
    }

    bool append(const string &name, const string &telNo);

    Element *retrive(int i)
    {
        return &v[i];
    }

    void print(int i);

};

#endif
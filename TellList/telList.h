// telList.h
// Class TelList to represent a list containing names and telephone numbers.
// ----------------------------------------------------
#ifndef _TelList_
#define _TelList_
#define MAX 100
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <string.h>
using namespace std;

struct Element
{
    string name, telNo;
};

class TelList
{
private:
    Element v[MAX];
    int count;          // pointer to Element

public:
    TelList() : count(0){};

    int getCount() const { return this->count; }    
    string getNumber(const string& name);

    bool append(const Element &el)
    {
        return append(el.name, el.telNo);
    }

    bool append(const string &name, const string &telNo);

    Element *retrive(int i)
    {
        return &v[i];
    }

    void print();
    void print(int i);
    void print(const string& name);

    bool erase( const string& name);

    int search(const string& name);

};

#endif
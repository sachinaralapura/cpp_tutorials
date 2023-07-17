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
#include <fstream>
using namespace std;

struct Element
{
    string name, telNo;
};

class TelList
{
private:
    Element v[MAX];
    int count;       // pointer to Element
    string fileName; // File name
    bool dirty;      // true if data has been changed but not yet saved.

public:
    TelList() : count(0), fileName(""), dirty(false){};

    int getCount() const { return this->count; }
    string getNumber(const string &name);

    bool append(const Element &el)
    {
        return append(el.name, el.telNo);
    }

    bool append(const string &name, const string &telNo);

    Element *retrive(int i)
    {
        return (i >= 0 && i < count) ? &v[i] : NULL;
    }

    bool erase(const string &name);
    int search(const string &name) const;

    void print();
    void print(int i);
    void print(const string &name);

    const string &getFileName() const { return this->fileName; }
    bool setFilename(const string &fn)
    {
        if (fn.empty())
            return false;
        else
        {
            fileName = fn;
            dirty = true;
            return true;
        }
    }

    bool isDirty() const { return dirty; }
    bool load();
    bool save();
    bool saveAs();
};

#endif
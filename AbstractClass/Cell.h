// cell.h: Defining the classes Cell, BaseEl, and DerivedEl
// --------------------------------------------------------
#ifndef _CELL_
#define _CELL_
#include <string>
#include <iostream>
using namespace std;

// ====================================================================

class Cell
{
private:
    Cell *next;

protected:
    Cell(Cell *suc = NULL) { next = suc; }

public:
    virtual ~Cell() {}
    Cell *getNext() const { return next; }
    void setNext(Cell *suc) { next = suc; }
    virtual void display() const = 0;
};

//======================================================================

class BaseEl : public Cell
{
private:
    string name;

public:
    BaseEl(Cell *suc = NULL, const string &s = "") : Cell(suc), name(s) {}
    const string &getName() const
    {
        return name;
    }
    void setName(const string &n) { name = n; }
    void display() const
    {
        cout << "\n--------------------------------"
             << "\nName:        " << name << endl;
    }
};

//======================================================================

class DerivedEl : public BaseEl
{
private:
    string rem;

public:
    DerivedEl(Cell *suc = NULL, const string &s = "", const string &b = "") : BaseEl(suc, s), rem(b) {}
    // Access methods:
    void setRem(const string &b) { rem = b; }
    const string &getRem() const { return rem; }

    void display() const
    {
        BaseEl::display();
        cout << "Remark:        " << rem << endl;
    }
};

#endif
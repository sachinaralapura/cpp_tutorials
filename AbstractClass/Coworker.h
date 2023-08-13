/*
■ PURE VIRTUAL METHODS
    -When a pure virtual method is declared, the method is identified by adding the expression = 0.
        Example: virtual void demo()=0; // pure virtual
    This informs the compiler that there is no definition of the demo() method in the class.
    A NULL pointer is then entered in the virtual method table for the pure virtual method.

■ ABSTRACT AND CONCRETE CLASSES
    -If a class comprises pure virtual methods, you cannot create objects of this class type.
        Example: Coworker worker("Black , Michael");
    -The compiler will issue an error message here, as the Coworker class contains the pure virtual method "income()."
    This avoids calling a method for worker that still needs to be defined.
    A class that does not allow you to create any objects is referred to as an "abstract class".
    In contrast, a class that allows you to create objects is referred to as a "concrete class".

    When a class is derived from an abstract class, it inherits all the methods the base class
    contains, particularly the pure virtual methods. If all of these pure virtual methods are
    implemented in the derived class, you can then create an object of the derived class type.

    ■ POINTERS AND REFERENCES TO ABSTRACT CLASSES
        Although you cannot define objects for abstract classes, you can declare pointers and references to abstract classes.
            Example: Coworker *felPtr, &coRef;

■ Virtual Operator Functions
    - Operator functions implemented as methods can also be virtual.
    - In this case, you can ensure that the right version of an operator function will be executed
      when using a pointer or reference to a base class to address a derived class object.

    ■ Using Virtual Assignments
    Redefining the virtual operator function operator=(), which returns a reference to the derived class,
    is not yet supported by all compilers. In this case the return type must be a reference to the base class Coworker.
*/

// Coworker.h: Defining the abstract class Coworker.
// ----------------------------------------------------
#ifndef _COWORKER_H
#define _COWORKER_H
#include <string>
#include <iostream>
using namespace std;

//===================================================================================

class Coworker
{
private:
    string name;

public:
    Coworker(const string &s = "") { name = s; }
    virtual ~Coworker() {}
    const string &getName() const { return name; }
    void setName(const string &n) { name = n; }
    virtual void display() const { cout << name; };
    virtual double income() const = 0;
    virtual Coworker &operator=(const Coworker &m);
};

// Extending the headerfile.
//=====================================================================================

class Laborer : public Coworker
{
private:
    double wages;
    int hr;

public:
    Laborer(const string &s = " ", double w = 0.0, int h = 0) : Coworker(s), wages(w), hr(h) {}
    ~Laborer() {}
    double getWages() const { return wages; }
    void setWages(double w) { wages = w; }
    int getHr() const { return hr; }
    void setHr(int h) { hr = h; }
    void display() const;
    double income() const
    {
        return (wages * hr);
    }
    Laborer &operator=(const Coworker &m);
    Laborer &operator=(const Laborer &m);
};

//=================================================================================

class Employee : public Coworker
{
private:
    double salary;
    // Pay per month
public:
    Employee(const string &s = "", double sa = 0.0) : Coworker(s), salary(sa) {}
    double getSalary() const { return salary; }
    void setSalary(double sa) { salary = sa; }
    void display() const;
    double income() const { return salary; }
    Employee &operator=(const Coworker &);
    Employee &operator=(const Employee &);
};

#endif
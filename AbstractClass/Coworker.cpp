#include "Coworker.h"

//-----------------------------------------------------------------------

Coworker &Coworker::operator=(const Coworker &m)
{
    if (this != &m)
        this->name = m.name;
    cout << " Coworker virtual  assignment" << endl;
    return *this;
}

// -----------------------------------------------------------------

void Laborer::display() const
{
    cout << getName() << endl;
    cout << getWages() << endl;
    cout << getHr() << endl;
}

// Redefinition: virtual
Laborer &Laborer::operator=(const Coworker &m)
{
    if (this != &m)
    {
        cout << " Laborer virtual assignment" << endl;
        Coworker::operator=(m);
        wages = 0.0;
        hr = 0.0;
    }

    return *this;
}

// Standard Assignment: not virtual
Laborer &Laborer::operator=(const Laborer &m)
{
    if (this != &m)
    {
        cout << " Laborer standard assignment" << endl;
        Coworker::operator=(m);
        // this->setName(m.getName)
        this->wages = m.getWages();
        this->hr = m.getHr();
    }
    return *this;
}

// ----------------------------------------------------------------------

void Employee::display() const
{
    cout << getName() << endl;
    cout << getSalary() << endl;
}

// Redefinition: virtual
Employee &Employee::operator=(const Coworker &m)
{
    if (this != &m)
    {
        this->setName(m.getName());
        this->salary = 0.0;
    }
    return *this;
}

// Standard Assignment: not virtual
Employee &Employee::operator=(const Employee &m)
{
    if (this != &m)
    {
        Coworker::operator=(m);
        this->salary = m.salary;
    }
    return *this;
}

// --------------------------------------------------------------------------
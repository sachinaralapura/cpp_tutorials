#include "mist.h"
#include <fstream>
#ifndef __ACCOUNT__
#define __ACCOUNT__

class Account
{

private:
    string name;
    unsigned long accno;
    double balance;

    /*Every class automatically contains four standard methods:
    ■ the default constructor
    ■ the destructor
    ■ the copy constructor and
    ■ the assignment.
    */

public:
    //-------------------- construtor and destructor----------------------------
    Account(){};                                              // implicit inline method (constructor)
    Account(const string &, unsigned long = 0, double = 0.0); // constructor with default values;
    ~Account();                                               // Destructor

    bool init(const string &, unsigned long, double);
    void display() const;
    bool isEmpty() const;

    //---------------------get and set methods -----------------------------------
    const string &getName() { return name; }                                 // If the  access methods were defined as inline, access is
    void setName(const string &n) { n.size() < 1 ? name = name : name = n; } // just as efficient as direct access to the public members.
    double getBalance() const;                                               // getBalance method , example for 'Read-only method'

    //------------------------ file write and read ---------------------------------
    ostream& writeToFile(ostream& os) const;
    istream& readFromFile(istream& is);

};

#endif

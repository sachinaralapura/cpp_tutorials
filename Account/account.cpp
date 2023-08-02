#include "account.h"

//--------------- Defining constructor and Destructor ------------------------

Account::Account(const string &c_name, unsigned long c_accno, double c_balance)
{
    name = c_name;
    accno = c_accno;
    balance = c_balance;
}

Account::~Account()
{
    cout << "I am the destructor of " << name << " 💀 " << endl;
}

//--------------- Defining class method --------------------------------------

bool Account::init(const string &i_name, unsigned long i_accno, double i_balance)
{
    if (i_name.size() < 1)
    {
        return false;
    }
    name = i_name;
    accno = i_accno;
    balance = i_balance;
    return true;
}

//---------------------------------------------------------------

void Account::display() const
{
    cout << fixed << setprecision(2)
         << "--------------------------------------\n"
         << "Account holder:" << name << '\n'
         << "Account number:" << accno << '\n'
         << "Account balance:" << balance << '\n'
         << "status:";

    if (isEmpty()) // calling Account method inside other method
        cout << "Empty Account" << endl;
    else
        cout << "Not Empty" << endl;
    cout << "----------------------------------------\n";
}

//----------------------- Explicit inline method-------------------------------
// --- inline method are used for small functions , when the function is called the function is replaced
// --- instead of jumping to the function defination , hence inline keyword suggests to the compiler that
// --- a function should be expanded inline at the call site.

inline bool Account::isEmpty() const
{
    if (balance == 0)
    {
        return true;
    }
    return false;
}

// ---------------------- get and set method --------------------------

double Account::getBalance() const
{                   // this is 'read-only method ,  it helps compiler to identify
    return balance; // read-only methods  , this method can alse be called on
} // const Account objects


#include "account.h"

//-------------------------------------------------------
// getAccount() reads data for a new account
// and adds it into the argument.

bool getAccount(Account *pAccount)
{

    string name, line(50, '-');
    unsigned long accno;
    double balance;

    cout << line << endl
         << "Enter data for a new account: \n"
         << "Account holder: ";

    // reading account name
    if (!getline(cin, name) || name.size() == 0)
    {
        return false;
    }

    // reading account number
    cout << "Account number: ";
    if (!(cin >> accno))
        return true;

    // reading account capital
    cout << "Starting capital: ";
    if (!(cin >> balance))
        return false;

    // initializing object
    (*pAccount).init(name, accno, balance);
    return true;
}
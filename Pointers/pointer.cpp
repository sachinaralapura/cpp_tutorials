#include "pointer.h"
#include <stdarg.h>
#include <cctype>
// variable number of arguments

void accSort(Account **kptr, int n);
void ptrSwap(Account **kptr, Account **p2);

void compare(double, double);

// two function;
void message_up(const char *), message_low(const char *);

// array of function pointer;
void (*funcPtr[])(const char *) = {message_up, message_low};

int main(int argc, char const *argv[])
{
    Account **accptr = new Account *[100];
    cout << accptr << endl;
    cout << *accptr << endl;

    // calling function using pointer to function
    void (*functionPointer)(double, double);
    functionPointer = compare;
    (*functionPointer)(233, 32);
    //--------------------------------------------

    (*funcPtr[0])("this is converted to upper");
    return 0;
}

void compare(double a, double b)
{
    if (a == b)
        cout << a << " is  equal to " << b << endl;
    else if (b > a)
        cout << b << " is greater than " << a << endl;
    else
        cout << a << " is greater than " << b << endl;
}

void message_up(const char *c)
{
    int ch;
    for (; *c != '\0'; c++)
    {
        ch = toupper(*c);
        cout.put(ch);
    }
}

void message_low(const char *c)
{
    int ch;
    for (; *c != '\0'; c++)
    {
        ch = tolower(*c);
        cout.put(ch);
    }
}
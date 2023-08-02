#include "LinkedList.h"
#include <string>
#define LINE "-----------------------------------------------------------\n"
List *passBook = new List;

bool pushElement();
void popElement();

int main(int argc, char const *argv[])
{

    List aList;
    cout << aList << endl;

    cout << "\nEnter account changes (Date and Amount)"
            "\n(Type invalid input to quit, e.g. q):\n";
    Date date;
    int month, day, year;
    char c;
    double amount;
    while (true)
    {
        cout << "Date format Month-Day-Year : ";
        if (!(cin >> month >> c >> day >> c >> year) || !date.setDate(month, day, year))
            break;
        // Invalid date.
        cout << "Account change: ";
        if (!(cin >> amount))
            break;
        aList.pushBack(date, amount);
    }
    cout << "\nContent of the list:\n";
    cout << aList << endl;
    cout << "\nRemoving the first element of the list:\n";
    ListElement *ptrEl = ptrEl = aList.getFirst();
    if (ptrEl != NULL)
    {
        cout << "Deleting: " << *ptrEl << endl;
        aList.popFront();
    }
    cout << "\nContent of the list:\n";
    cout << aList << endl;
    return 0;
}

bool pushElement()
{
    Date date;
    int month, day, year;
    char c;
    double amount;

    cout << "Date format Day-Month-Year : \n";
    if (!(cin >> day >> c >> month >> c >> year) || cin.fail())
    {
        return false;
    }

    if (!(date.setDate(day, month, year)))
    {
        return false;
    }

    cout << "enter Amount " << endl;
    if (!(cin >> amount))
        return false;

    (*passBook).pushBack(date, amount);

    return true;
}

void popElement()
{
    ListElement *front = passBook->getFirst();
    if (front != NULL)
    {
        cout << "Deleting: " << *front << endl;
        passBook->popFront();
    }
}

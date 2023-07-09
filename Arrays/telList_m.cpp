#include "telList.h"

bool TelList::append(const string &name, const string &telNo)
{
    if (count < 100)
    {
        Element temp;
        temp.name = name;
        temp.telNo = telNo;
        v[count++] = temp;
        return true;
    }
    return false;
}

void TelList::print(int i)
{
    if (i < MAX)
    {
        cout << "---------------------------------------------------" << endl;
        cout << "name : " << v[i].name << endl;
        cout << "telephone number : " << v[i].telNo << endl;
        cout << "---------------------------------------------------" << endl;
    }
    else
        cout << "give valid number" << endl;
}
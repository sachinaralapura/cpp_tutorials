#include "Ledger.h"
#include <random>
#include <ctime>
Ledger::Ledger(const int *arr)
{
    for (int i = 0; i < 100; i++)
    {
        measure[i] = *arr;
        arr++;
    }
}

Rupee Ledger::getTotalData() const
{
    Rupee temp;
    for (int i; i < 100; i++)
    {
        temp += (double)(measure[i].Data); // Ledger class can access the private members of 'Rupee'
    }                                      // because Ledger class is the friend class of Rupee class
    return temp;
}

void Ledger::printAll() const
{
    for (int i = 0; i < 100; i++)
    {
        measure[i].print(cout);
    }
}

int main()
{
    const int ARRAY_SIZE = 100;
    int myArray[ARRAY_SIZE];
    std::srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        myArray[i] = std::rand();
    }
    Ledger l1(myArray);
    l1.printAll();
}
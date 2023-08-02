#include "Rupee.h"
class Ledger
{
private:
    Rupee measure[100];
public:
    Ledger(const int *arr);
    Rupee getTotalData() const;
    void printAll() const;
};




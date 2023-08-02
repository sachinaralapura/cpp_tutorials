#include "Rupee.h"
#include <fstream>
ostream &operator<<(ostream &os, const Rupee &rup);
int main(int argc, char const *argv[])
{
    // array of currency
    Rupee currency[] = {
        Rupee(100, 10),
        23.0,
        Rupee(10, 34),
        Rupee(23, 65),
        Rupee(1000, 34),
        2,
        3};

    // ------------ opening the file ---------------------
    ofstream file;
    file.open(argv[1], ios::out|ios::app);

    // ---------------- calculating the sum of all rupees ------------------

    Rupee total;
    for (int i = 0; i < 5; i++)
    {
        total += currency[i]; // overloading +=
        currency[i].print(file);
    }
    total.print(cout);

    //---------------------------------------------------------------------------

    Rupee newRupee(-currency[0]); // copy constructor
    newRupee.print(cout);

    // -------------------------------------------------------------------------

    newRupee = -currency[4];   // -> standard assignment.
    newRupee -= 234;  // implicit type conversion // -> Can add int or double , this is possible cause of constructor which create "Rupee"
    newRupee = newRupee + 123; // object from int or double types
    newRupee += (Rupee)343.23; // explicit type conversion;
    newRupee.print(cout);

    //------------------------------- using global operator function -----------------------------

    (currency[1] + currency[1]).print(cout);
    (45.34 + currency[2]).print(cout); // conversion of int or double to Euro is performed for both operands now.

    // ------------------------ using friend operator function * ---------------------------------
    (currency[5] * currency[6]).print(cout);
    (2 / currency[5]).print(cout);

    // ------------------------------- overloading subscript function  ----------------------------

    //  Rupee *ptrCur ;
    // for(ptrCur = currency; ptrCur < currency + 5*sizeof(Rupee); ptrCur+=sizeof(Rupee))
    //     cout << *(ptrCur);

    for (int i = 0; i < 5; i++)
        file << currency[i];
    

    return 0;
}

#include "dynamic.h"
#include "../operatorOverLoad/Rupee.h"
int main(int argc, char const *argv[])
{
    // ------------ using 'new' keyword --------------------
    int a = 32;
    int *ptr = new int(a); // or int *ptr = new int;
    ++(*ptr) = 33;         // assigning new value

    // ------------------- using 'delete' keyword ---------
    delete ptr; // ok
    // int* newptr = &a;
    // delete newptr;  // error :the object is not dynamically allocated

    // -------------------DYNAMIC STORAGE ALLOCATION FOR CLASSES ------------

    Rupee *newRupee = new Rupee;
    *newRupee = 100;
    newRupee->print(cout);
    delete newRupee;

    Rupee *ptrRupee = new Rupee;
    Rupee *ptrRupee2 = new Rupee(*ptrRupee);

    // ----------------- array of Rupee class ----------------------

    Rupee *rupeeArr = new Rupee[10];
    
    return 0;
}

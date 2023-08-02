/*
C++ uses the new and delete operators to allocate and release memory, and this
means that objects of any type can be created and destroyed.

----------------------------- Calling new for Fundamental Types -------------------------------------

    'new' operator expects type of the object as argument
     ________________________
    |Syntax: ptr = new type; |  return type pointer to new object
    |________________________|

    The 'new' operator creates an object of the specified type and returns the address of that object.

    If there is not enough memory to allocate 'new handler' is called;
    older version compiler returns 'NULL'

---------------------- DYNAMIC STORAGE ALLOCATION FOR CLASSES -----------------------------------

    A call to new for a class is not much different from a call for a fundamental type.
    ________________________________________
   |   Example: Rupee* pRupee = new Rupee;  |
   |________________________________________|

   When an object that was created dynamically is destroyed, the delete operator makes
    sure that the object is cleaned up. The destructor is first called, and only then is the
    memory space released.
        hen you call delete
    you must ensure that the pointer is addressing a dynamic object or that you are dealing
    with a NULL pointer.

------------------------------- DYNAMIC STORAGE ALLOCATION FOR ARRAYS -----------------------------

    Imagine you are compiling a program that will store an unknown quantity of elements in
    an array. Your best option is to let the program create the array dynamically. An array of
    this type is known as a dynamic array.

    The new[ ] operator is available for creating dynamic arrays.
     __________________________________
    | Syntax: vekPtr = new Type[cnt];  |
    |__________________________________|

    -------- The delete[] Operator -------

    The braces []
    tell the compiler to release the whole array, and not just a single array element.
     __________________________
    |   Example: delete[] pk;  |
    |__________________________|

    If is array is of class type. The destructor belonging to the current
    class is called for each array element.
*/

#include <iostream>
using namespace std;

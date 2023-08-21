/*
■ POINTER TO POINTERS
    -Pointer variables are objects that have an address in memory, and this means you can use
     pointers to address them

Generating Pointer Arrays Dynamically
        Example: Account** ptr = new Account*[400];
        The pointer 'ptr' is now pointing at the first pointer in the array with a total of 400
        Account* type pointers.

Pointer Arrays as Arguments
       Example: void accSort( Account **kptr, int len);
    You can use the kptr parameter to manipulate a pointer array whose length is stored in
    the second parameter, len. After calling
        Example: accSort( ptr, 100);
    Instead of Account **kptr you can also use the equivalent form Account *kptr[].

VARIABLE NUMBER OF ARGUMENTS
    -C++ allows you to define functions that allow a variable number of arguments. One
    example of a function of this type is the standard C function printf()
    -Functions with a variable number of arguments always expect a fixed number of "obligatory arguments" (at least one ) and
    a variable number of "optional arguments"
    -The optional arguments are represented by three dots ... in the parameter list.
    - The optional arguments are accessed via a pointer, the so-called argument pointer,

■ POINTERS TO FUNCTIONS
    -In C++ the name of a function is a constant pointer to that function.
    -There are many uses for pointers to functions. You can save them in an array to form a jump table.
    -A pointer to a function can also be passed as an argument to another function.

Declaring Pointers to Functions
       _______________________________________________
      |  Syntax: type (* funcptr)( parameter_list );  |
      |_______________________________________________|

    This defines the variable 'funcptr', which can store the address of a function. The function has the
    type "type" and the parameter list stated.

    Example:    bool compare(double, double); // Prototype
                bool (*funcptr)(double, double);
                funcptr = compare;
                (*funcptr)(9.1, 7.2);       calling function using pointer

    Calling (*funcptr)() is now equivalent to calling compare().

    -a function cannot return a function or an array , but it can return a pointer to a function or an array.


■ The typedef Keyword
    - C++ allows you to give types a new name using the keyword typedef.
        Example: typedef unsigned char BYTE;

            This defines the type name BYTE, which can then be used as an abbreviation of the unsigned char type.

    - Type names are normally uppercase, although this is not mandatory.
    - Type definitions do not allocate memory and do not create a new type. They simply introduce a new name for an existing type.

        Example: typedef char* (*PTR_TO_FUNC)();
        The type name PTR_TO_FUNC is an abbreviation for the type “pointer to a function that returns a pointer to char.”

        The declaration

        Example: PTR_TO_FUNC search; 
        
        is then equivalent to

        char* (*search)();




*/

#include "../Account/account.h"

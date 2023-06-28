#include "account.h"
int main()
{
    Account a("aaa", 123456, 123);
    const Account b(a); // copy constructor;  // b have different address 

    Account* const thiss = &a;    // this pointer; 
    

    

    // When a method is called, it is passed a hidden argument containing the address of the current
    // object. The address of the current object is available to the method via the constant pointer 'this'.
    //(const Account* ptrAcc = &a;)    this constant pointer
    // there is a difference between (const Account* ptrAcc) and (Account* const ptrAcc )
    //we can use the this pointer within a method to address an object member example
    // this->balance or (*this).balance
    // this->isEmpty() or (*this).isEmpty();

    //The compiler implicitly creates an expression of this type if only a member of the current object is supplied.example
    // balance += 1  is equivalent to     this->balance += 1;

    return 1;
}
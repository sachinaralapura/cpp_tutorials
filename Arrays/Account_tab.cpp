/*
Array elements can also be objects of a class type. The array is known as a class array
Example : Result temperatureTab[24];
👉Class arrays can only be defined without explicit initialization if a default constructor exists for the class.

👉 Explicit Initialization
    Example: Result temperatureTab[24] ={
                                            Result( -2.5, 0,30,30),
                                            Result( 3.5), // At present time
                                            4.5,// Just so
                                            Result( temp1),// Copy constructor
                                            temp2
                                            // Just so
                                        };
    👉 Instead of using a constructor with one argument, you can simply supply the argument.
*/
#include "../Account/account.h"
Account kiran("kiran kumar", 35456345645, 34222);
Account accountArr[] = {
    Account("Tang, Sarah", 123000, 2500.0),
    Account("Smith, John", 543001),
    Account(),              //default constructor
    kiran
};

int main(){
    cout << sizeof(Account) << endl;
    cout << sizeof(accountArr) << endl;
    accountArr[1].setName("sachin");
    accountArr[1].display();
}
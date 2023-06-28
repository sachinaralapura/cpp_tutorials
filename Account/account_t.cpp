#include "account.h"

//---------------------- main() -------------------------

bool getAccount(Account *pAccount);

Account manager("manager", 111111, 100); // global Account object
int main()
{
    Account modi;
    // local Account object ||| => if the object is declared as "const" no methods can be accessed
    // even the methods that only reads , because compiler cannot decided which is 'read-only' method
    // To identify method method as read-only append 'const' in method declaration and defination(example getBalance method)

    Account yogi("yogi", 23534);     // initialization with the help of constructor
    modi.init("Modi", 234543, 1200); // init modi

    Account &refAcc = modi; // referencing modi

    refAcc.display(); // displaying accounts
    yogi.display();

    Account saving, *ptr = &saving;      // pointer to Account class object;
    ptr->init("elon", 495347, 23534546); // using arrow function to initilize
    //(*ptr).display();                  // using dot operator to display
    // equivalent to ptr->display

    if (getAccount(ptr))
    {
        ptr->display();
    }

    //------------ using set and getMethods -------------------
    cout << "------------set and get methods --------------------\n\n";

    modi.setName("Narendra Modi");  // setting new name for modi object
    cout << " Account Holder :" << modi.getName() << endl << "\n"; // get name of object and printing

    // ------------------ using Read-only methods ----------------
    cout << "------------Read-only objects --------------------\n\n";

    const Account fixed("unknown", 36454544, 34524);
    cout << " Accout Balance : " << fixed.getBalance()<< "\n" << endl;
}

// destructor will be called in a order opposite of creation of object
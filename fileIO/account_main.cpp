#include "../Account/account.h"
// #include "fileOperation.h"

Account accountArr1[4];

int main(int argc, char const *argv[])
{ // opening two files

    ofstream outFile(argv[1], ios::in | ios::binary);
    ifstream inFile(argv[1], ios::out | ios::binary);

    // creating Account object
    Account myAcc("sachin", 344564, 345456456);
    myAcc.writeToFile(outFile);
    outFile.close();

    Account otherAcc;
    otherAcc.readFromFile(inFile);
    otherAcc.display();
    inFile.close();
    return 0;
}

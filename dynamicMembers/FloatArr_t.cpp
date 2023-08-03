#include "dynamicMem.h"
int main(int argc, char const *argv[])
{
    ofstream f1;
    f1.open("new.txt", ios::out);
    if (!f1)
        cout << "eerror" << endl;

    FloatArr arr1(5, 69), arr2(arr1); // copy constructor
    FloatArr newArr(5);
    newArr = arr1; // assignment
    cout << arr1;
    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    // fstream file(argv[1]);
    fstream file;
    file.open(argv[1], ios::in | ios::out | ios::app); // out -> write
    if (!file)                                         // file.fail()            // in  -> read
    {                                                  // app -> append
        cerr << "error in reading file";
        return 1;
    }
    int count = 0;
    char line[80];
    char *ptr = line;
    cout << ios::failbit << endl;
    cout << (ios::in & ios::out) << endl;
    while (file.getline(ptr, 80))
    {
        cout << line << endl;
        ptr = line;
        if ((++count) > 10)
        {
            count = 0;
            cout << "\n\t ---- <return> to continue ---- " << endl;
            cin.sync();
            cin.get();
        }

        if (file.eof())
        {
            cerr << " End of the file has occured " << endl;
        }
    }

    return 0;
}

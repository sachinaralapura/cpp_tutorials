#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char const *argv[])
{
    fstream myfile;
    myfile.open("File.h", ios::in | ios::out);
    if (!myfile)
    {
        cerr << "error in reading file";
        return 1;
    }
    myfile.seekp(0L, ios::end);
    unsigned long count = myfile.tellg();
    cout << count << endl;

    return 0;
}

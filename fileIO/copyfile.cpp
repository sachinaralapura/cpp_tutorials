#include "fileOperation.h"
int main(int argc, char const *argv[])
{
    if (argc < 2 || argc > 3)
    {
        cerr << "Call: fcopy1 source [ destination ]" << endl;
        return 1;
    }

    ifstream infile;
    infile.open(argv[1]);

    if (!infile)
    {
        fileOpenError(argv[1]);
    }

    if (argc == 2)
        copyFile(infile, cout);
    else
    {
        ofstream outfile;
        outfile.open(argv[2]);
        if (!outfile.is_open())
            fileOpenError(argv[2]);
        copyFile(infile, outfile);
        outfile.close();
    }

    infile.close();
    return 0;
}

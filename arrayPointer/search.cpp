#include <iostream>
#include <string>

using namespace std;
#define MAX 200

namespace Myscope
{
    char *searchPat(const char *line, const char *pattern);
}

char line[500];
char pat[] = "is";
int main()
{
    cout << "enter pattern" << endl;
    cin >> pat;
    int lineNum = 0;
    while (cin.getline(line, MAX))
    {
        ++lineNum;
        if (Myscope::searchPat(line, pat) != NULL)
        {
            cout.width(3);
            cout << lineNum << " : " << line << endl;
        }
    }

    return 0;
}
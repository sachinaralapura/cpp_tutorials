#include <iostream>
using namespace std;
extern char **environ; // Declaration for the environment variable
int main(int argc, char *argv, char **env)
{
    char line[100];
    char *ptrLine = line;
    char ch;
    while ((ch = cin.get()) != '\n')
    {
        *(ptrLine++) = ch;
    }
    ptrLine--;
    while (ptrLine >= line)
    {
        cout << *ptrLine--;
    }
    int i = 0;
    while (*env != NULL)
    {
        cout << *env << endl;
        *env++;
    }
    cout << "Environment variables:" << std::endl;
    for (char **envir = environ; *envir != nullptr; ++envir)
    {
        cout << *envir << endl;
    }
}
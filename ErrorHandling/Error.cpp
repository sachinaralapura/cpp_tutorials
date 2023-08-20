/*
Some common causes of errors are
    ■ division by 0, or values that are too large or small for a type
    ■ no memory available for dynamic allocation
    ■ errors on file access, for example, file not found
    ■ attempt to access an invalid address in main memory
    ■ invalid user input



*/

#include <string>
#include <iostream>
using namespace std;
void check(int, int) throw(MyError);

class MyError
{
private:
    string message;

public:
    MyError(const string &s) : message(s) {}
    const string &getMessage() const { return message; }
};

int main()
{
    int x, y;
    try
    {
        cout << "enter two number" << endl;
        cin >> x >> y;
        check(x, y);
    }
    catch (MyError &error)
    {
        cerr << error.getMessage();
    }
    return 0;
}

void check(int x, int y) throw(MyError)
{
    if (y == 0)
        throw MyError("Denominator cannot be zero");
}
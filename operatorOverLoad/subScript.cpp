// subScript.cpp
// A simple class to represent an array
// with range checking.
// --------------------------------------------------

#include <iostream>
#include <cstdlib> // For exit()
using namespace std;
#define MAX 100

class FloatArr
{
private:
    float v[MAX];

public:
    float &operator[](int i);
    static int maxIndex() { return MAX - 1; }
};

float &FloatArr::operator[](int i)
{
    if (i < 0 || i >= MAX)
    {
        cerr << "\nFloatArr: Outside of range!" << endl;
        exit(1);
    }
    return v[i];
}

int main()
{
    cout << "\n An array with range checking!\n"
         << endl;
    int i;
    FloatArr random; // create a array of float
    for (i = 0; i < FloatArr::maxIndex(); i++)
    {
        random[i] = (rand() - RAND_MAX / 2) / 100.0F;
    }

    cout << "\nEnter indices between 0 and "
         << FloatArr::maxIndex() << "!"
         << "\n (Quit by entering invalid input)"
         << endl;

    while (cout << "\nIndex: " && cin >> i)
        cout << i << ". element: " << random[i];
}
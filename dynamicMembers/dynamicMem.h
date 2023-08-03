/*
Depending on the amount of data an application program really has to handle, memory is allocated as
required while the application is running. In order to do this the class needs a pointer to the
 dynamically allocated memory that contains the actual data. Data members of this kind are also known as
"dynamic members" of a class.

// A class representing dynamic arrays of floats.
// ---------------------------------------------------
class FloatArr
{
    private:
        float* arrPtr;    // Dynamic member
        int max;          // Maximum quantity without// reallocating new storage.
        int cnt;         // Number of present elements
    public:
        // Public methods here
};


A standard copy constructor is normally sufficient for a class. However, simply copy-
ing the data members would serve no useful purpose for objects containing dynamic
members. This would merely copy the pointers, meaning that the pointers of several dif-
ferent objects would reference the same place in memory.

Each class comprises four implicitly defined default methods, which you can replace with
your own definitions:
■ the default constructor and the destructor
■ the copy constructor and the standard assignment


■ you need to overload the default assignment for classes containing
dynamic members.

■ release the memory referenced by the dynamic members
■ allocate sufficient memory and copy the source object’s data to that memory.
■ When implementing the operator function you must avoid self assignment, which would
read memory areas that have already been released.


*/

// floatArr.h : Dynamic array of floats.
// ---------------------------------------------------
#ifndef _FLOATARR_
#define _FLOATARR_
#include <iostream>
#include <fstream>
using namespace std;
class FloatArr
{
private:
    float *arrPtr; // Dynamic member
    int max;       // maximum quantity
    int current;   // current number of array elements

public:
    FloatArr(int n = 256); // default constructor
    FloatArr(int n, float val);
    FloatArr(const FloatArr &src);            // copy constructor
    FloatArr &operator=(const FloatArr &src); // assignment ;
    ~FloatArr();
    int length() const { return current; }
    float &operator[](int i); // subscript operator
    float operator[](int i) const;
    void expand(int n);
    void append(float val);                               // append value val
    void append(const FloatArr &v);                       // append
    bool remove(int pos);                                 // delete positin at pos
    void display(ostream &os, int from = 0, int to = -1); // display every
    friend ostream &operator<<(ostream &os, const FloatArr &v);
};
//-------------------------------------------------------------------

FloatArr::FloatArr(int n)
{
    this->max = n;
    this->current = 0;
    this->arrPtr = new float[max];
}

//-------------------------------------------------------------------

FloatArr::FloatArr(int n, float val)
{
    this->max = n;
    this->current = n;
    this->arrPtr = new float[max];
    for (int i = 0; i < max; i++)
    {
        arrPtr[i] = val;
    }
}

//-------------------------------------------------------------------

FloatArr::FloatArr(const FloatArr &src)
{
    this->max = src.max;
    this->current = src.current;
    arrPtr = new float[max];
    for (int i = 0; i < current; i++)
        this->arrPtr[i] = src.arrPtr[i];
}

//-------------------------------------------------------------------

FloatArr &FloatArr::operator=(const FloatArr &src)
{
    if (this != &src) // no self assignment | arr1 = arr1;
    {
        max = src.max;
        current = src.current;
        delete[] arrPtr;
        arrPtr = new float[max];
        for (int i = 0; i < current; i++)
            this->arrPtr[i] = src.arrPtr[i];
    }
    return *this;
}

//-------------------------------------------------------------------

FloatArr::~FloatArr()
{
    delete[] arrPtr;
}

//-------------------------------------------------------------------

float &FloatArr::operator[](int i)
{
    if (i < 0 || i >= current)
    {
        cerr << "\n class FloatArr: Out of range! ";
        exit(1);
    }
    return arrPtr[i];
}

//-------------------------------------------------------------------

float FloatArr::operator[](int i) const
{
    if (i < 0 || i >= current)
    {
        cerr << "\n class FloatArr: Out of range! ";
        exit(1);
    }
    return arrPtr[i];
}

//-------------------------------------------------------------------

void FloatArr::expand(int newMax)
{
    if (newMax == max)
        return;
    max = newMax;
    if (newMax < current)
        current = newMax;
    float *temp = new float[newMax];
    for (int i = 0; i < current; ++i)
        temp[i] = arrPtr[i];
    delete[] arrPtr;
    arrPtr = temp;
}

//-------------------------------------------------------------------

void FloatArr::append(float val)
{
    if (current + 1 < max)
        expand(current + 1);
    arrPtr[current++] = val;
}

//-------------------------------------------------------------------

void FloatArr::append(const FloatArr &v)
{
    if (current + v.current > max)
        expand(current + v.current);
    int count = v.current;
    for (int i = 0; i < count; i++)
        arrPtr[current++] = v.arrPtr[i];
}

//-------------------------------------------------------------------

bool FloatArr::remove(int pos)
{
    if (pos >= 0 && pos < current)
    {
        for (int i = pos; i < current - 1; i++)
            arrPtr[i] = arrPtr[i + 1];
        current--;
        return true;
    }
    else
        return false;
}

//-------------------------------------------------------------------

void FloatArr::display(ostream &os, int from, int to)
{
    if (to == -1)
        to = current - 1;
    if ((from >= 0 && from < current) && (to >= 0 && to < current))
        for (int i = from; i < to + 1; i++)
        {
            os << arrPtr[i] << endl; // read the array values
        }
    else
        cout << "invalid index" << endl;
}

ostream &operator<<(ostream &os, const FloatArr &v)
{
    int w = os.width();
    for (float *i = v.arrPtr; i < v.arrPtr + v.current; i++)
    {
        os.width(w);
        os << *i;
    }

    return os;
}
#endif
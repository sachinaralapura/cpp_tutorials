// matrix.h: Representing dynamic matrices.
// ---------------------------------------------------
#include <stdexcept>
#include <iostream>
using namespace std;

class Row
{
private:
    double *ro;
    int size;

public:
    Row(int s)
    {
        size = s;
        ro = new double[s];
    }
    ~Row()
    {
        delete[] ro;
    }

    double &operator[](int i) 
    {
        if (i < 0 || i > size)
            throw out_of_range("Column index: Out of Range\n");
        else
        {
            return ro[i];
        }
    }
};

class Matrix
{
private:
    Row **mat;
    int rows;
    int cols;

public:
    Matrix(int row, int col)
    {
        rows = row;
        cols = col;
        mat = new Row *[rows];
        for (int i = 0; i < rows; i++)
        {
            mat[i] = new Row(cols);
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
            delete mat[i];
        delete[] mat;
    }
    int getLines() const { return rows; }
    int getCols() const { return cols; }

    Row &operator[](int i) 
    {
        if (i < 0 || i > rows)
            throw out_of_range("Row index: Out of Range\n");
        else
            return *mat[i];
    }
};
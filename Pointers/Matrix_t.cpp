#include "Matrix.h"

int main(int argc, char const *argv[])
{

    try
    {
        Matrix mat1(2, 2);
        mat1[0][0] = 1;
        cout << mat1[0][0];

        mat1[2][2] = 34;
    }
    catch (out_of_range& e)
    {
        cout << e.what();
    }
    return 0;
}

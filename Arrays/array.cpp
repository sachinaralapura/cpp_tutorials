/*Arrays can be initialized when you define them.
A list containing the values for the individual array elements is used to initialize the array:

=> If the array length is explicitly stated in the definition and is larger than the number of initial values,
any remaining array elements are set to zero.

=> If, in contrast, the number of initial values exceeds the array length, the surplus values are ignored.
---------------------------------------------------------------------------------------------------------------
=>Locally defined arrays are created on the stack at program runtime. You should there-
fore be aware of the following issues when defining arrays:

    👉 Arrays that occupy a large amount of memory (e.g., more than one kbyte) should be defined as global or static.
    👉 Unless they are initialized, the elements of a local array will not necessarily have
       a definite value. Values are normally assigned by means of a loop 
---------------------------------------------------------------------------------------------------------------

    You cannot assign a vector to another vector. However, you can overload the assign-
ment operator within a class designed to represent arrays.

*/
#include <array.h>

int main()
{
    const int MAX = 10;
    float arr[MAX], x;
    int i, cnt;

    cout << "Enter up to 10 numbers \n"
         << "(Quit with a letter):" << endl;
    for (i = 0; i < MAX && cin >> x; i++)
    {
        arr[i] = x;
    }
    cnt = i;
    for (i = 0; i < cnt; i++)
    {
        cout << arr[i] << setw(10);
    }
}
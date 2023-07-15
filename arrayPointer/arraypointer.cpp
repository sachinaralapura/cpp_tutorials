// #include <iostream>
// void add(int *x){
//     std::cout << *x << std::endl;
// }
// int main(){
//     int *p ;
//     int **pp;
//     int x(5);
//     add(&x);
//     p = &x;
//     pp = &p;

//     std:: cout << "the address of a is : "  << &x << std::endl;
//     std::cout << "The address of the pointer p : " << p << std::endl;
//     std::cout << "the value of *pp " << *pp << std::endl;
//     std::cout << "The address of the pointer pp : " << pp << std::endl;
//     std::cout <<"the value of  *p : "<< *p << std::endl;
//     std::cout <<"the value of  *p + 5 : "<< (*p+5) << std::endl;
//     std::cout << "the value of **pp : " << **pp << std::endl;
//     return 1;
// }

#include <iostream>
#include <string.h>
using namespace std;

// user defined function for strcpy;
void stringCopy(char *source, char *dest);
int main()
{
    // int a = 24;
    // int *ptr = &a;
    // cout << "address of 'a' :" << &a << endl;
    // cout << "address of ptr :" << &ptr << endl;
    // cout << "content of ptr :" << ptr << endl;
    // cout << "content of *ptr :" << *ptr << endl;

    char town[] = "Bangalore";
    char *townPtr;
    townPtr = town;
    cout << "&town[0] " << &town[0] << endl
         << "town " << town << endl
         << "townPtr " << townPtr << endl
         << "*townPtr " << *townPtr << endl
         << "(void *)town " << (void *)town << endl        // typeless pointer
         << "(void *)townPtr " << (void *)townPtr << endl; // typeless pointer

    cout << "\n--------------------------------------------------------\n";

    int arr[5] = {3, 4, 7, 8, 33};
    cout << "\nAddress and value of array elements:" << endl;
    for (int i = 0; i < 5; i++)
        cout << "Address: " << (void *)(arr + i) << "   Value : " << *(arr + i) << endl;
    // arr points to arr[0] ,arr+1 points to next element of array
    // *(arr + i) is the arr[i] array element
    // (void * )(arr + i) is the address of the arr[i]

    // For any given integer, i, the following expressions are thus equivalent:
    // &arr[i]
    // arr + i
    // ptr + i

    // The following thus represent equivalent values:
    // arr[i]
    // *(arr + i)
    // *(ptr + i)
    // ptr[i]

    // The compiler translates arr[i] to *(arr + i)

    // subtraction with two pointers, resulting in an int value that represents the number of array elements between the
    // pointers. ex  int  diff = ptr - v;

    // comparisons can be performed with two pointers of the same type.
    // example pv >= v;

    // If an array name is passed as an argument when calling a function, the function actually
    // receives the address of the first array element.

    // In the case of C strings, the length is derived implicitly from the
    // position of the terminating null character. In most other cases the length must be supplied explicitly(array of objects)
    char source[] = "sachin";
    char dest[20];
    stringCopy(source, dest);
    dest[6] = 'A';
    dest[7] = 'S';
    dest[8] = '\0';
    cout << dest << endl;

    // multidimensional arrays
    int mulArr[][10] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
        {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
        {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
        {71, 72, 73, 74, 75, 76, 77, 78, 79, 80},
        {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
        {91, 92, 93, 94, 95, 96, 97, 98, 99, 100}};

    int *ptrarr;

    cout << mulArr[1] << endl;
    cout << "mulArr " << mulArr << endl;
    int i = 0;
    while (i < 10)
    {
        cout << "mulArr[" << i << "]  " << mulArr[i] << endl;
        // cout << "mulArr[" <<  i << "]  " << mulArr+i << endl;
        i++;
    }

    for (int ii = 0; ii < 10; ii++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << "mulArr[" << ii << "][" << j << "] " << mulArr[ii][j] << "\t";
        }
        cout << endl;
    }

    cout << "---------------------------------------------------------------------------\n";
    for (int ii = 0; ii < 10; ii++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << "mulArr[" << ii << "][" << j << "] " << *(mulArr[ii] + j) << "\t" << (mulArr[ii] + j) << "\t";
        }
        cout << endl;
    }

    cout << "---------------------------------------------------------------------------\n";
    ptrarr = mulArr[0];
    for (int ii = 0; ii < 40; ii += 10)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << "mulArr[" << ii << "][" << j << "] " << *(ptrarr + ii + j) << "\t ";
        }
        cout << endl;
    }
    cout << "---------------------------------------------------------------------------\n";

    cout << *ptrarr << endl;
}

void stringCopy(char *source, char *des)
{
    while ((*des++ = *source++) != '\0')
        ;
}
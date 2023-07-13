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
    // position of the terminating null character. In most other cases the length must be sup-
    // plied explicitly(array of objects)
    town[0] = 'X';
    cout << town;
    return 0;
}
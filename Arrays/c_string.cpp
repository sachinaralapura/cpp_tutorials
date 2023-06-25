/*
Arrays whose elements are of char type are often used as data communication buffers.
One way of representing a string is to store the string and the terminating null character '\0' in a char array.
When you define an array, you can use a string constant to initialize the array.

Example: char text[40] = "Hello world";
Example: char name[] = "Hugo"; or char name[] = { 'H','u','g','o','\0' };

In C++, strings of this type are referred to as C strings to distinguish them
from objects of the string class,functionality of the string class is not available for C string

The standard functions of the C language, such as strlen(), strcpy(), strcmp(),
and others, are available for C strings.

*/
#include "array.h"

char header[] = "\n *** C Strings ***\n\n";
int main(int argc, char const *argv[])
{
    // char name[] = "sachin";
    // char init[] = "aralapura";
    // strcpy(name, init);
    // cout << sizeof(init) << endl;
    // cout << strlen(name) << endl;
    // cout << name << endl;

    char hello[30] = "Hello ", name[20], message[500];
    cout << header << "Your first name: ";
    cin >> setw(20) >> name;
    // Enter a word.
    strcat(hello, name);
    // Append the name.
    cout << hello << endl;
    cin.sync();
    // No previous input.
    cout << "\nWhat is the message for today?"
         << endl;
    cin.getline(message, 500); // Enter a line with a max of 79 characters.
    if (strlen(message) > 0)
    // If string length is
    {
        // longer than 0.
        for (int i = 0; message[i] != '\0'; ++i)
            cout << message[i] << ' ';
        // Output with
        cout << endl;
        // white spaces.
    }
    return 1;
}

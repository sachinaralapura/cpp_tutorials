#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
#define DELAY 1000000L
// Output delay
inline void cls()
{
    cout << "\033[2J\n";
}
// Clear screen
inline void locate(int z, int s)
// Put cursor in row z
{
    // and column s
    cout << "\033[" << z << ';' << s << 'H';
}
char msg[] = "* * *B R E A K * **";
int main()
{
    int i, start = 0, len = strlen(msg);
    cls();
    locate(24, 20);
    // Row 24, column 20
    cout << "--- Press interrupt key to terminate (^C) ---";
    while (true)
    {
        locate(12, 25);
        // Row 12, column 25
        i = start;
        // Output from index start
        do
        {
            cout << msg[i++];
            i = i % len;
            // if( i == len) i = 0;
        } while (i != start);
        cout << endl;
        // Outputs buffer to screen
        // Wait in short
        for (int count = 0; count < DELAY; ++count)
            ;
        ++start;
        // For next output
        start %= len;
        // start = start % len;
    }
    cls();
    return 0;
}
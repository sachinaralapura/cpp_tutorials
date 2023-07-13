#include <iostream>
#include "Enum/enum.h"
#include <string>
#include <ctime>
using namespace std;
inline void wait_t(int sec)
{ // wait_t sec second
    time_t end = time(NULL) + sec;
    while (time(NULL) < end)
        ;
}

Lights A1, A2;
enum
{
    greenTime1 = 10,
    amberTime1 = 1,
    greenTime2 = 14,
    amberTime2 = 2
};

int main()
{
    cout << "Simulating two traffic lights!\n\n"
         << "Terminate this program with <Ctrl>+<C>!\n"
         << endl;
    cout << " 1. Light    2. Light\n "
         << "---------------------------" << endl;
    while (true)
    {
        A1.setState(Lights::red);
        // A1 = red
        A2.setState(Lights::amber);
        wait_t(amberTime2);
        cout << "   ";
        A2.setState(Lights::green);
        wait_t(greenTime2);
        cout << "   ";
        A2.setState(Lights::amber);
        wait_t(amberTime2);
        A1.setState(Lights::amber);
        // A2 = red
        A2.setState(Lights::red);
        wait_t(amberTime1);
        A1.setState(Lights::green);
        wait_t(greenTime1);
        A1.setState(Lights::amber);
        wait_t(amberTime1);
    }
    return 0;
}
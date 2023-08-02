#include "DayTime.h"

void swapDay(DayTime &t1, DayTime &t2);
const DayTime *currentTime();
int main()
{
    DayTime day1(22, 56, 17), day2; // initializing day1 using constructor;
    day2.setTime(12, 51, 20);       // initializing day2 using setTime() method;

    swapDay(day1, day2); // swaping day1 and day2 using swapDay() function;
    day1.swapDay(day2);  // swaping day1 and day2; using swapDay() method;

    if (day1.isLess(&day2))
        cout << "day1 is less then day2" << endl;
    else
        cout << "day1 is not less then day2" << endl;

    const DayTime constDay(23, 34, 5); // constant object;

    const DayTime *curTime = currentTime();
    curTime->displayTime(cout); //(*curTime).displayTime();

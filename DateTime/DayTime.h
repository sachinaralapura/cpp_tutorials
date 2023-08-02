// DayTime.h
// The class DayTime represents the time in
// hours, minutes and seconds.
// ---------------------------------------------------
#ifndef __DAYTIME__
#define __DAYTIME__
#include <iostream>
#include <ctime>
using namespace std;

class DayTime
{
private:
    short hour, minute, second;
    bool overflow;

public:
    DayTime(int h = 0, int m = 0, int s = 0)
    {
        printf("calling Daytime constructor\n");
        overflow = false;
        if (!setTime(h, m, s))
            hour = minute = second;
    }

    void displayTime(ostream& os) const
    {
        os << "HOUR :" << this->getHour() << endl;
        os << "MINUTE :" << this->getMinute() << endl;
        os << "SECOND :" << this->getSecond() << endl;
    }

    bool setTime(int hour, int minute, int second = 0);
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    int asSeconds() const;
    bool isLess(DayTime *t) const;
    void swapDay(DayTime &t);
};

#endif
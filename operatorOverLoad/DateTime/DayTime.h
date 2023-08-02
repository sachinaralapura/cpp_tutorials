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

    void displayTime() const
    {
        cout << "HOUR :" << this->getHour() << endl;
        cout << "MINUTE :" << this->getMinute() << endl;
        cout << "SECOND :" << this->getSecond() << endl;
    }

    bool setTime(int hour, int minute, int second = 0);
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    int asSeconds() const;
    bool isLess(DayTime *t) const;
    void swapDay(DayTime &t);

    // operator overloading
    bool operator<(const DayTime &t) const // compare *this and t
    {
        return asSeconds() < t.asSeconds();
    }

    DayTime& operator++() 
    {
        cout << "seconds incremented"  << endl;
        second++;
        return *this;
    }
       DayTime& operator++(int) 
    {
        cout << "seconds incremented"  << endl;
        second++;
        return *this;
    }
};

#endif
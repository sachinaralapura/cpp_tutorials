#include "DayTime.h"

bool DayTime::setTime(int hour, int minute, int second)
{
    if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60)
    {
        this->hour = (short)hour;
        this->minute = (short)minute;
        this->second = (short)second;
        return true;
    }
    else
        return false;
}

int DayTime::getHour() const { return hour; }
int DayTime::getMinute() const { return minute; }
int DayTime::getSecond() const { return second; }
int DayTime::asSeconds() const { return (60 * 60 * hour + 60 * minute + second); }
bool DayTime::isLess(DayTime *t) const { return this->asSeconds() < t->asSeconds(); } // passing object by pointers object cannot be modified
void DayTime::swapDay(DayTime &t)
{
    DayTime temp(t);
    t = *this;
    *this = temp;
} // since this is read-only method;

//------------------------------------------------------

void swapDay(DayTime &t1, DayTime &t2)
{
    DayTime temp(t1);
    t1 = t2;
    t2 = temp;
}

//----------------------------returning object reference-------------------------

 DayTime currentTime()
{
    static DayTime curTime; // object must be static since we are returning reference
    time_t sec;             // of the object or else the object will be destroyed after function call
    time(&sec);
    struct tm *ptrTm = localtime(&sec);
    curTime.setTime(ptrTm->tm_hour, ptrTm->tm_min, ptrTm->tm_sec);
    return curTime;
}
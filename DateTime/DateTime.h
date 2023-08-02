// ------------------------------------------------------
// Date.h
// Defining class Date with optimized
// functionality, e.g. range check.
// ------------------------------------------------------
#ifndef _DATE_
// Avoids multiple inclusions.
#define _DATE_
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;
class Date
{
private:
    short month, day, year;

public:
    Date()
    {
        month = day = year = 1;
        // Default constructor
    }
    Date(int month, int day, int year)
    {
        if (!setDate(month, day, year))
            month = day = year = 1; // If date is invalid
    }
    void setDate();
    // Sets the current date
    bool setDate(int month, int day, int year);
    int getMonth() const { return month; }
    int getDay()
        const
    {
        return day;
    }
    int getYear() const { return year; }
    bool isEqual(const Date &d) const
    {
        return month == d.month && day == d.day && year == d.year;
    }
    bool isLess(const Date &d) const;
    const string &asString() const;
    void print(void) const;
};

inline bool Date::isLess(const Date &d) const
{
    if (year != d.year)
        return year < d.year;
    else if (month != d.month)
        return month < d.month;
    else
        return day < d.day;
}
inline bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

// -----------------------------------------------------
void Date::setDate()
// Get the present date and
{
    // assign it to the data members.
    struct tm *dur;
    // Pointer to struct tm.
    time_t sec;
    // For seconds.
    time(&sec);
    dur = localtime(&sec);
    // Get the present time.
    // Initialize a struct of
    // type tm and return a
    // pointer to it.
    day = (short)dur->tm_mday;
    month = (short)dur->tm_mon + 1;
    year = (short)dur->tm_year + 1900;
}

// -----------------------------------------------------
bool Date::setDate(int da, int mn, int yr)
{
    if (mn < 1 || mn > 12)
        return false;
    if (da < 1 || da > 31)
        return false;
    switch (mn)
    // Month with less than 31 days
    {
    case 2:
        if (isLeapYear(yr))
        {
            if (da > 29)
                return false;
        }
        else if (da > 28)
            return false;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (da > 30)
            return false;
    }
    month = (short)mn;
    day = (short)da;
    year = (short)yr;
    return true;
}
// -----------------------------------------------------
void Date::print() const
// Output a date
{
    cout << asString() << endl;
}
// -----------------------------------------------------
const string &Date::asString() const
// Return a date
{
    // as string.
    static string dateString;
    stringstream iostream;
    // For conversion
    // number -> string
    iostream << setfill('0')
             // and formatting.
             << setw(2) << day << '-'
             << setw(2) << month
             << '-' << year;
    iostream >> dateString;
    return dateString;
}

#endif
// _DATE_

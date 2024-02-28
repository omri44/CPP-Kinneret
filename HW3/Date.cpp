#include "date.h"
#include <iostream>

bool Date::ValidMonth(int m)
{
    return m > 0 && m <= 12;
}

bool Date::ValidDay(int d)
{
    return d > 0 && d <= 30;
}

Date::Date()
{
    day = 1;
    month = 1;
    year = 2000;
}

Date::Date(int d, int m, int y)
{
    if(ValidDay(d) && ValidMonth(m) && y > 0)
    {
        day = d;
        month = m;
        year = y;
    }
    else
    {
        day = 0;
        month = 0;
        year = 0;
    }
}

int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }

void Date::setDay(int d)
{
    if(ValidDay(d))
        day = d;
    else
        day = 0;
}
void Date::setMonth(int m)
{
    if(ValidMonth(m))
        month = m;
    else
        month = 0;
}
void Date::setYear(int y)
{
    if(y > 0)
        year = y;
    else
        year = 0;
}

void Date::printDate() 
{
    std::cout << day << "/" << month << "/" << year << std::endl;
}
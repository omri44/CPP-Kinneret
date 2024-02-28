#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    bool ValidMonth(int m);
    bool ValidDay(int d);

public:
    Date();
    Date(int day, int month, int year);
    int getDay();
    int getMonth();
    int getYear();
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    bool operator < (Date &other);
    bool operator > (Date &other);
    bool operator == (Date &other);

    friend ostream &operator << (ostream &os, Date &date);
};

#endif
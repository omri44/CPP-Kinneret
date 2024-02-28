#ifndef TRIP_H
#define TRIP_H

#include "Date.h"
#include <iostream>
using namespace std;

class Trip 
{
private:
    static int tripCount;
    int tripNum;
    char *dest;
    Date date;

    bool ValiDest(char *dest);

public:
    Trip();
    Trip(int tripNum, char *dest, Date &date);
    Trip(Trip &other);
    ~Trip();
    Trip &operator = (Trip &other);

    int getTripNum();
    char *getDest();
    Date getDate();

    void setTripNum(int tripNum);
    void setDest(char *dest);
    void setDate(Date &date);

    bool operator == (Trip& other);

    friend ostream &operator << (ostream &os, Trip &trip);
};

#endif

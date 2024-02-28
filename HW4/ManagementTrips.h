#ifndef MANAGEMENTTRIPS_H
#define MANAGEMENTTRIPS_H

#include "Trip.h"
#include <iostream>
using namespace std;

class ManagementTrips 
{
private:
    Trip **tripArray;
    int index;
    int size;

public:
    ManagementTrips(int capacity);
    ~ManagementTrips();
    void operator += (Trip &trip);
    void operator -= (Date &date);
    bool operator < (Trip &other);
    friend ostream &operator << (ostream &os, ManagementTrips &mt);
};

#endif

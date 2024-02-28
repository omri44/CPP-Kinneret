#include "ManagementTrips.h"
using namespace std;

ManagementTrips::ManagementTrips(int capacity)
{
    size = capacity;
    index = 0;
    tripArray = new Trip*[size];
}

ManagementTrips::~ManagementTrips() 
{
    for (int i = 0; i < index; ++i) 
    {
        delete tripArray[i];
    }
    delete[] tripArray;
}

void ManagementTrips::operator += (Trip &trip) 
{
    if (index < size) 
    {
        tripArray[index++] = &trip;
    }
}

void ManagementTrips::operator -= (Date &date) 
{
    for (int i = 0; i < index; ++i) 
    {
        if ((*tripArray[i]).getDate() == date) 
        {
            delete tripArray[i];
            for (int j = i; j < index - 1; ++j) 
            {
                tripArray[j] = tripArray[j + 1];
            }
            --index;
            --i;
        }
    }
}

bool ManagementTrips::operator < (Trip &other)
{
    return index < other.getTripNum();
}

ostream &operator << (ostream &os, ManagementTrips &mt) 
{
    if (mt.index == 0) 
    {
        os << "The list of trips is empty." << endl;
    } 
    else 
    {
        for (int i = 0; i < mt.index; ++i) 
        {
            os << *mt.tripArray[i] << endl;
        }
    }
    return os;
}

#include "trip.h"
#include <iostream>
#include <cstring>
using namespace std;

bool Trip::ValiDest(char* dest)
{
    for(size_t i = 0; i < strlen(dest); i++)
    {
        if(!isalpha(dest[i]))
            return false;
    }

    return true;
}

Trip::Trip()
{
    dest = new char[8];
    strcpy(dest, "unkown");
}

Trip::Trip(int tn, char* des, Date& date)
{
    if(tripNum> 0 && ValiDest(des))
    {
        tripNum = tn;
        dest = new char[strlen(des) +1];
        strcpy(dest, des);
        date = date;
    }
    else
    {
        tripNum = 0;
        dest = new char[8];
        strcpy(dest, "not good");
        date = Date();
    }
}

Trip::Trip(Trip& other)
{
    tripNum = other.tripNum;
    date = other.date;
    dest = new char[strlen(other.dest) + 1];
    strcpy(dest, other.dest);
}

Trip::~Trip()
{
    delete[] dest;
}

Trip &Trip::operator = (Trip &other)
{
    if (this != &other) 
    {
        delete[] dest;
        
        tripNum = other.tripNum;
        date = other.date;
        dest = new char[strlen(other.dest) + 1];
        strcpy(dest, other.dest);
    }

    return *this;
}

int Trip::getTripNum()
{
    return tripNum;
}

char* Trip::getDest()
{
    return dest;
}

Date Trip::getDate()
{
    return date;
}


void Trip::setDate(Date& d)
{
    date = d;
}

void Trip::setTripNum(int tn)
{
    if (tn > 0)
    {
        tripNum = tn;
    }
    else
    {
        tripNum = 0;
    }
}

void Trip::setDest(char* des)
{
    if (ValiDest(des))
    {
        delete[] dest;
        dest = new char[strlen(des) + 1];
        strcpy(dest, des);
    }
    else
    {
        delete[] dest;
        dest = new char[8];
        strcpy(dest, "invalid");
    }
}

void Trip::printTrip()
{
    cout << "Trip Number: " << tripNum << endl;
    cout << "Destination: " << dest << endl;
    cout << "Date: ";
    date.printDate();
}
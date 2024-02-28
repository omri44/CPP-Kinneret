#include "Trip.h"
#include <cstring>

int Trip::tripCount = 0;

bool Trip::ValiDest(char *dest) 
{
    for (size_t i = 0; i < strlen(dest); i++) 
    {
        if (!isalpha(dest[i]))
        {
            return false;
        } 
    }
    return true;
}

Trip::Trip()
{
    tripNum = ++tripCount;
    dest = new char[strlen("unknown") + 1];
    strcpy(dest, "unknown");
}

Trip::Trip(int tn, char *des, Date &d)
{
    tripNum = tn;

    if (tripNum > 0 && ValiDest(des)) 
    {
        dest = new char[strlen(des) + 1];
        strcpy(dest, des);
        date = d;
    } 
    else 
    {
        tripNum = 0;
        dest = new char[strlen("not good") + 1];
        strcpy(dest, "not good");
        date = Date();
    }
}

Trip::Trip(Trip &other)
{
    tripCount = ++tripCount;
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
        tripNum = ++tripCount;
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

char *Trip::getDest()
{
    return dest;
}

Date Trip::getDate() 
{
    return date;
}

void Trip::setDate(Date &d) 
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

void Trip::setDest(char *des) 
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
        dest = new char[strlen("invalid") + 1];
        strcpy(dest, "invalid");
    }
}

bool Trip::operator == (Trip &other) 
{
    return ((tripNum == other.tripNum) && (date == other.date) && (strcmp(dest, other.dest) == 0));
}

std::ostream &operator<<(ostream &os, Trip &trip) 
{
    os << "Trip Number: " << trip.tripNum << endl;
    os << "Destination: " << trip.dest << endl;
    os << "Date: " << trip.date << endl;
    return os;
}

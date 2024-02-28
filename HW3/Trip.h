#ifndef TRIP_H
#define TRIP_H
#include "date.h"

class Trip
{
    private:
        int tripNum;
        char *dest;
        Date date;
        bool ValiDest(char *dest);
    public:
        Trip();
        Trip(int tripNum, char *dest, Date &d);
        Trip(Trip &other);
        ~Trip();
        Trip &operator = (Trip &other);

        int getTripNum();
        char *getDest();
        Date getDate();

        void setTripNum(int tripNum);
        void setDest(char *dest);
        void setDate(Date &date);

        void printTrip(); 
};

#endif
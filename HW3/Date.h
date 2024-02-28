#ifndef DATE_H
#define DATE_H

class Date
{
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

        void printDate();
};

#endif
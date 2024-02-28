#ifndef BirthdayCake_H
#define BirthdayCake_H

#include <iostream>
#include "Cake.h"
using namespace std;

class BirthdayCake : Cake 
{
    char* description;

    public:
    BirthdayCake(Date expiryDate, double height, double price, int storage, bool glutenFree, char* description);
    BirthdayCake(BirthdayCake &other);
    ~BirthdayCake();
    BirthdayCake &operator = (BirthdayCake &other);

    void setDescription(char* description);
    char* getDescription();

    bool operator == (BirthdayCake &other);
    void operator += (int addCakePrice);

    friend ostream &operator << (ostream &os, BirthdayCake &birthdayCake);
};

#endif
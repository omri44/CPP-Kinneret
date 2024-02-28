#ifndef CAKE_H
#define CAKE_H

#include <iostream>
#include "Date.h"
using namespace std;

class Cake 
{
protected:
    Date expiryDate;
    const int diameter = 10;
    double height;
    double price;
    int storage;
    bool glutenFree;

public:
    Cake();
    Cake(Date expiryDate, double height, double price, int storage, bool glutenFree);
    Cake(Cake &other);
    ~Cake();
    Cake &operator = (Cake &other);

    bool operator == (Cake &other);
    void operator += (int addCakePrice);

    friend ostream &operator << (ostream &os, Cake &Cake);
};

#endif
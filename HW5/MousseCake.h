#ifndef MousseCake_H
#define MousseCake_H

#include <iostream>
#include "Cake.h"
using namespace std;

class MousseCake : Cake 
{
    char* taste;

    public:
    MousseCake(Date expiryDate, double height, double price, int storage, bool glutenFree, char* taste);
    MousseCake(MousseCake &other);
    ~MousseCake();
    MousseCake &operator = (MousseCake &other);

    void setTaste(char* taste);
    char* getTaste();

    bool operator == (MousseCake &other);
    void operator += (int addCakePrice);

    friend ostream &operator << (ostream &os, MousseCake &mousseCake);
};

#endif
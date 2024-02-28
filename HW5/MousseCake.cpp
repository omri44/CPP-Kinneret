#include "MousseCake.h"
#include <cstring>
using namespace std;

MousseCake::MousseCake(Date expiryDate, double height, double price, int storage, bool glutenFree, char* taste)
: Cake(expiryDate, height, price, storage, glutenFree)
{
    this->taste = new char[strlen(taste) + 1];
    strcpy(this->taste, taste);
}

MousseCake::MousseCake(MousseCake &other)
{
    this->expiryDate = other.expiryDate;
    this->height = other.height;
    this->price = other.price;
    this->storage = other.storage;
    this->glutenFree = other.glutenFree;
    this->taste = taste;
}

MousseCake::~MousseCake()
{
    delete [] taste;
}

MousseCake &MousseCake::operator = (MousseCake &other)
{
     if (this != &other) 
    {
        this->expiryDate = other.expiryDate;
        this->height = other.height;
        this->price = other.price;
        this->storage = other.storage;
        this->glutenFree = other.glutenFree;
        this->taste = taste;
    }
    return *this;
}

void MousseCake::setTaste(char *taste) 
{
    delete[] taste;
    this->taste = new char[strlen(taste) + 1];
    strcpy(this->taste, taste);
}

char* MousseCake::getTaste() 
{
    return taste;
}

bool MousseCake::operator == (MousseCake &other)
{
    return ((expiryDate == other.expiryDate) && 
            (height == other.height) && 
            (price == other.price) &&
            (storage == other.storage) &&
            (glutenFree == other.glutenFree) &&
            (taste == other.taste));
}

void MousseCake::operator += (int addCakePrice)
{
    price += addCakePrice;
}

std::ostream &operator << (ostream &os, MousseCake &mousseCake)
{
    os << "Expiry Date: " << mousseCake.expiryDate << endl;
    os << "Destination: " << mousseCake.diameter << endl;
    os << "Height: " << mousseCake.height << endl;
    os << "Price: " << mousseCake.price << endl;
    os << "Storage: " << mousseCake.storage << endl;
    os << "GlutenFree: " << mousseCake.glutenFree << endl;
    os << "Taste: " << mousseCake.taste << endl;

    return os;
}
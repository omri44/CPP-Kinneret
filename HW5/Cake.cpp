#include "Cake.h"
using namespace std;

Cake::Cake()
{
    this->expiryDate = Date();
    this->height = 100;
    this->price = 100;
    this->storage = 100;
    this->glutenFree = true;
}

Cake::Cake(Date expiryDate, double height, double price, int storage, bool glutenFree)
{
    this->expiryDate = expiryDate;
    this->height = height;
    this->price = price;
    this->storage = storage;
    this->glutenFree = glutenFree;
}

Cake::Cake(Cake &other)
{
    this->expiryDate = other.expiryDate;
    this->height = other.height;
    this->price = other.price;
    this->storage = other.storage;
    this->glutenFree = other.glutenFree;
}

Cake &Cake::operator = (Cake &other)
{
    if (this != &other) 
    {
        this->expiryDate = other.expiryDate;
        this->height = other.height;
        this->price = other.price;
        this->storage = other.storage;
        this->glutenFree = other.glutenFree;
    }
    return *this;
}

bool Cake::operator == (Cake &other)
{
    return ((expiryDate == other.expiryDate) && 
            (height == other.height) && 
            (price == other.price) &&
            (storage == other.storage) &&
            (glutenFree == other.glutenFree));
}

void Cake::operator += (int addCakePrice)
{
    price += addCakePrice;
}

std::ostream &operator << (ostream &os, Cake &cake)
{
    os << "Expiry Date: " << cake.expiryDate << endl;
    os << "Destination: " << cake.diameter << endl;
    os << "Height: " << cake.height << endl;
    os << "Price: " << cake.price << endl;
    os << "Storage: " << cake.storage << endl;
    os << "GlutenFree: " << cake.glutenFree << endl;

    return os;
}
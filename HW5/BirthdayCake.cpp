#include "BirthdayCake.h"
#include <cstring>
using namespace std;

BirthdayCake::BirthdayCake(Date expiryDate, double height, double price, int storage, bool glutenFree, char* description)
: Cake(expiryDate, height, price, storage, glutenFree)
{
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}


BirthdayCake::BirthdayCake(BirthdayCake &other)
{
    this->expiryDate = other.expiryDate;
    this->height = other.height;
    this->price = other.price;
    this->storage = other.storage;
    this->glutenFree = other.glutenFree;
    this->description = description;
}

BirthdayCake::~BirthdayCake()
{
    delete [] description;
}

BirthdayCake &BirthdayCake::operator = (BirthdayCake &other)
{
     if (this != &other) 
    {
        this->expiryDate = other.expiryDate;
        this->height = other.height;
        this->price = other.price;
        this->storage = other.storage;
        this->glutenFree = other.glutenFree;
        this->description = description;
    }
    return *this;
}

void BirthdayCake::setDescription(char *description) 
{
    delete[] description;
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

char* BirthdayCake::getDescription() 
{
    return description;
}

bool BirthdayCake::operator == (BirthdayCake &other)
{
    return ((expiryDate == other.expiryDate) && 
            (height == other.height) && 
            (price == other.price) &&
            (storage == other.storage) &&
            (glutenFree == other.glutenFree) &&
            (description == other.description));
}

void BirthdayCake::operator += (int addCakePrice)
{
    price += addCakePrice;
}

std::ostream &operator << (ostream &os, BirthdayCake &birthdayCake)
{
    os << "Expiry Date: " << birthdayCake.expiryDate << endl;
    os << "Destination: " << birthdayCake.diameter << endl;
    os << "Height: " << birthdayCake.height << endl;
    os << "Price: " << birthdayCake.price << endl;
    os << "Storage: " << birthdayCake.storage << endl;
    os << "GlutenFree: " << birthdayCake.glutenFree << endl;
    os << "Description: " << birthdayCake.description << endl;

    return os;
}
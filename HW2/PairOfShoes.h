#pragma once
#include <iostream>
#include <string>
using namespace std;
class PairOfShoes
{
private:
	double price;
	char* name;
public:
	PairOfShoes(char* shoeName, double shoePrice);
	char* getName();
	double getPrice();
	void setPrice(double value);
};


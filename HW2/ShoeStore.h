#pragma once
#include "PairOfShoes.h"
#include "ShoeStorage.h"
class ShoeStore
{
private:
	ShoeStorage* shoeStorage;
	double discount;
public: 
	ShoeStore(double discount = 0);
	void setDiscountPrecent(double newDiscPrecent);
	double getDiscountPrecent();
	void addShoes(char* shoeName, double price, int pairs = 1);
	double avgShoesPrice();
	double getShoesPrice(char* ShoeName);
	void removeOnePair(char* shoeName);
};


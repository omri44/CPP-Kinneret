#pragma once
#include <iostream>
#include "PairOfShoes.h"	
class ShoeStorage
{
private:
	int capacity;
	int arrLength;
	PairOfShoes** arrShoes;
public:
	ShoeStorage(int size = 4);
	~ShoeStorage();
	ShoeStorage(ShoeStorage& storage);
	ShoeStorage& operator = (ShoeStorage& storage);
	void addPairOfShoes(PairOfShoes shoes);
	void removePairOfShoes(char* name);
	double getPrice(char* name);
	double averageShoesPrice();
};


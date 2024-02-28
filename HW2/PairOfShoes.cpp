#include "PairOfShoes.h"

PairOfShoes::PairOfShoes(char* shoeName, double shoePrice) {
	name = shoeName;
	price = shoePrice;
}

char* PairOfShoes::getName() {
	return name;
}
double PairOfShoes::getPrice() {
	return price;
}
void PairOfShoes::setPrice(double value) {
	price = value;
}

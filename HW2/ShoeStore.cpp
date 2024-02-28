#include "ShoeStore.h"
#include "PairOfShoes.h"
#include "ShoeStorage.h"


ShoeStore::ShoeStore(double disc) {
	discount = disc;
	shoeStorage = new ShoeStorage();
}

void ShoeStore::setDiscountPrecent(double newDiscPrecent) {
	discount = newDiscPrecent;
}

double ShoeStore::getDiscountPrecent() {
	return discount;
}

void ShoeStore::addShoes(char* shoeName, double price, int pairs) {
    PairOfShoes* newShoes= new PairOfShoes(shoeName, price);
	for (int i = 0;i < pairs;i++) 
		shoeStorage->addPairOfShoes(*newShoes);
}
double ShoeStore::avgShoesPrice() {
	return shoeStorage->averageShoesPrice() * discount;
}
double ShoeStore::getShoesPrice(char* shoeName) {
	return shoeStorage->getPrice(shoeName) * discount;
}
void ShoeStore::removeOnePair(char* shoeName) {
	shoeStorage->removePairOfShoes(shoeName);
}
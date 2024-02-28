#include "ShoeStorage.h"
#include "PairOfShoes.h"

//העתקת המערך הנוכחי אל מערך אחר הגדול פי 2 ממנו
ShoeStorage::ShoeStorage(int size) {
	arrLength = size;
	arrShoes = new PairOfShoes * [size];
	for (int i = 0; i < size;i++) {
		arrShoes[i] = nullptr;
	}
} 
ShoeStorage::~ShoeStorage() {
	for (int i = 0;i < this->arrLength;i++) {
		delete arrShoes[i];
	}
	delete[] arrShoes;
}
ShoeStorage::ShoeStorage(ShoeStorage& storage) {
	this->arrShoes = nullptr;
	*this = storage;
}
ShoeStorage& ShoeStorage:: operator=(ShoeStorage& storage) {
	if (this == &storage) {
		return *this;
	}
	for (int i = 0; i < arrLength;i++) 
		delete arrShoes[i];
	delete[] arrShoes;
	arrShoes = new PairOfShoes * [storage.capacity];
	arrLength = storage.arrLength;
	capacity = storage.capacity;
	for (int i = 0;i < arrLength;i++) {
		if (storage.arrShoes[i] != nullptr)
			arrShoes[i] = new PairOfShoes(*(storage.arrShoes[i]));
	}
	return *this;
}

//הוסף נעל אל מאגר הנעליים של החנות
void ShoeStorage::addPairOfShoes(PairOfShoes shoe) {
	PairOfShoes* insertNewShoe = new PairOfShoes(shoe.getName(), shoe.getPrice());
	for (int i = 0; i < arrLength;i++) {
		if (arrShoes[i] == nullptr) {
			arrShoes[i] = insertNewShoe;
			return;

		}
	}
}
void ShoeStorage::removePairOfShoes(char* name) {
	for (int i = 0;i < arrLength;i++) {
		if (strcmp(name, arrShoes[i]->getName()))
			arrShoes[i] = nullptr;
		return;
	}
}

double ShoeStorage::getPrice(char* name) {
	for (int i = 0;i < arrLength;i++) {
		if (arrShoes[i] != nullptr) {
		    if (strcmp(arrShoes[i]->getName(), name) == 0)
				return arrShoes[i]->getPrice();
		}
	}
	return 0;
}
double ShoeStorage::averageShoesPrice() {
	double price = 0.0;
	int amountOfShoes = 0;
	for (int i = 0;i < arrLength;i++) {
		if (arrShoes[i] != nullptr) {
			amountOfShoes++;
			price += arrShoes[i]->getPrice();
		}
	}
	return price > 0 ? price / amountOfShoes : 0.0;
}
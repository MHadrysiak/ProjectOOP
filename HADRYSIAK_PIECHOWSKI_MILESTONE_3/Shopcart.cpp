#include <iostream>
#include <fstream>

#include "Shopcart.h"

Shopcart::Shopcart(DB &db) : db(db) {
	size = 0;
	cart = new int[size];
}
Shopcart::~Shopcart() {
	delete[] cart;
}
int Shopcart::getSize()	const {
	return size;
}
int Shopcart::getElement(int i)	const {
	return cart[i];
}
void Shopcart::addToCart(int ID) {
	++size;
	int *temp = new int[size];
	for (int i = 0; i < size; ++i) {
		temp[i] = cart[i];
	}
	temp[size - 1] = ID-1;
	delete[] cart;
	cart = temp;
}
void Shopcart::saveShopcart(const std::string &fileName)
{
	float counter = 0;
	for (int i = 0; i < getSize(); ++i) {
		db.saveOne(fileName, getElement(i));
		counter += db[getElement(i)].getPrice();
	}
	std::ofstream sv(fileName, std::ios::app);
	if (sv) sv << "\nNumber of purchased products: " << getSize() << "\nTotal price: " << counter;
	else std::cout << "FILE ERROR";
	sv.close();
}
void Shopcart::showShopcart() const {
	db.displayHeader();
	for (int i = 0; i < getSize(); ++i)
		db.showOne(getElement(i));
}
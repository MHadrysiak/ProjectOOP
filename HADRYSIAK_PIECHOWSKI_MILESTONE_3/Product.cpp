#include <string>

#include "Product.h"

Product::Product() {
	name = "test";
	price = 00;
	if_premium = true;
	type = tools;
}
void Product::setID(int ID) {
	id = ID;
}
void Product::setName(std::string Name) {
	name = Name;
}
void Product::setPrice(float Price) {
	price = Price;
}
void Product::setPremium(bool Premium) {
	if_premium = Premium;
}
void Product::setType(int Type) {
	switch (Type) {
		case 0: type = tools; break;
		case 1: type = plants; break;
	}
}
int Product::getID() const {
	return id;
}
std::string Product::getName() const {
	return name;
}
float Product::getPrice() const {
	return price;
}
bool Product::getPremium() const {
	return if_premium;
}
int Product::getType() const {
	if (type == tools) return 0;
	else return 1;
}
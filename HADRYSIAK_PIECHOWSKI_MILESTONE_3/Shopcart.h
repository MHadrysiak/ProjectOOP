#ifndef SHOPCART_H_
#define SHOPCART_H_

#include <string>

#include "Product.h"
#include "Database.h"

class Shopcart
{
	int size;
	int *cart;
	DB &db;
public:
	Shopcart(DB &db);
	~Shopcart();
	int getSize() const;
	int getElement(int i) const;
	void addToCart(int ID);
	void saveShopcart(const std::string &fileName);
	void showShopcart() const;
};
#endif
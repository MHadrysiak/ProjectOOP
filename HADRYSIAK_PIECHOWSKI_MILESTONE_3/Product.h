#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <string>

class Product {
	enum Types {tools, plants};
	int id = 0;
	std::string name;
	float price;
	bool if_premium;
	Types type;
public:
	Product();
	void setID(int ID);
	void setName(std::string Name);
	void setPrice(float Price);
	void setPremium(bool Premium);
	void setType(int Type);
	int getID()	const;
	std::string getName() const;
	float getPrice() const;
	bool getPremium() const;
	int getType() const;
};
#endif
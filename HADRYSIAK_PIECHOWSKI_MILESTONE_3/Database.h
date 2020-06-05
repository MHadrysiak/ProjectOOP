#ifndef DATABASE_H_
#define DATABASE_H_

#include <vector>

#include "Product.h"

class DB: public Product {
	std::vector<Product> db;
	char s = ';';
public:
	Product& operator[] (int index) {return this->db[index];}
	const Product& operator[] (int index) const {return this->db[index];}
	void addProduct(std::string Name, float Price, bool Premium, int Type);
	void showOne(int N)	const;
	int checkSize() const;
	void displayHeader() const;
	int getSize() const;
	void deleteProduct(int N);
	void saveOne(const std::string &fileName, int N) const;
	void saveAll(const std::string &fileName);
	void Upload(const std::string &fileName);
	int getTheLongest() const;
	std::string endeCode(std::string Data, bool way);
};
#endif
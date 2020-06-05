#include <iostream>
#include <string>
#include <iomanip>

#include "Menu.h"

void Standard_Menu::PrintMenu()	{
	std::cout << "Menu:" << "\n";
	std::cout << "	1.Show Products" << "\n";
	std::cout << "	2.Add to Shopcart" << "\n";
	std::cout << "	3.Show Shopcart" << "\n";
	std::cout << "	4.Save Shopcart" << "\n";
	std::cout << "	5.Log Out From the Program" << "\n";
	std::cout << "Your Choice: ";
}
void Premium_Menu::PrintMenu() {
	std::cout << "Menu:" << "\n";
	std::cout << "	1.Show Products" << "\n";
	std::cout << "	2.Add to Shopcart" << "\n";
	std::cout << "	3.Show Shopcart" << "\n";
	std::cout << "	4.Save Shopcart" << "\n";
	std::cout << "	5.Log Out From the Program" << "\n";
	std::cout << "Your Choice: ";
}
void Admin_Menu::PrintMenu() {
	std::cout << "Menu:" << "\n";
	std::cout << "	1.Show Products" << "\n";
	std::cout << "	2.Add Product to Database" << "\n";
	std::cout << "	3.Delete Product from Database" << "\n";
	std::cout << "	4.Upload Products from File" << "\n";
	std::cout << "	5.Save Database to File" << "\n";
	std::cout << "	6.Log Out From the Program" << "\n";
	std::cout << "Your Choice: ";
}
void Standard_Menu::showProduct(DB &db, int t) {
	int size = db.getSize();
	db.displayHeader();
	for (int i = 0; i < size; ++i) {
		if (t == 2 and db[i].getPremium() == false) db.showOne(i);
		else {
			if (db[i].getPremium() == false and db[i].getType() == t) db.showOne(i);
		}
	}
}
void Premium_Menu::showProduct(DB &db, int t) {
	int size = db.getSize();
	db.displayHeader();
	for (int i = 0; i < size; ++i) {
		if (t == 2 and db[i].getPremium() == true) db.showOne(i);
		else {
			if (db[i].getPremium() == true and db[i].getType() == t) db.showOne(i);
		}
	}
}
void Admin_Menu::showProduct(DB &db, int t) {
	int size = db.getSize();
	db.displayHeader();
	for (int i = 0; i < size; ++i) {
		if (t == 2) db.showOne(i);
		else {
			if (db[i].getType() == t) db.showOne(i);
		}
	}
}
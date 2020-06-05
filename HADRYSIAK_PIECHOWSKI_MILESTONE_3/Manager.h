#ifndef MANAGER_H
#define MANAGER_H

#include "Menu.h"
#include "Database.h"
#include "Shopcart.h"

class Manager{
	DB &db1;
	Menu *pointer;
	Standard_Menu &s_menu;
	Premium_Menu &p_menu;
	Admin_Menu &a_menu;
	Shopcart &shopcart;
	int exit = 0;
	bool first = true;
	int id = -1;
	std::string password = "";
	std::string fileName = "";
	int choice = -1;
	std::string name = "";
	float price = -1;
	int premium_int = -1;
	bool premium_bool = false;
	int type = -1;
public:
	Manager(DB &db, Menu *p, Standard_Menu &s_m, Premium_Menu &p_m, Admin_Menu &a_m, Shopcart &sh);
	void Printing();
	void ATC(); //Add to Cart
	void SaSh(); //Save Shopcart
	void APTD(); //Add Product to Database
	void DPFD(); //Delete Product from Database
	void Upload();
	void SDTF(); //Save Database to File
	void Workplace();
	void AdminWorkplace();
	void ALogin();
	void LoginPanel();
};
#endif
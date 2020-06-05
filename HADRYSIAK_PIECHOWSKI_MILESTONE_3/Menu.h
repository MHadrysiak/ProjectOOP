#ifndef MENU_H_
#define MENU_H_

#include "Database.h"

class Menu {

public:
	virtual void PrintMenu() = 0;
	virtual void showProduct(DB &db, int t) = 0;
};

class Standard_Menu: public Menu {

public:
	void PrintMenu() override;
	void showProduct(DB &db, int t)	override;
};

class Premium_Menu: public Menu {

public:
	void PrintMenu() override;
	void showProduct(DB &db, int t)	override;
};

class Admin_Menu: public Menu {

public:
	void PrintMenu() override;
	void showProduct(DB &db, int t)	override;
};
#endif
#include <string>
#include <iostream>

#include "Manager.h"

Manager::Manager(DB &db, Menu *p, Standard_Menu &s_m, Premium_Menu &p_m, Admin_Menu &a_m, Shopcart &sh)
	: db1(db), pointer(p), s_menu(s_m), p_menu(p_m), a_menu(a_m), shopcart(sh) {}

void Manager::Printing() {
	std::cout << "Which Types of Products Do You Want to Print?\n";
	std::cout << "0.	Tools\n";
	std::cout << "1.	Plants\n";
	std::cout << "2.	Both\n";
	std::cout << "Your Choice: ";
	std::cin >> choice;
	pointer->showProduct(db1, choice);
}
void Manager::ATC() {
	std::cout << "Enter the ID of the Product You Want to Add: ";
	std::cin >> id;
	shopcart.addToCart(id);
}
void Manager::SaSh() {
	std::string fileName;
	std::cout << "Enter File Name (With Extension): ";
	std::cin>>fileName;
	shopcart.saveShopcart(fileName);
}
void Manager::APTD() {
	std::cout << "Product\n";
	std::cout << "Name: ";
	std::cin >> name;
	std::cout << "Price: ";
	std::cin >> price;
	std::cout << "Premium(1.true/0.false): ";
	std::cin >> premium_int;
	std::cout << "Type(0.Tools/1.Plants): ";
	std::cin >> type;
	if(premium_int == 1) premium_bool = true;
	if(premium_int == 0) premium_bool = false;
	db1.addProduct(name, price, premium_bool, type);
}
void Manager::DPFD() {
	std::cout << "Enter the Product ID to Delete: ";
	std::cin >> id;
	db1.deleteProduct(id);
}
void Manager::Upload() {
	std::cout << "Enter File Name (With Extension): ";
	std::cin>>fileName;
	db1.Upload(fileName);
}
void Manager::SDTF() {
	std::cout << "Enter File Name (With Extension): ";
	std::cin>>fileName;
	db1.saveAll(fileName);
}
void Manager::Workplace() {
	do {
		pointer->PrintMenu();
		std::cin>>choice;
		switch (choice) {
			case 1: Printing(); break;
			case 2: ATC(); break;
			case 3: shopcart.showShopcart(); break;
			case 4: SaSh(); break;
			default: {if (choice != 5) std::cout<<"Please, Enter Valid Number\n";} break;
		}
	} while (choice != 5);
}
void Manager::AdminWorkplace() {
	do {
		pointer->PrintMenu();
		std::cin>>choice;
		switch (choice) {
			case 1: Printing(); break;
			case 2: APTD(); break;
			case 3: DPFD(); break;
			case 4: Upload(); break;
			case 5: SDTF(); break;
			default: {if (choice != 6) std::cout<<"Please, Enter Valid Number\n";} break;
		}
	} while(choice != 6);
}
void Manager::ALogin() {
	std::cout <<"		LOG IN\n";
	std::cout <<"	Login: 	Admin\n";
	std::cout <<"	Password: ";
	std::cin >> password;
	if (password == "adminadmin") AdminWorkplace();
	else std::cout << "WRONG PASSWORD\n";
}
void Manager::LoginPanel() {
	do {
		if (first) {
			std::cout << "Welcome in the M&M's Shop!\n";
			db1.Upload("initial_stock.csv");
			first = false;
		}
		std::cout << "\nLOG IN:\n";
		std::cout << "1.	Standard\n";
		std::cout << "2.	Premium\n";
		std::cout << "3.	Close\n";
		std::cout << "Your Choice: ";
		std::cin >> choice;
		switch (choice) {
			case 1: {pointer = &s_menu; Workplace();} break;
			case 2: {pointer = &p_menu; Workplace();} break;
			case 3: {std::cout << "\nThank You For Shopping!\n"; exit = 1;} break;
			case 23: {pointer = &a_menu; ALogin();} break;
			default: {std::cout<<"Please, Enter Valid Number\n"; break;} break;
		}
	} while (exit != 1);
}
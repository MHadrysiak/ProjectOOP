#include "Product.h"
#include "Database.h"
#include "Shopcart.h"
#include "Menu.h"
#include "Manager.h"

int main() {

DB db1;
Menu *pointer = nullptr;
Standard_Menu s_menu;
Premium_Menu p_menu;
Admin_Menu a_menu;
Shopcart shopcart(db1);
Manager menago(db1, pointer, s_menu, p_menu, a_menu, shopcart);

menago.LoginPanel();

return 0;	
}
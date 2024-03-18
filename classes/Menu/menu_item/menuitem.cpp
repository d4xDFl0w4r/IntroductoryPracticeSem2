#include "menuitem.h"

MenuItem::MenuItem(std::string name, Function func) : item_name(name), func(func) {}

string MenuItem::getName() {
    return item_name;
}

void MenuItem::printItemName() {
    std::cout << item_name;
}

int MenuItem::run() {
    return func();
}
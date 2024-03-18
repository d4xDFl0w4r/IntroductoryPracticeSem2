#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string>

using namespace std;

class MenuItem {
public:
    typedef int(*Function)();
    MenuItem(string, Function);
    string getName();
    void printItemName();
    int run();

private:
    Function func{};
    string item_name{};
};
#endif //MENUITEM_H
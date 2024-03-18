#ifndef MENU_H
#define MENU_H

#include <cstddef>
#include <string>

#include "../menu_item/menuitem.h"

using namespace std;


class Menu {
    public:
        Menu(MenuItem *, size_t);
        int getSelect() const;
        bool isRun() const;
        string getTitle();
        size_t getCount() const;
        MenuItem *getItems();
        void print();
        int runCommand();

    private:
        int select{-1};
        size_t numberOfFunctions{};
        bool running{};
        MenuItem *items{};
};
#endif //MENU_H
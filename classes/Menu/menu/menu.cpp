#include "menu.h"

Menu::Menu(MenuItem *items, size_t numberOfFunctions) : items(items), numberOfFunctions(numberOfFunctions) {}

int Menu::getSelect() const {
    return select;
}

bool Menu::isRun() const {
    return running;
}

size_t Menu::getCount() const {
    return numberOfFunctions;
}

MenuItem *Menu::getItems() {
    return items;
}

void Menu::print() {
    std::cout << std::endl;
    for (size_t i = 0; i < numberOfFunctions; ++i) {
        std::cout << i + 1 << ". ";
        items[i].printItemName();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int Menu::runCommand() {
    print();
    for (;;) {
        select = getInt(getString("\tSelect"));
        std::cout << std::endl;
        if (select == -1) {
            //pass
        } else if (select < 1 || select > numberOfFunctions) {
            throwRangeException("Select", 1, numberOfFunctions);
        } else {
            return items[select - 1].run();
        }
    }
}
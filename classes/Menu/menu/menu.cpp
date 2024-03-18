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
    std::cout << "\tSelect >> ";
    for (;;) {
        std::cin >> select;
        std::cout << std::endl;
        if (select < 1 || select > numberOfFunctions) {
            cout << "Number must be in range [1;" << numberOfFunctions <<"]" << endl;
        } else {
            return items[select - 1].run();
        }
    }
}
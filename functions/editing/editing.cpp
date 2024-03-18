#include "editing.h"

std::string getString(std::string coutText) {
    std::cout << coutText << ": ";
    std::string userText;
    getline(std::cin, userText);
    return userText;
}

void addRecord(std::vector<TableRow>& table) {
    table.push_back(TableRow());
}

void editRecord(std::vector<TableRow>& table) {
    if (!table.size()) {
        std::cout << "There is nothing to edit" << std::endl;
        return;
    }

    std::cout << "id of record to edit: ";
    int index;
    std::cin >> index;

    if (index-- > table.size()) {
        std::cout << "Index must be in range [1;" << table.size() <<"]" << std::endl;
        return;
    }

    std::cin.clear();
    std::cin.ignore(100, '\n');

    int choice;
    std::cout << "1. Commentary" << std::endl;
    std::cout << "2. Date" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    if (2 < choice || choice < 1) {
        std::cout << "Index must be in range [1;" << table.size() <<"]" << std::endl;
        return;
    }

    std::cin.clear();
    std::cin.ignore(100, '\n');

    if (choice == 1) {
        table[index].setComment(getString("Commentary"));
    } else {
        std::string date = getString("Date (dd.mm.yyyy)");
        int day = -1;
        int month = -1;
        int year = -1;
        if (date.length() == 10 && date[2] == '.' && date[5] == '.') {
            day = std::stoi(date.substr(0, 2));
            month = std::stoi(date.substr(3, 2));
            year = std::stoi(date.substr(6, 4));
        }
        table[index].setDateOfReceipt(day, month, year);
    }
}

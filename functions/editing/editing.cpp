#include "editing.h"

std::string getString(std::string coutText) {
    std::cout << coutText << ": ";
    std::string userText;
    getline(std::cin, userText);
    return userText;
}

Date getDate(std::string coutText) {
    std::string strDate = getString("Date of " + coutText + " (dd.mm.yyyy)");
    int day = -1;
    int month = -1;
    int year = -1;
    if (strDate.length() == 10 && strDate[2] == '.' && strDate[5] == '.') {
        day = std::stoi(strDate.substr(0, 2));
        month = std::stoi(strDate.substr(3, 2));
        year = std::stoi(strDate.substr(6, 4));
    }
    Date date;
    date.setDay(day);
    date.setMonth(month);
    date.setYear(year);
    return date;
}

void addRecord(std::vector<TableRow>& table) {
    TableRow tableRow;
    tableRow.setAnimalType(getString("Animal type"));
    tableRow.setAnimalBreed(getString("Animal breed"));
    tableRow.setAnimalSex(getString("Animal sex"));
    tableRow.setAnimalName(getString("Animal name"));
    tableRow.setComment(getString("Comment"));
    tableRow.setOwner(getString(""));
    tableRow.setDepartment(getString(""));
    tableRow.setServiceType(getString(""));
    tableRow.setServicePrice(getString(""));

    Date date = getDate("receipt");
    tableRow.setDateOfReceipt(date.getDay(), date.getMonth(), date.getYear());
    Date date = getDate("discharge");
    tableRow.setDateOfDischarge(date.getDay(), date.getMonth(), date.getYear());
    
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
        throwRangeException("Index", 1, table.size());
        return;
    }

    std::cin.clear();
    std::cin.ignore(100, '\n');

    int choice;
    std::cout << "1. Commentary" << std::endl;
    std::cout << "2. Date of discharge" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    if (2 < choice || choice < 1) {
        throwRangeException("Choice", 1, 2);
        return;
    }

    std::cin.clear();
    std::cin.ignore(100, '\n');

    if (choice == 1) {
        table[index].setComment(getString("Commentary"));
    } else {
        Date date = getDate("discharge");
        table[index].setDateOfDischarge(date.getDay(), date.getMonth(), date.getYear());
    }
}

#include "editing.h"

std::string getString(std::string coutText) {
    std::cout << coutText << ": ";
    std::string userText;
    getline(std::cin, userText);
    if (!userText.length()) {
        throwEmptyStringException();
        return "";
    }
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

int getInt(std::string strNum) {
    if (isCorrectNumber(strNum) && strNum.length()) {
        return std::stoi(strNum);
    }
    else {
        return -1;
    }
}

void addRecord(std::vector<TableRow>& table) {
    TableRow tableRow;
    tableRow.setAnimalType(getString("Animal type"));
    tableRow.setAnimalBreed(getString("Animal breed"));
    tableRow.setAnimalSex(getString("Animal sex"));
    tableRow.setAnimalName(getString("Animal name"));
    tableRow.setComment(getString("Comment"));
    tableRow.setOwner(getString("Owner"));
    tableRow.setDepartment(getString("Department"));
    tableRow.setServiceType(getString("Serivce type"));
    tableRow.setServicePrice(getString("Service price"));

    Date date = getDate("receipt");
    tableRow.setDateOfReceipt(date.getDay(), date.getMonth(), date.getYear());
    date = getDate("discharge");
    tableRow.setDateOfDischarge(date.getDay(), date.getMonth(), date.getYear());
    
    table.push_back(tableRow);
}

void editRecord(std::vector<TableRow>& table) {
    if (!table.size()) {
        std::cout << "There is nothing to edit" << std::endl;
        return;
    }

    int index = getInt(getString("id of record to edit"));

    if (index-- > table.size()) {
        throwRangeException("Index", 1, table.size());
        return;
    }

    
    std::cout << "1. Commentary" << std::endl;
    std::cout << "2. Date of discharge" << std::endl;
    int choice = getInt(getString("Choice"));

    if (2 < choice || choice < 1) {
        throwRangeException("Choice", 1, 2);
        return;
    }

    if (choice == 1) {
        table[index].setComment(getString("Commentary"));
    } else {
        Date date = getDate("discharge");
        table[index].setDateOfDischarge(date.getDay(), date.getMonth(), date.getYear());
    }
}

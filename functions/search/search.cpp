#include "search.h"
 
void searchRecord(std::vector<TableRow>& table, size_t maxWitdth) { 
    if (!table.size()) { 
        std::cout << "There is nothing to search" << std::endl; 
        return; 
    } 
 
    std::cout << "Search by fields"; 
 
    int choice;
    std::cout << "1. Animal type" << std::endl;
    std::cout << "2. Owner" << std::endl;
    std::cout << "3. Service type" << std::endl;
    std::cout << "4. Date of receipt" << std::endl;
    std::cout << "Choice: " << std::endl;
    std::cin >> choice;
 
    if (4 < choice || choice < 1) { 
        throwRangeException("Choice", 1, 4);
        return; 
    } 
 
    std::string tempString{}; 
    unsigned int tempInt{}; 
    Date* dateOfReceipt{};
    std::vector<TableRow> buffTable;
 
    switch (choice) { 
    case 1: 
        std::cout << "Input animal type: "; 
        std::cin >> tempString; 
 
        for (int i = 0; i < table.size(); i++) { 
            if (table[i].getAnimalType() == tempString) { 
                buffTable.push_back(table[i]);
            } 
        } 
        break; 
    case 2: 
        std::cout << "Input owner: "; 
        std::cin >> tempString; 
 
        for (int i = 0; i < table.size(); i++) { 
            if (table[i].getOwner() == tempString) { 
                buffTable.push_back(table[i]);
            } 
        } 
        break; 
    case 3: 
        std::cout << "Input service type: "; 
        std::cin >> tempString; 
 
        for (int i = 0; i < table.size(); i++) { 
            if (table[i].getServiceType() == tempString) { 
                buffTable.push_back(table[i]);
            } 
        } 
        break; 
    case 4: 
        std::cout << "Input date of receipt\n"; 
        std::cout << "Year: "; 
        std::cin >> tempInt; 
        dateOfReceipt->setYear(tempInt); 
        std::cout << "Month: "; 
        std::cin >> tempInt; 
        dateOfReceipt->setMonth(tempInt); 
        std::cout << "Day: "; 
        std::cin >> tempInt; 
        dateOfReceipt->setDay(tempInt);
 
        for (int i = 0; i < table.size(); i++) { 
            Date* ptrDate = new Date();
            *ptrDate = table[i].getDateOfReceipt();
            if (Date::CompareDates(dateOfReceipt, ptrDate) == 0) { 
                buffTable.push_back(table[i]);
            } 
        } 
        break;
    default:
        break; 
    }
    printTable(buffTable, maxWitdth);
}
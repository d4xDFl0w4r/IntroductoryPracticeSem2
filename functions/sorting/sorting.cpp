#include "sorting.h" 
 
bool firstEarlySecond(std::string first, std::string second) { 
    for (int i = 0; i < second.size(); i++) { 
        if (first[i] > second[i]) { 
            return false; 
        } 
        else if (first[i] < second[i]) { 
            return true; 
        } 
    }
    return true; 
} 
 
void sortTable(std::vector<TableRow>& table) { 
    if (!table.size() || table.size() == 1) { 
        std::cout << "There is nothing to sort" << std::endl; 
        return; 
    } 
 
    std::cout << "Sorting by animalType field" << std::endl; 
 
    int choice; 
    std::cout << "1. From A to Z" << std::endl; 
    std::cout << "2. From Z to A" << std::endl; 
    std::cout << "Choice: "; 
    std::cin >> choice; 
 
    if (2 < choice || choice < 1) { 
        throwRangeException("Choice", 1, 2);
        return; 
    } 
 
    for (int i = 0; i < table.size() - 1; i++) { 
        for (int j = i + 1; j < table.size(); j++) { 
            if (--choice * !firstEarlySecond(table[i].getAnimalType(), table[j].getAnimalType())) { 
                TableRow temp = table[i]; 
                table[i] = table[j]; 
                table[j] = temp;
            } 
        } 
    } 
}
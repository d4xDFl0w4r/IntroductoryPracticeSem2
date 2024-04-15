#include "others.h"

void printTable(std::vector<TableRow> table, size_t maxWidth) {
    size_t size = table.size();
    if (size > 0)
    {
        std::string id = "id";
        std::string animalType = "Vid zhivotnogo";
        std::string animalBreed = "Poroda";
        std::string animalSex = "Pol";
        std::string animalName = "Klichka";
        std::string comment = "commentari";
        std::string owner = "Vladeletz";
        std::string department = "Otdelenie";
        std::string serviceType = "Okazyvaemaya usluga";
        std::string servicePrice = "Stoimost uslugi";
        std::string dateOfReceipt = "Data postupleniya";
        std::string dateOfDischarge = "Data vypiski";

        std::vector<size_t> maxLinesCount(size, 1);

        size_t maxLinesCountTop = 1;

        size_t lenID = id.length();
        size_t lenAnimalType = animalType.length();
        size_t lenAnimalBreed = animalBreed.length();
        size_t lenAnimalSex = animalSex.length();
        size_t lenAnimalName = animalName.length();
        size_t lenComment = comment.length();
        size_t lenOwner = owner.length();
        size_t lenDepartment = department.length();
        size_t lenServiceType = serviceType.length();
        size_t lenServicePrice = servicePrice.length();
        size_t lenDateOfReceipt = dateOfReceipt.length();
        size_t lenDateOfDischarge = dateOfDischarge.length();

        maxLinesCountTop = std::max(maxLinesCountTop, linesCount(lenID, maxWidth));
        maxLinesCountTop = std::max(maxLinesCountTop, linesCount(lenAnimalType, maxWidth));
        maxLinesCountTop = std::max(maxLinesCountTop, linesCount(lenAnimalBreed, maxWidth));
        maxLinesCountTop = std::max(maxLinesCountTop, linesCount(lenAnimalSex, maxWidth));
        maxLinesCountTop = std::max(maxLinesCountTop, linesCount(lenAnimalName, maxWidth));
        maxLinesCountTop = std::max(maxLinesCountTop, linesCount(lenComment, maxWidth));
        maxLinesCountTop = std::max(maxLinesCountTop, linesCount(lenOwner, maxWidth));
        maxLinesCountTop = std::max(maxLinesCountTop, linesCount(lenDepartment, maxWidth));
        maxLinesCountTop = std::max(maxLinesCountTop, linesCount(lenServiceType, maxWidth));
        maxLinesCountTop = std::max(maxLinesCountTop, linesCount(lenServicePrice, maxWidth));
        maxLinesCountTop = std::max(maxLinesCountTop, linesCount(lenDateOfReceipt, maxWidth));
        maxLinesCountTop = std::max(maxLinesCountTop, linesCount(lenDateOfDischarge, maxWidth));
        for (int i = 0; i < size; i++)
        {
            lenID = maxLength(lenID, intlen(i), maxWidth);
            lenAnimalType = maxLength(lenAnimalType, table[i].getAnimalType().length(), maxWidth);
            lenAnimalBreed = maxLength(lenAnimalBreed, table[i].getAnimalBreed().length(), maxWidth);
            lenAnimalSex = maxLength(lenAnimalSex, table[i].getAnimalSex().length(), maxWidth);
            lenAnimalName = maxLength(lenAnimalName, table[i].getAnimalName().length(), maxWidth);
            lenComment = maxLength(lenComment, table[i].getComment().length(), maxWidth);
            lenOwner = maxLength(lenOwner, table[i].getOwner().length(), maxWidth);
            lenDepartment = maxLength(lenDepartment, table[i].getDepartment().length(), maxWidth);
            lenServiceType = maxLength(lenServiceType, table[i].getServiceType().length(), maxWidth);
            lenServicePrice = maxLength(lenServicePrice, table[i].getServicePrice().length(), maxWidth);
            lenDateOfReceipt = maxLength(lenDateOfReceipt, table[i].getDateOfReceipt().GetDateAsString().length(), maxWidth);
            lenDateOfDischarge = maxLength(lenDateOfDischarge, table[i].getDateOfDischarge().GetDateAsString().length(), maxWidth);
            
            maxLinesCount[i] = std::max(maxLinesCount[i], linesCount(lenID, maxWidth));
            maxLinesCount[i] = std::max(maxLinesCount[i], linesCount(lenAnimalType, maxWidth));
            maxLinesCount[i] = std::max(maxLinesCount[i], linesCount(lenAnimalBreed, maxWidth));
            maxLinesCount[i] = std::max(maxLinesCount[i], linesCount(lenAnimalSex, maxWidth));
            maxLinesCount[i] = std::max(maxLinesCount[i], linesCount(lenAnimalName, maxWidth));
            maxLinesCount[i] = std::max(maxLinesCount[i], linesCount(lenComment, maxWidth));
            maxLinesCount[i] = std::max(maxLinesCount[i], linesCount(lenOwner, maxWidth));
            maxLinesCount[i] = std::max(maxLinesCount[i], linesCount(lenDepartment, maxWidth));
            maxLinesCount[i] = std::max(maxLinesCount[i], linesCount(lenServiceType, maxWidth));
            maxLinesCount[i] = std::max(maxLinesCount[i], linesCount(lenServicePrice, maxWidth));
            maxLinesCount[i] = std::max(maxLinesCount[i], linesCount(lenDateOfReceipt, maxWidth));
            maxLinesCount[i] = std::max(maxLinesCount[i], linesCount(lenDateOfDischarge, maxWidth));
        }
        size_t length = 43 + lenID + lenAnimalType + lenAnimalBreed + lenAnimalSex + lenAnimalName + lenAnimalName + lenComment + lenOwner + lenDepartment + lenServiceType + lenServicePrice + lenDateOfReceipt + lenDateOfDischarge;
        for (int i = 0; i < length; i++)
        {
            std::cout << "=";
        }
        std::cout << std::endl;
        for (int i = 0; i < maxLinesCountTop; i++)
        {
            std::cout << "|| " << printw(id, lenID * maxLinesCountTop).substr(i * lenID, lenID);
            std::cout << " || " << printw(animalType, lenAnimalType * maxLinesCountTop).substr(i * lenAnimalType, lenAnimalType);
            std::cout << " || " << printw(animalBreed, lenAnimalBreed * maxLinesCountTop).substr(i * lenAnimalBreed, lenAnimalBreed);
            std::cout << " || " << printw(animalSex, lenAnimalSex * maxLinesCountTop).substr(i * lenAnimalSex, lenAnimalSex);
            std::cout << " || " << printw(animalName, lenAnimalName * maxLinesCountTop).substr(i * lenAnimalName, lenAnimalName);
            std::cout << " || " << printw(comment, lenComment * maxLinesCountTop).substr(i * lenComment, lenComment);
            std::cout << " || " << printw(owner, lenOwner * maxLinesCountTop).substr(i * lenOwner, lenOwner);
            std::cout << " || " << printw(department, lenDepartment * maxLinesCountTop).substr(i * lenDepartment, lenDepartment);
            std::cout << " || " << printw(serviceType, lenServiceType * maxLinesCountTop).substr(i * lenServiceType, lenServiceType);
            std::cout << " || " << printw(servicePrice, lenServicePrice * maxLinesCountTop).substr(i * lenServicePrice, lenServicePrice);
            std::cout << " || " << printw(dateOfReceipt, lenDateOfReceipt * maxLinesCountTop).substr(i * lenDateOfReceipt, lenDateOfReceipt);
            std::cout << " || " << printw(dateOfDischarge, lenDateOfDischarge * maxLinesCountTop).substr(i * lenDateOfDischarge, lenDateOfDischarge) << " ||";
            std::cout << std::endl;
        }
        for (int i = 0; i < size; i++)
        {
            for (int k = 0; k < length; k++)
            {
                std::cout << "=";
            }
            for (int j = 0; j < maxLinesCount[i]; j++)
            {
                std::cout << std::endl;
                std::cout << "|| " << printwInt(i + 1, lenID * maxLinesCount[i]).substr(j * lenID, lenID);
                std::cout << " || " << printw(table[i].getAnimalType(), lenAnimalType * maxLinesCount[i]).substr(j * lenAnimalType, lenAnimalType);
                std::cout << " || " << printw(table[i].getAnimalBreed(), lenAnimalBreed * maxLinesCount[i]).substr(j * lenAnimalBreed, lenAnimalBreed);
                std::cout << " || " << printw(table[i].getAnimalSex(), lenAnimalSex * maxLinesCount[i]).substr(j * lenAnimalSex, lenAnimalSex);
                std::cout << " || " << printw(table[i].getAnimalName(), lenAnimalName * maxLinesCount[i]).substr(j * lenAnimalName, lenAnimalName);
                std::cout << " || " << printw(table[i].getComment(), lenComment * maxLinesCount[i]).substr(j * lenComment, lenComment);
                std::cout << " || " << printw(table[i].getOwner(), lenOwner * maxLinesCount[i]).substr(j * lenOwner, lenOwner);
                std::cout << " || " << printw(table[i].getDepartment(), lenDepartment * maxLinesCount[i]).substr(j * lenDepartment, lenDepartment);
                std::cout << " || " << printw(table[i].getServiceType(), lenServiceType * maxLinesCount[i]).substr(j * lenServiceType, lenServiceType);
                std::cout << " || " << printw(table[i].getServicePrice(), lenServicePrice * maxLinesCount[i]).substr(j * lenServicePrice, lenServicePrice);
                std::cout << " || " << printw(table[i].getDateOfReceipt().GetDateAsString(), lenDateOfReceipt * maxLinesCount[i]).substr(j * lenDateOfReceipt, lenDateOfReceipt);
                std::cout << " || " << printw(table[i].getDateOfDischarge().GetDateAsString(), lenDateOfDischarge * maxLinesCount[i]).substr(j * lenDateOfDischarge, lenDateOfDischarge);
                std::cout << " ||";
            }
            std::cout << std::endl;
        }
        for (int i = 0; i < length; i++)
        {
            std::cout << "=";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Пустая таблица" << std::endl << std::endl;
    }
    std::cout << std::endl;
}

size_t maxLength(size_t num1, size_t num2, size_t maxLength) {
    size_t max = std::max(num1, num2);
    if (max > maxLength) {
        return maxLength;
    } else {
        return max;
    }
}

size_t linesCount(size_t len, size_t &maxWidth) {
    int linesCount = 1;
    if (len > maxWidth) {
        linesCount = std::ceil((double)len / maxWidth);
        len = maxWidth;
    }
    return linesCount;
}

int intlen(int num) {
    return std::to_string(num).length();
}

std::string printw(std::string str, int width) {
    size_t size = str.length();
    for (int i = 0; i < width - size; i++) {
        str += " ";
    }
    return str;
}

std::string printwInt(int num, int width) {
    return printw(std::to_string(num), width);
}

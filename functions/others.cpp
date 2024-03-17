#include "others.h"

void outputData(std::vector<TableRow> table) {
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
        
        std::vector<int> maxLinesCount(size, 1);

        size_t maxLinesCountTop = 1;
        size_t maxWidth = 14;

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

        maxLinesCountTop = maxNum(maxLinesCountTop, linesCount(lenID, maxWidth));
        maxLinesCountTop = maxNum(maxLinesCountTop, linesCount(lenAnimalType, maxWidth));
        maxLinesCountTop = maxNum(maxLinesCountTop, linesCount(lenAnimalBreed, maxWidth));
        maxLinesCountTop = maxNum(maxLinesCountTop, linesCount(lenAnimalSex, maxWidth));
        maxLinesCountTop = maxNum(maxLinesCountTop, linesCount(lenAnimalName, maxWidth));
        maxLinesCountTop = maxNum(maxLinesCountTop, linesCount(lenComment, maxWidth));
        maxLinesCountTop = maxNum(maxLinesCountTop, linesCount(lenOwner, maxWidth));
        maxLinesCountTop = maxNum(maxLinesCountTop, linesCount(lenDepartment, maxWidth));
        maxLinesCountTop = maxNum(maxLinesCountTop, linesCount(lenServiceType, maxWidth));
        maxLinesCountTop = maxNum(maxLinesCountTop, linesCount(lenServicePrice, maxWidth));
        maxLinesCountTop = maxNum(maxLinesCountTop, linesCount(lenDateOfReceipt, maxWidth));
        maxLinesCountTop = maxNum(maxLinesCountTop, linesCount(lenDateOfDischarge, maxWidth));
        for (int i = 0; i < size; i++)
        {
            lenID = maxNum(lenID, i);
            lenAnimalType = maxNum(lenAnimalType, table[i].getAnimalType().length());
            lenAnimalBreed = maxNum(lenAnimalBreed, table[i].getAnimalBreed().length());
            lenAnimalSex = maxNum(lenAnimalSex, table[i].getAnimalSex().length());
            lenAnimalName = maxNum(lenAnimalName, table[i].getAnimalName().length());
            lenComment = maxNum(lenComment, table[i].getComment().length());
            lenOwner = maxNum(lenOwner, table[i].getOwner().length());
            lenDepartment = maxNum(lenDepartment, table[i].getDepartment().length());
            lenServiceType = maxNum(lenServiceType, table[i].getServiceType().length());
            lenServicePrice = maxNum(lenServicePrice, table[i].getServicePrice().length());
            lenDateOfReceipt = maxNum(lenDateOfReceipt, table[i].getDateOfReceipt().GetDateAsString().length());
            lenDateOfDischarge = maxNum(lenDateOfDischarge, table[i].getDateOfDischarge().GetDateAsString().length());
            
            maxLinesCount[i] = maxNum(maxLinesCount[i], linesCount(lenID, maxWidth));
            maxLinesCount[i] = maxNum(maxLinesCount[i], linesCount(lenAnimalType, maxWidth));
            maxLinesCount[i] = maxNum(maxLinesCount[i], linesCount(lenAnimalBreed, maxWidth));
            maxLinesCount[i] = maxNum(maxLinesCount[i], linesCount(lenAnimalSex, maxWidth));
            maxLinesCount[i] = maxNum(maxLinesCount[i], linesCount(lenAnimalName, maxWidth));
            maxLinesCount[i] = maxNum(maxLinesCount[i], linesCount(lenComment, maxWidth));
            maxLinesCount[i] = maxNum(maxLinesCount[i], linesCount(lenOwner, maxWidth));
            maxLinesCount[i] = maxNum(maxLinesCount[i], linesCount(lenDepartment, maxWidth));
            maxLinesCount[i] = maxNum(maxLinesCount[i], linesCount(lenServiceType, maxWidth));
            maxLinesCount[i] = maxNum(maxLinesCount[i], linesCount(lenServicePrice, maxWidth));
            maxLinesCount[i] = maxNum(maxLinesCount[i], linesCount(lenDateOfReceipt, maxWidth));
            maxLinesCount[i] = maxNum(maxLinesCount[i], linesCount(lenDateOfDischarge, maxWidth));
        }
        size_t length = 43 + lenID + lenAnimalType + lenAnimalBreed + lenAnimalSex + lenAnimalName + lenAnimalName + lenComment + lenOwner + lenDepartment + lenServiceType + lenServicePrice + lenDateOfReceipt + lenDateOfDischarge;
        for (int i = 0; i < length; i++)
        {
            std::cout << "=";
        }
        std::cout << std::endl;
        for (int i = 0; i < maxLinesCountTop; i++)
        {
            std::cout << "|| " << printw(id, lenID * maxLinesCountTop).substr(i * lenID, (i + 1) * lenID);
            std::cout << " || " << printw(animalType, lenAnimalType * maxLinesCountTop).substr(i * lenAnimalType, (i + 1) * lenAnimalType);
            std::cout << " || " << printw(animalBreed, lenAnimalBreed * maxLinesCountTop).substr(i * lenAnimalBreed, (i + 1) * lenAnimalBreed);
            std::cout << " || " << printw(animalSex, lenAnimalSex * maxLinesCountTop).substr(i * lenAnimalSex, (i + 1) * lenAnimalSex);
            std::cout << " || " << printw(animalName, lenAnimalName * maxLinesCountTop).substr(i * lenAnimalName, (i + 1) * lenAnimalName);
            std::cout << " || " << printw(comment, lenComment * maxLinesCountTop).substr(i * lenComment, (i + 1) * lenComment);
            std::cout << " || " << printw(owner, lenOwner * maxLinesCountTop).substr(i * lenOwner, (i + 1) * lenOwner);
            std::cout << " || " << printw(department, lenDepartment * maxLinesCountTop).substr(i * lenDepartment, (i + 1) * lenDepartment);
            std::cout << " || " << printw(serviceType, lenServiceType * maxLinesCountTop).substr(i * lenServiceType, (i + 1) * lenServiceType);
            std::cout << " || " << printw(servicePrice, lenServicePrice * maxLinesCountTop).substr(i * lenServicePrice, (i + 1) * lenServicePrice);
            std::cout << " || " << printw(dateOfReceipt, lenDateOfReceipt * maxLinesCountTop).substr(i * lenDateOfReceipt, (i + 1) * lenDateOfReceipt);
            std::cout << " || " << printw(dateOfDischarge, lenDateOfDischarge * maxLinesCountTop).substr(i * lenDateOfDischarge, (i + 1) * lenDateOfDischarge) << " ||";
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
                std::cout << "|| " << printwInt(i + 1, lenID * maxLinesCount[i]).substr(j * lenID, (j + 1) * lenID);
                std::cout << " || " << printw(table[i].getAnimalType(), lenAnimalType * maxLinesCount[i]).substr(i * lenAnimalType, (i + 1) * lenAnimalType);
            std::cout << " || " << printw(table[i].getAnimalBreed(), lenAnimalBreed * maxLinesCount[i]).substr(i * lenAnimalBreed, (i + 1) * lenAnimalBreed);
            std::cout << " || " << printw(table[i].getAnimalSex(), lenAnimalSex * maxLinesCount[i]).substr(i * lenAnimalSex, (i + 1) * lenAnimalSex);
            std::cout << " || " << printw(table[i].getAnimalName(), lenAnimalName * maxLinesCount[i]).substr(i * lenAnimalName, (i + 1) * lenAnimalName);
            std::cout << " || " << printw(table[i].getComment(), lenComment * maxLinesCount[i]).substr(i * lenComment, (i + 1) * lenComment);
            std::cout << " || " << printw(table[i].getOwner(), lenOwner * maxLinesCount[i]).substr(i * lenOwner, (i + 1) * lenOwner);
            std::cout << " || " << printw(table[i].getDepartment(), lenDepartment * maxLinesCount[i]).substr(i * lenDepartment, (i + 1) * lenDepartment);
            std::cout << " || " << printw(table[i].getServiceType(), lenServiceType * maxLinesCount[i]).substr(i * lenServiceType, (i + 1) * lenServiceType);
            std::cout << " || " << printw(table[i].getServicePrice(), lenServicePrice * maxLinesCount[i]).substr(i * lenServicePrice, (i + 1) * lenServicePrice);
            std::cout << " || " << printw(table[i].getDateOfReceipt().GetDateAsString(), lenDateOfReceipt * maxLinesCount[i]).substr(i * lenDateOfReceipt, (i + 1) * lenDateOfReceipt);
            std::cout << " || " << printw(table[i].getDateOfDischarge().GetDateAsString(), lenDateOfDischarge * maxLinesCount[i]).substr(i * lenDateOfDischarge, (i + 1) * lenDateOfDischarge);
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

int maxNum(int num1, int num2)
{
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
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
    for (int i = 0; i < width - str.length(); i++) {
        str += " ";
    }
    return str;
}

std::string printwInt(int num, int width) {
    return printw(std::to_string(num), width);
}

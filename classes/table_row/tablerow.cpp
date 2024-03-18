#include "tablerow.h"
#include "../../functions/correct_input/correctinput.h"

TableRow::TableRow() {
    animalType = "none";
    animalBreed = "none";
    animalSex = "none";
    animalName = "none";
    comment = "none";
    owner = "none";
    department = "none";
    serviceType = "none";
    servicePrice = "none";
    dateOfReceipt = Date();
    dateOfDischarge = Date();
}

std::string TableRow::getAnimalType() const {
    return animalType;
}

void TableRow::setAnimalType(const std::string &newAnimalType) {
    if (!isCorrectString(newAnimalType)) {
        return;
    }
    animalType = newAnimalType;
}

std::string TableRow::getAnimalBreed() const {
    return animalBreed;
}

void TableRow::setAnimalBreed(const std::string &newAnimalBreed) {
    if (!isCorrectString(newAnimalBreed)) {
        return;
    }
    animalBreed = newAnimalBreed;
}

std::string TableRow::getAnimalSex() const {
    return animalSex;
}

void TableRow::setAnimalSex(const std::string &newAnimalSex) {
    if (!isCorrectString(newAnimalSex)) {
        return;
    }
    animalSex = newAnimalSex;
}

std::string TableRow::getAnimalName() const {
    return animalName;
}

void TableRow::setAnimalName(const std::string &newAnimalName) {
    if (!isCorrectStringWithNumbers(newAnimalName)) {
        return;
    }
    animalName = newAnimalName;
}

std::string TableRow::getComment() const {
    return comment;
}

void TableRow::setComment(const std::string &newComment) {
    if (!isCorrectStringWithNumbers(newComment)) {
        return;
    }
    comment = newComment;
}

std::string TableRow::getOwner() const {
    return owner;
}

void TableRow::setOwner(const std::string &newOwner) {
    if (!isCorrectString(newOwner)) {
        return;
    }
    owner = newOwner;
}

std::string TableRow::getDepartment() const {
    return department;
}

void TableRow::setDepartment(const std::string &newDepartment) {
    if (!isCorrectStringWithNumbers(newDepartment)) {
        return;
    }
    department = newDepartment;
}

std::string TableRow::getServiceType() const {
    return serviceType;
}

void TableRow::setServiceType(const std::string &newServiceType) {
    if (!isCorrectString(newServiceType)) {
        return;
    }
    serviceType = newServiceType;
}

std::string TableRow::getServicePrice() const {
    return servicePrice;
}

void TableRow::setServicePrice(const std::string &newServicePrice) {
    if (!isCorrectStringWithNumbers(newServicePrice)) {
        return;
    }
    servicePrice = newServicePrice;
}

Date TableRow::getDateOfReceipt() const {
    return dateOfReceipt;
}

void TableRow::setDateOfReceipt(const unsigned int &newDay, const unsigned int &newMonth, const unsigned int &newYear) {
    dateOfReceipt.setDay(newDay);
    dateOfReceipt.setMonth(newMonth);
    dateOfReceipt.setYear(newYear);
}

Date TableRow::getDateOfDischarge() const {
    return dateOfDischarge;
}

void TableRow::setDateOfDischarge(const unsigned int &newDay, const unsigned int &newMonth, const unsigned int &newYear) {
    dateOfDischarge.setDay(newDay);
    dateOfDischarge.setMonth(newMonth);
    dateOfDischarge.setYear(newYear);
}

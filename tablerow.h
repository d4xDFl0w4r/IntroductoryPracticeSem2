#ifndef TABLEROW_H
#define TABLEROW_H

#include <string.h>
#include "date.h"

class TableRow
{
public:
    TableRow();


    string getAnimalType() const;
    void setAnimalType(const string &newAnimalType);

    string getAnimalBreed() const;
    void setAnimalBreed(const string &newAnimalBreed);

    string getAnimalSex() const;
    void setAnimalSex(const string &newAnimalSex);

    string getAnimalName() const;
    void setAnimalName(const string &newAnimalName);

    string getComment() const;
    void setComment(const string &newComment);

    string getOwner() const;
    void setOwner(const string &newOwner);

    string getDepartment() const;
    void setDepartment(const string &newDepartment);

    string getServiceType() const;
    void setServiceType(const string &newServiceType);

    string getServicePrice() const;
    void setServicePrice(const string &newServicePrice);

    date getDateOfReceipt() const;
    void setDateOfReceipt(const date &newDateOfReceipt);

private:
    static bool isCorrectString(const string &str);

    string animalType;
    string animalBreed;
    string animalSex;
    string animalName;
    string comment;
    string owner;
    string department;
    string serviceType;
    string servicePrice;
    Date dateOfReceipt;
    Date dateOfDischarge;
};

#endif // TABLEROW_H

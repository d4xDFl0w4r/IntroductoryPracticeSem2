#ifndef TABLEROW_H
#define TABLEROW_H

#include <string>
#include "../date/date.h"

class TableRow
{
public:
    TableRow();


    std::string getAnimalType() const;
    void setAnimalType(const std::string &newAnimalType);

    std::string getAnimalBreed() const;
    void setAnimalBreed(const std::string &newAnimalBreed);

    std::string getAnimalSex() const;
    void setAnimalSex(const std::string &newAnimalSex);

    std::string getAnimalName() const;
    void setAnimalName(const std::string &newAnimalName);

    std::string getComment() const;
    void setComment(const std::string &newComment);

    std::string getOwner() const;
    void setOwner(const std::string &newOwner);

    std::string getDepartment() const;
    void setDepartment(const std::string &newDepartment);

    std::string getServiceType() const;
    void setServiceType(const std::string &newServiceType);

    std::string getServicePrice() const;
    void setServicePrice(const std::string &newServicePrice);

    Date getDateOfReceipt() const;
    void setDateOfReceipt(const unsigned int &newDay, const unsigned int &newMonth, const unsigned int &newYear);
    void setDateOfReceipt(Date &newDate);

    Date getDateOfDischarge() const;
    void setDateOfDischarge(const unsigned int &newDay, const unsigned int &newMonth, const unsigned int &newYear);
    void setDateOfDischarge(Date &newDate);

private:
    std::string animalType;
    std::string animalBreed;
    std::string animalSex;
    std::string animalName;
    std::string comment;
    std::string owner;
    std::string department;
    std::string serviceType;
    std::string servicePrice;
    Date dateOfReceipt;
    Date dateOfDischarge;
};

#endif // TABLEROW_H

#include "tablerow.h"

TableRow::TableRow() {}

bool TableRow::isCorrectString(const string &str) {
    for (char character : str) {
        if ('я' < character && character < 'а' ||
            'Я' < character && character < 'А' ||
            'z' < character && character < 'a' ||
            'Z' < character && character < 'A' ||
            character == 'ё' || character == 'Ё') {
            return 0;
        }
    }
    return 1;
}

string TableRow::getAnimalType() const {
    return animalType;
}

void TableRow::setAnimalType(const string &newAnimalType) {
    if (isCorrectString(newAnimalType)) {
        return;
    }
    animalType = newAnimalType;
}

string TableRow::getAnimalBreed() const {
    return animalBreed;
}

void TableRow::setAnimalBreed(const string &newAnimalBreed) {
    if (isCorrectString(newAnimalBreed)) {
        return;
    }
    animalBreed = newAnimalBreed;
}

string TableRow::getAnimalSex() const {
    return animalSex;
}

void TableRow::setAnimalSex(const string &newAnimalSex) {
    if (isCorrectString(newAnimalSex)) {
        return;
    }
    animalSex = newAnimalSex;
}

string TableRow::getAnimalName() const {
    return animalName;
}

void TableRow::setAnimalName(const string &newAnimalName) {
    animalName = newAnimalName;
}

string TableRow::getComment() const {
    return comment;
}

void TableRow::setComment(const string &newComment) {
    comment = newComment;
}



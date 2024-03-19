#include "correctinput.h"

bool isCorrectString(const std::string &str) {
    for (char character : str) {
        if (!isalpha(character) && character != ' ') {
            return 0;
        }
    }
    return 1;
}

bool isCorrectStringWithNumbers(const std::string &str) {
    for (char character : str) {
        if (!isalnum(character)  && character != ' ') {
            return 0;
        }
    }
    return 1;
}

bool isCorrectNumber(const std::string &str) {
    for (char character : str) {
        if (!isdigit(character)) {
            return 0;
        }
    }
    return 1;
}

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

size_t length(std::wstring str) {
    size_t i = 0;
    for (char character : str) {
        i++;
    }
    return i;
}
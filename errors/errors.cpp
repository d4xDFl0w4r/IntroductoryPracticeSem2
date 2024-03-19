#include "errors.h"

void throwBadAllocException() {
    std::cout << "error: std::bad_alloc" << "\n\n";
}

void throwRangeException(std::string coutText, int bottom, int top) {
    std::cout << "error: " << coutText << " must be in range [" << bottom << ";" << top << "]" << "\n\n";
}

void throwEmptyStringException() {
    std::cout << "error: Empty string" << "\n\n";
}
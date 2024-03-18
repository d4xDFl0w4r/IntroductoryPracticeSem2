#include "errors.h"

void throwRangeException(std::string coutText, int bottom, int top) {
    std::cout << coutText << " must be in range [" << bottom << ";" << top << "]" << std::endl;
}
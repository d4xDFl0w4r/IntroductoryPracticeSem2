#ifndef ERRORS_H
#define ERRORS_H

#include <iostream>
#include <string>

void throwBadAllocException();
void throwRangeException(std::string coutText, int bottom, int top);
void throwEmptyStringException();

#endif //ERRORS_H
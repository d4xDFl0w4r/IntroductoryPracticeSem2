#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "../classes/tablerow.h"

void outputData(std::vector<TableRow> table);
int maxNum(int num1, int num2);
size_t linesCount(size_t len, size_t &maxWidth);
int intlen(int num);
std::string printw(std::string str, int width);
std::string printwInt(int num, int width);
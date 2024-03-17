#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

#include "../../classes/table_row/tablerow.h"

void printTable(std::vector<TableRow> table, size_t maxWidth);
size_t maxLength(size_t num1, size_t num2, size_t maxLength);
size_t linesCount(size_t len, size_t &maxWidth);
int intlen(int num);
std::string printw(std::string str, int width);
std::string printwInt(int num, int width);
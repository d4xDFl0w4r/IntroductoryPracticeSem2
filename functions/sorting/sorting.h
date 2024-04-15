#ifndef SORTING_H 
#define SORTING_H 
 
#include <iostream> 
#include <vector> 
 
#include "../../classes/table_row/tablerow.h"
#include "../../errors/errors.h"
 
bool firstEarlySecond(std::string first, std::string second); 
 
void sortTable(std::vector<TableRow>& table); 
 
#endif //SORTING_H
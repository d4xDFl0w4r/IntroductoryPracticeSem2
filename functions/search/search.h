#ifndef SEARCH_H 
#define SEARCH_H 
 
#include <iostream> 
#include <vector>

#include "../../classes/date/date.h" 
 
#include "../../classes/table_row/tablerow.h"
#include "../others/others.h"
#include "../../errors/errors.h" 
 
void searchRecord(std::vector<TableRow>& table, size_t maxWitdth); 
 
#endif //SEARCH_H
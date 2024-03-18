#ifndef EDITING_H
#define EDITING_H

#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "../../classes/table_row/tablerow.h"

std::string getString(std::string coutText);
void addRecord(std::vector<TableRow>& table);
void editRecord(std::vector<TableRow>& table);

#endif //EDITING_H
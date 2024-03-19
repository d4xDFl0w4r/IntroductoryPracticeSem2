#ifndef EDITING_H
#define EDITING_H

#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "../../classes/table_row/tablerow.h"
#include "../../errors/errors.h"
#include "../correct_input/correctinput.h"

std::string getString(std::string coutText);
Date getDate(std::string coutText);
void addRecord(std::vector<TableRow>& table);
void editRecord(std::vector<TableRow>& table);
int getInt(std::string strNum);

#endif //EDITING_H
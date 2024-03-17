#ifndef BINARYFILES_H
#define BINARYFILES_H

#include <fstream>
#include <vector>
#include "../classes/tablerow.h"

void ReadFromBinaryFile(std::string filename, std::vector<TableRow>& table);
void WriteToBinaryFile(std::string filename, std::vector<TableRow>& table);

#endif //BINARYFILES_H
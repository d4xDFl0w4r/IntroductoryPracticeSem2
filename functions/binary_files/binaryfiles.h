#ifndef BINARYFILES_H
#define BINARYFILES_H

#include <iostream>

#include <fstream>
#include <vector>
#include "../../classes/table_row/tablerow.h"

void ReadFromBinaryFile(std::string filename, std::vector<TableRow>& table);
void WriteToBinaryFile(std::string filename, std::vector<TableRow>& table);

void WriteString(std::ofstream& fout, std::string str);
std::string ReadString(std::ifstream& fin);

#endif //BINARYFILES_H
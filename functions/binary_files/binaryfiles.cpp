#include "binaryfiles.h"

void ReadFromBinaryFile(std::string filename, std::vector<TableRow>& table) {
    std::ifstream fin(filename, std::ios::binary);
    if (!fin.is_open()) {
        return;
    }

    TableRow buff;
    while (fin.read(reinterpret_cast<char*>(&buff), sizeof(TableRow))) {
        table.push_back(buff);
    }

    fin.close();
}


void WriteToBinaryFile(std::string filename, std::vector<TableRow>& table) {
    std::ofstream fout(filename, std::ios::binary);
    if (!fout.is_open()) {
        return;
    }
    
    for (int i = 0; i < table.size(); i++) {
        fout.write(reinterpret_cast<char*>(&table[i]), sizeof(&table[i]));
    }

    fout.close();
}
#include "binaryfiles.h"

void ReadFromBinaryFile(std::string filename, std::vector<TableRow>& table) {
    std::ifstream fin(filename, std::ios::binary);
    if (!fin.is_open()) {
        return;
    }

    TableRow buff;
    std::string buffstr;
    Date buffdate;

    while (true) {
        buffstr = ReadString(fin);
        buff.setAnimalType(buffstr);
        buffstr = ReadString(fin);
        buff.setAnimalBreed(buffstr);
        buffstr = ReadString(fin);
        buff.setAnimalSex(buffstr);
        buffstr = ReadString(fin);
        buff.setAnimalName(buffstr);
        buffstr = ReadString(fin);
        buff.setComment(buffstr);
        buffstr = ReadString(fin);
        buff.setOwner(buffstr);
        buffstr = ReadString(fin);
        buff.setDepartment(buffstr);
        buffstr = ReadString(fin);
        buff.setServiceType(buffstr);
        buffstr = ReadString(fin);
        buff.setServicePrice(buffstr);
        
        fin.read(reinterpret_cast<char*>(&buffdate), sizeof(Date));
        buff.setDateOfReceipt(buffdate);
        fin.read(reinterpret_cast<char*>(&buffdate), sizeof(Date));
        buff.setDateOfDischarge(buffdate);

        if (fin.eof()) {
            break;
        }

        table.push_back(buff);
    }

    fin.close();
}


void WriteToBinaryFile(std::string filename, std::vector<TableRow>& table) {
    std::ofstream fout(filename, std::ios::binary);
    if (!fout.is_open()) {
        return;
    }
    
    std::string buffstr;
    Date buffdate;

    for (int i = 0; i < table.size(); i++) {
        buffstr = table[i].getAnimalType();
        WriteString(fout, buffstr);
        buffstr = table[i].getAnimalBreed();
        WriteString(fout, buffstr);
        buffstr = table[i].getAnimalSex();
        WriteString(fout, buffstr);
        buffstr = table[i].getAnimalName();
        WriteString(fout, buffstr);
        buffstr = table[i].getComment();
        WriteString(fout, buffstr);
        buffstr = table[i].getOwner();
        WriteString(fout, buffstr);
        buffstr = table[i].getDepartment();
        WriteString(fout, buffstr);
        buffstr = table[i].getServiceType();
        WriteString(fout, buffstr);
        buffstr = table[i].getServicePrice();
        WriteString(fout, buffstr);

        buffdate = table[i].getDateOfReceipt();
        fout.write(reinterpret_cast<char*>(&buffdate), sizeof(Date));
        buffdate = table[i].getDateOfDischarge();
        fout.write(reinterpret_cast<char*>(&buffdate), sizeof(Date));
    }

    fout.close();
}


void WriteString(std::ofstream& fout, std::string str) {
    size_t len = str.length() + 1;
    fout.write(reinterpret_cast<char*>(&len), sizeof(len));
    fout.write(const_cast<char*>(str.c_str()),len);
}

std::string ReadString(std::ifstream& fin) {
    size_t len;
    fin.read(reinterpret_cast<char*>(&len), sizeof(len));
    char * buf = new char[len];
    fin.read(buf, len);
    std::string str = buf;
    delete[]buf;
    return str;
}
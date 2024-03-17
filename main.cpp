#include <string>
#include <vector>
#include <locale>

#include "classes/date.h"
#include "classes/tablerow.h"

#include "functions/others.h"
#include "functions/binaryfiles.h"

using namespace std;

int main(int argc, char *argv[])
{
    vector<TableRow> table;
    table.push_back(TableRow());
    table.push_back(TableRow());
    table.push_back(TableRow());
    table.push_back(TableRow());
    //ReadFromBinaryFile("test.bin", table);
    outputData(table);
    return 0;
}
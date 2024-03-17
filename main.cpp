#include <string>
#include <vector>
#include <locale>

#include "classes/date/date.h"
#include "classes/table_row/tablerow.h"

#include "functions/others/others.h"
#include "functions/binary_files/binaryfiles.h"

using namespace std;

int main(int argc, char *argv[])
{
    vector<TableRow> table;
    table.push_back(TableRow());
    table.push_back(TableRow());
    table.push_back(TableRow());
    table.push_back(TableRow());
    table.push_back(TableRow());
    table.push_back(TableRow());
    table.push_back(TableRow());
    table.push_back(TableRow());
    table.push_back(TableRow());
    table.push_back(TableRow());
    printTable(table, 20);
    return 0;
}
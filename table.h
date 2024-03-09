#ifndef TABLE_H
#define TABLE_H

#include <vector>

class Table
{
public:
    Table();

private:
    std::vector<TableRow> table;
    size_t size;
};

#endif // TABLE_H

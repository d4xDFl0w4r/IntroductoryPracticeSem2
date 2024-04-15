<<<<<<< HEAD
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Widget w;
    w.show();

    return a.exec();
}
=======
#include <string>
#include <vector>
#include <locale>

#include "classes/date/date.h"
#include "classes/table_row/tablerow.h"

#include "functions/others/others.h"
#include "functions/editing/editing.h"
#include "functions/sorting/sorting.h"
#include "functions/search/search.h"
#include "functions/binary_files/binaryfiles.h"

#include "classes/Menu/menu/menu.h"
#include "classes/Menu/menu_item/menuitem.h"

using namespace std;




vector<TableRow> table;

size_t maxWidth = 20;




int itemPrintTable() {
    printTable(table, maxWidth);
    return 1;
}

int itemAddRecord() {
    addRecord(table);
    return 2;
}

int itemEditRecords() {
    editRecord(table);
    return 3;
}

int itemSortTable() {
    sortTable(table);
    return 4;
}

int itemSearch() {
    searchRecord(table, maxWidth);
    return 5;
}

int itemOpenTable() {
    try {
        ReadFromBinaryFile(".data_files/data.bin", table);
    }
    catch (std::bad_alloc) {
        throwBadAllocException();
    }
    return 6;
}

int itemSaveTable() {
    WriteToBinaryFile(".data_files/data.bin", table);
    return 7;
}

int itemExit() {
    return 0;
}



int main(int argc, char *argv[]) {
    MenuItem menuItems[] {
        MenuItem("Print table", itemPrintTable),
        MenuItem("Add record", itemAddRecord),
        MenuItem("Edit record", itemEditRecords),
        MenuItem("Sort table", itemSortTable),
        MenuItem("Search", itemSearch),
        MenuItem("Open file", itemOpenTable),
        MenuItem("Save file", itemSaveTable),
        MenuItem("Exit", itemExit)
    };

    Menu menu(menuItems, sizeof(menuItems) / sizeof(menuItems[0]));

    while (menu.runCommand());

    return 0;
}
>>>>>>> 90d4c74fd8d54ddf1aa42cbae2ce266dbd18b88b

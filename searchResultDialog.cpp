#include "searchResultDialog.h"
#include "ui_searchResultDialog.h"

SearchResultDialog::SearchResultDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchResultDialog)
{
    ui->setupUi(this);
    QStringList title{};
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnCount(11);

    title << "Вид" << "Порода" << "Пол" << "Кличка"
          << "Владелец" << "Комментарий" << "Отделение"
          << "Оказываемая услуга" << "Стоимость услуги"
          << "Дата поступления" << "Дата выписки";
    ui->tableWidget->setHorizontalHeaderLabels(title);
    ui->tableWidget->resizeColumnsToContents();
}

SearchResultDialog::~SearchResultDialog()
{
    delete ui;
}

void SearchResultDialog::on_buttonBox_accepted()
{
    accept();
}


void SearchResultDialog::on_buttonBox_rejected()
{
    reject();
}

void SearchResultDialog::setSearchData(QStringList searchData, int columns)
{
    int rows{};
    rows = searchData.length() / columns;

    ui->tableWidget->setRowCount(rows);
    auto it = searchData.begin();

    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            ui->tableWidget->setItem(row, column, new QTableWidgetItem(*(it++)));
        }
    }

    ui->tableWidget->resizeColumnsToContents();
}

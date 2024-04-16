#include "searchFieldDialog.h"
#include "ui_searchFieldDialog.h"

SearchFieldDialog::SearchFieldDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchFieldDialog)
{
    ui->setupUi(this);
}

SearchFieldDialog::~SearchFieldDialog()
{
    delete ui;
}

void SearchFieldDialog::on_buttonBox_accepted()
{
    accept();
}


void SearchFieldDialog::on_buttonBox_rejected()
{
    reject();
}


void SearchFieldDialog::on_comboBox_activated(int index)
{
    switch (index) {
    case 0:
        ui->lineEdit->setEnabled(true);
        ui->dateEdit->setEnabled(false);
        break;
    case 1:
        ui->lineEdit->setEnabled(true);
        ui->dateEdit->setEnabled(false);
        break;
    case 2:
        ui->lineEdit->setEnabled(true);
        ui->dateEdit->setEnabled(false);
        break;
    case 3:
        ui->lineEdit->setEnabled(false);
        ui->dateEdit->setEnabled(true);
        break;
    default:
        break;
    }
}


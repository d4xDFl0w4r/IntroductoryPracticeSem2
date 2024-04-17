#include "searchFieldDialog.h"
#include "ui_searchFieldDialog.h"

SearchFieldDialog::SearchFieldDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchFieldDialog)
{
    ui->setupUi(this);

    ui->lineEdit->setVisible(true);
    ui->label_text->setVisible(true);

    ui->dateEdit->setVisible(false);
    ui->label_date->setVisible(false);
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
    _choose = index;
    switch (index)
    {
    case 0:
    case 1:
    case 2:
        ui->lineEdit->setVisible(true);
        ui->label_text->setVisible(true);

        ui->dateEdit->setVisible(false);
        ui->label_date->setVisible(false);
        break;
    case 3:
        ui->lineEdit->setVisible(false);
        ui->label_text->setVisible(false);

        ui->dateEdit->setVisible(true);
        ui->label_date->setVisible(true);
        break;
    default:
        break;
    }
}

int SearchFieldDialog::getChoose() const
{
    return _choose;
}

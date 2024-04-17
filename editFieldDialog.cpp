#include "editFieldDialog.h"
#include "ui_editFieldDialog.h"

EditFieldDialog::EditFieldDialog(QWidget *parent, QTableWidget *table)
    : QDialog(parent)
    , ui(new Ui::EditFieldDialog)
{
    ui->setupUi(this);

    ui->spinBox->setMaximum(table->rowCount());

    ui->label_text->setVisible(true);
    ui->label_date->setVisible(false);
    ui->lineEdit->setVisible(true);
    ui->dateEdit->setVisible(false);
}

EditFieldDialog::~EditFieldDialog()
{
    delete ui;
}

void EditFieldDialog::on_buttonBox_accepted()
{
    accept();
}


void EditFieldDialog::on_buttonBox_rejected()
{
    reject();
}


void EditFieldDialog::on_comboBox_activated(int index)
{
    if (index == 0)
    {
        ui->label_text->setVisible(true);
        ui->label_date->setVisible(false);
        ui->lineEdit->setVisible(true);
        ui->dateEdit->setVisible(false);
    }
    else if (index == 1)
    {
        ui->label_text->setVisible(false);
        ui->label_date->setVisible(true);
        ui->lineEdit->setVisible(false);
        ui->dateEdit->setVisible(true);
    }
}



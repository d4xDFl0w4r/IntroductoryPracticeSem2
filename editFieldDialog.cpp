#include "editFieldDialog.h"
#include "ui_editFieldDialog.h"

EditFieldDialog::EditFieldDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditFieldDialog)
{
    ui->setupUi(this);
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
        ui->lineEdit->setEnabled(true);
        ui->dateEdit->setEnabled(false);
    }
    else if (index == 1)
    {
        ui->lineEdit->setEnabled(false);
        ui->dateEdit->setEnabled(true);
    }
}


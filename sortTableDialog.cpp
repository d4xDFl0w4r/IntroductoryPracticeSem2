#include "sortTableDialog.h"
#include "ui_sortTableDialog.h"

SortTableDialog::SortTableDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SortTableDialog)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());
}

SortTableDialog::~SortTableDialog()
{
    delete ui;
}

void SortTableDialog::on_comboBox_2_activated(int index)
{
    _choose = index;
    if (index == 0)
    {
        ui->label_4->setStyleSheet("image: url(:/images/sort_A-Z.png);");
    }
    else if (index == 1)
    {
        ui->label_4->setStyleSheet("image: url(:/images/sort_Z-A.png);");
    }
}


void SortTableDialog::on_buttonBox_accepted()
{
    accept();
}


void SortTableDialog::on_buttonBox_rejected()
{
    reject();
}

int SortTableDialog::getChoose() const
{
    return _choose;
}

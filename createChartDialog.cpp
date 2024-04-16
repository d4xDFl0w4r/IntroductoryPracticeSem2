#include "createChartDialog.h"
#include "ui_createChartDialog.h"

CreateChartDialog::CreateChartDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateChartDialog)
{
    ui->setupUi(this);
}

CreateChartDialog::~CreateChartDialog()
{
    delete ui;
}

void CreateChartDialog::on_buttonBox_accepted()
{
    accept();
}


void CreateChartDialog::on_buttonBox_rejected()
{
    reject();
}


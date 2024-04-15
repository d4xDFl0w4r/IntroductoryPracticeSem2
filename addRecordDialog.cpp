#include "addRecordDialog.h"
#include "ui_addRecordDialog.h"

AddRecordDialog::AddRecordDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddRecordDialog)
{
    ui->setupUi(this);
}

AddRecordDialog::~AddRecordDialog()
{
    delete ui;
}

void AddRecordDialog::on_buttonBox_accepted()
{
    accept();
}


void AddRecordDialog::on_buttonBox_rejected()
{
    reject();
}

QString AddRecordDialog::getType() const
{
    return ui->type->text();
}
QString AddRecordDialog::getBreed() const
{
    return ui->breed->text();
}
QString AddRecordDialog::getGender() const
{
    return ui->gender->currentText();
}
QString AddRecordDialog::getPet() const
{
    return ui->pet->text();
}
QString AddRecordDialog::getOwner() const
{
    return ui->owner->text();
}
QString AddRecordDialog::getComment() const
{
    return ui->comment->text();
}
QString AddRecordDialog::getDepartment() const
{
    return ui->department->currentText();
}
QString AddRecordDialog::getService() const
{
    return ui->service->text();
}
double AddRecordDialog::getCost() const
{
    return ui->cost->value();
}
QString AddRecordDialog::getReceipt() const
{
    return ui->receipt->date().toString();
}
QString AddRecordDialog::getDischarge() const
{
    return ui->discharge->date().toString();
}

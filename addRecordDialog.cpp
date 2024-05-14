#include "addRecordDialog.h"
#include "ui_addRecordDialog.h"
#include <QPushButton>

AddRecordDialog::AddRecordDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddRecordDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    ui->receipt->setMaximumDate(QDate::currentDate());
    ui->discharge->setMaximumDate(QDate::currentDate());

    connect(ui->type, &QLineEdit::textChanged, this, &AddRecordDialog::handler_Text_Changed);
    connect(ui->breed, &QLineEdit::textChanged, this, &AddRecordDialog::handler_Text_Changed);
    connect(ui->pet, &QLineEdit::textChanged, this, &AddRecordDialog::handler_Text_Changed);
    connect(ui->owner, &QLineEdit::textChanged, this, &AddRecordDialog::handler_Text_Changed);
    connect(ui->comment, &QLineEdit::textChanged, this, &AddRecordDialog::handler_Text_Changed);
    connect(ui->service, &QLineEdit::textChanged, this, &AddRecordDialog::handler_Text_Changed);
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
    return ui->receipt->date().toString("dd.MM.yyyy");
}
QString AddRecordDialog::getDischarge() const
{
    return ui->discharge->date().toString("dd.MM.yyyy");
}

void AddRecordDialog::handler_Text_Changed(const QString& text)
{
    if (text.length() == 0 || NotRusLetters(text))
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
    else if (!EmptyFields() && !NotRusFields())
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}

bool AddRecordDialog::EmptyFields()
{
    return (
        ui->type->text().length() == 0 ||
        ui->breed->text().length() == 0 ||
        ui->pet->text().length() == 0 ||
        ui->owner->text().length() == 0 ||
        ui->comment->text().length() == 0 ||
        ui->service->text().length() == 0
    );
}

bool AddRecordDialog::NotRusFields()
{
    return (
        NotRusLetters(ui->type->text()) ||
        NotRusLetters(ui->breed->text()) ||
        NotRusLetters(ui->pet->text()) ||
        NotRusLetters(ui->owner->text()) ||
        NotRusLetters(ui->comment->text()) ||
        NotRusLetters(ui->service->text())
        );
}

bool AddRecordDialog::NotRusLetters(const QString &text)
{
    return text.contains(QRegularExpression("[^А-Яа-я ]"));
}

#include "editFieldDialog.h"
#include "ui_editFieldDialog.h"
#include <QPushButton>

EditFieldDialog::EditFieldDialog(QWidget *parent, QTableWidget *table)
    : QDialog(parent)
    , ui(new Ui::EditFieldDialog)
{
    ui->setupUi(this);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &EditFieldDialog::handler_Text_Changed);

    ui->spinBox->setMaximum(table->rowCount());
    ui->dateEdit->setMaximumDate(QDate::currentDate());

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
    choose = index;
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

int EditFieldDialog::getIndex() {
    return ui->spinBox->value() - 1;
}

int EditFieldDialog::getChoose() {
    return choose;
}

QString EditFieldDialog::getData() {
    if (choose == EditFieldDialog::Date) {
        return ui->dateEdit->date().toString("dd.MM.yyyy");
    }  else {
        return ui->lineEdit->text();
    }
}

void EditFieldDialog::handler_Text_Changed(const QString& text)
{
    if (text.length() == 0 || NotRusLetters(text))
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
    else
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}

bool EditFieldDialog::NotRusLetters(const QString &text)
{
    return text.contains(QRegularExpression("[^А-Яа-я ]"));
}

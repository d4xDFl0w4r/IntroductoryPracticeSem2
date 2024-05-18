#include "editFieldDialog.h"
#include "ui_editFieldDialog.h"
#include <QPushButton>

EditFieldDialog::EditFieldDialog(QWidget *parent, QTableWidget *table)
    : QDialog(parent)
    , ui(new Ui::EditFieldDialog)
    , table(table)
{
    ui->setupUi(this);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    connect(ui->lineEdit, &QLineEdit::textChanged, this, &EditFieldDialog::handler_TextChanged);
    connect(ui->spinBox, &QSpinBox::valueChanged, this, &EditFieldDialog::handler_IndexChanged);

    ui->spinBox->setMaximum(table->rowCount());
    ui->dateEdit->setMaximumDate(QDate::currentDate());

    ui->label_text->setVisible(true);
    ui->label_date->setVisible(false);
    ui->lineEdit->setVisible(true);
    ui->dateEdit->setVisible(false);

    ui->lineEdit->setText(table->item(0, COMMENT)->text());

    choose = 0;
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
    if (index == TEXT)
    {
        ui->label_text->setVisible(true);
        ui->label_date->setVisible(false);
        ui->lineEdit->setVisible(true);
        ui->dateEdit->setVisible(false);

        ui->lineEdit->setText(table->item(ui->spinBox->value() - 1, COMMENT)->text());
    }
    else if (index == DATE)
    {
        ui->label_text->setVisible(false);
        ui->label_date->setVisible(true);
        ui->lineEdit->setVisible(false);
        ui->dateEdit->setVisible(true);

        ui->dateEdit->setDate(QDate::fromString(table->item(ui->spinBox->value() - 1, DISCHARGE)->text(), "dd.MM.yyyy"));
    }
}

int EditFieldDialog::getIndex() {
    return ui->spinBox->value() - 1;
}

int EditFieldDialog::getChoose() {
    return choose;
}

QString EditFieldDialog::getData() {
    if (choose == DATE) {
        return ui->dateEdit->date().toString("dd.MM.yyyy");
    }  else {
        return ui->lineEdit->text();
    }
}

void EditFieldDialog::handler_IndexChanged(const int &index) {
    if (choose == TEXT) {
        ui->lineEdit->setText(table->item(index - 1, COMMENT)->text());
    } else {
        ui->dateEdit->setDate(QDate::fromString(table->item(index - 1, DISCHARGE)->text(), "dd.MM.yyyy"));
    }
}

void EditFieldDialog::handler_TextChanged(const QString& text)
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

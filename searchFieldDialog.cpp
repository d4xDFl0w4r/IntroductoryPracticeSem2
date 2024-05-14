#include "searchFieldDialog.h"
#include "ui_searchFieldDialog.h"
#include <QPushButton>

SearchFieldDialog::SearchFieldDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchFieldDialog)
{
    ui->setupUi(this);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    ui->dateEdit->setMaximumDate(QDate::currentDate());

    connect(ui->lineEdit, &QLineEdit::textChanged, this, &SearchFieldDialog::handler_Text_Changed);

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

        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
        break;
    case 3:
        ui->lineEdit->setVisible(false);
        ui->label_text->setVisible(false);

        ui->dateEdit->setVisible(true);
        ui->label_date->setVisible(true);

        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
        break;
    default:
        break;
    }
}

int SearchFieldDialog::getChoose() const
{
    return _choose;
}

QString SearchFieldDialog::getEdit() const
{
    return ui->lineEdit->text();
}

QString SearchFieldDialog::getDate() const
{
    return ui->dateEdit->date().toString();
}

void SearchFieldDialog::handler_Text_Changed(const QString& text)
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

bool SearchFieldDialog::NotRusLetters(const QString &text)
{
    return text.contains(QRegularExpression("[^А-Яа-я ]"));
}

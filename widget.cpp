#include "widget.h"
#include "ui_widget.h"
#include "addRecordDialog.h"
#include "sortTableDialog.h"
#include "searchFieldDialog.h"
#include "searchResultDialog.h"
#include "createChartDialog.h"
#include "editFieldDialog.h"
#include <QFile>
#include <QDataStream>
#include <QFileDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    keyCtrlS = new QShortcut(this);
    keyCtrlS->setKey(Qt::CTRL | Qt::Key_S);
    connect(keyCtrlS, SIGNAL(activated()), this, SLOT(on_saveFile_clicked()));

    keyCtrlO = new QShortcut(this);
    keyCtrlO->setKey(Qt::CTRL | Qt::Key_O);
    connect(keyCtrlO, SIGNAL(activated()), this, SLOT(on_openFile_clicked()));

    keyCtrlN = new QShortcut(this);
    keyCtrlN->setKey(Qt::CTRL | Qt::Key_N);
    connect(keyCtrlN, SIGNAL(activated()), this, SLOT(on_addRecord_clicked()));

    QStringList title{};
    ui->setupUi(this);
    setWindowTitle("Регистратура ветеринарной клиники");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnCount(11);

    title << "Вид" << "Порода" << "Пол" << "Кличка"
          << "Владелец" << "Комментарий" << "Отделение"
          << "Оказываемая услуга" << "Стоимость услуги"
          << "Дата поступления" << "Дата выписки";
    ui->tableWidget->setHorizontalHeaderLabels(title);
    ui->tableWidget->resizeColumnsToContents();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_addRecord_clicked()
{
    int result{};
    int lastRow{};
    AddRecordDialog ard(this);

    ard.setWindowTitle("Добавление записи пациента");
    result = ard.exec();

    if (result == QDialog::Rejected)
    {
        return;
    }

    QString type = ard.getType();
    QString breed = ard.getBreed();
    QString gender = ard.getGender();
    QString pet = ard.getPet();
    QString owner = ard.getOwner();
    QString comment = ard.getComment();
    QString department = ard.getDepartment();
    QString service = ard.getService();
    double cost = ard.getCost();
    QString receipt = ard.getReceipt();
    QString discharge = ard.getDischarge();

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    lastRow = ui->tableWidget->rowCount() - 1;
    ui->tableWidget->setItem(lastRow, TYPE, new QTableWidgetItem(type));
    ui->tableWidget->setItem(lastRow, BREED, new QTableWidgetItem(breed));
    ui->tableWidget->setItem(lastRow, GENDER, new QTableWidgetItem(gender));
    ui->tableWidget->setItem(lastRow, PET, new QTableWidgetItem(pet));
    ui->tableWidget->setItem(lastRow, OWNER, new QTableWidgetItem(owner));
    ui->tableWidget->setItem(lastRow, COMMENT, new QTableWidgetItem(comment));
    ui->tableWidget->setItem(lastRow, DEPARTMENT, new QTableWidgetItem(department));
    ui->tableWidget->setItem(lastRow, SERVICE, new QTableWidgetItem(service));
    ui->tableWidget->setItem(lastRow, COST, new QTableWidgetItem(QString::number(cost)));
    ui->tableWidget->setItem(lastRow, RECEIPT, new QTableWidgetItem(receipt));
    ui->tableWidget->setItem(lastRow, DISCHARGE, new QTableWidgetItem(discharge));

    ui->tableWidget->resizeColumnsToContents();
}

void WriteString(QDataStream& fout, QString str) {
    fout << str;
}

QString ReadString(QDataStream& fin) {
    QString buffstr;
    fin >> buffstr;
    return buffstr;
}

void Widget::on_openFile_clicked()
{
    QString filename{};

    filename = QFileDialog::getOpenFileName
            (
                this,
                tr("Открыть файл"),
                "/home/d4xdfl0w4r/Документы/VetClinicData",
                "Бинарные файлы (*.bin)"
            );

    if (filename.length() == 0)
    {
        return;
    }

    QFile file(filename);
    file.open(QFile::ReadOnly);

    if (!file.isOpen())
    {
        QMessageBox::critical
                (
                    this,
                    tr("Ошибка открытия файла"),
                    ("Файл " + filename.toStdString() + " не удалось открыть").c_str()
                );
        return;
    }

    if (file.atEnd())
    {
        QMessageBox::warning
                (
                    this,
                    tr("Предупреждение"),
                    ("Файл " + filename.toStdString() + " пустой, ничего не записалось в таблицу").c_str()
                );
    }

    ui->tableWidget->setRowCount(0);

    QDataStream fin(&file);

    for (int row = 0; !fin.atEnd(); row++)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        for (int column = 0; column < ui->tableWidget->columnCount(); column++)
        {
            ui->tableWidget->setItem(row, column, new QTableWidgetItem(ReadString(fin)));
        }
    }

    file.close();

    ui->tableWidget->resizeColumnsToContents();
}


void Widget::on_saveFile_clicked()
{
    QString filename{};

    filename = QFileDialog::getSaveFileName(this,
                       tr("Сохранить файл"), "/home/d4xdfl0w4r/Документы/VetClinicData", "Бинарные файлы (*.bin)");
    if (!filename.endsWith(".bin")) {
        filename.append(".bin");
    }

    QFile file(filename);
    file.open(QFile::WriteOnly);
    if (file.NotOpen) {
        QMessageBox::information(this, tr("Ошибка открытия файла"), ("Файл " + filename.toStdString() + " не удалось открыть").c_str());
        return;
    }

    QDataStream fout(&file);

    for (int row = 0; row < ui->tableWidget->rowCount(); row++)
    {
        for (int column = 0; column < ui->tableWidget->columnCount(); column++)
        {
            WriteString(fout, ui->tableWidget->item(row, column)->text());
        }
    }

    file.close();
}


void Widget::on_sortTable_clicked()
{
    if (ui->tableWidget->rowCount() == 0)
    {
        QMessageBox::warning
                (
                    this,
                    tr("Предупреждение"),
                    "Пустая таблица"
                );
        return;
    } else if (ui->tableWidget->rowCount() == 1)
    {
        QMessageBox::warning
                (
                    this,
                    tr("Предупреждение"),
                    "В таблице 1 элемент"
                );
        return;
    }

    int choose{};
    int result{};
    SortTableDialog std(this);

    std.setWindowTitle("Сортировка таблицы");
    result = std.exec();

    if (result == QDialog::Rejected)
    {
        return;
    }

    choose = std.getChoose();
    if (choose == 0)
    {
        ui->tableWidget->sortByColumn(TYPE, Qt::AscendingOrder);
    }
    else
    {
        ui->tableWidget->sortByColumn(TYPE, Qt::DescendingOrder);
    }
}


void Widget::on_searchField_clicked()
{
    if (ui->tableWidget->rowCount() == 0)
    {
        QMessageBox::warning
            (
                this,
                tr("Предупреждение"),
                "Пустая таблица"
                );
        return;
    }

    int choose{};
    int result{};
    int column{};
    QString text{};
    SearchFieldDialog sfd(this);

    sfd.setWindowTitle("Поиск по полю");
    result = sfd.exec();

    if (result == QDialog::Rejected)
    {
        return;
    }

    choose = sfd.getChoose();
    switch (choose)
    {
    case 0:
        column = TYPE;
        text = sfd.getEdit();
        break;
    case 1:
        column = OWNER;
        text = sfd.getEdit();
        break;
    case 2:
        column = SERVICE;
        text = sfd.getEdit();
        break;
    case 3:
        column = RECEIPT;
        text = sfd.getDate();
        break;
    default:
        break;
    }

    QStringList searchData;

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        if (ui->tableWidget->item(row, column)->text() == text)
        {
            for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
                searchData.append(ui->tableWidget->item(row, col)->text());
            }
        }
    }

    if (searchData.isEmpty())
    {
        QMessageBox::information
            (
                this,
                tr("Результат поиска"),
                "Ничего не найдено"
                );
        return;
    }
    else
    {
        SearchResultDialog srd(this);
        srd.setWindowTitle("Результат поиска");
        srd.setSearchData(searchData, ui->tableWidget->columnCount());
        result = srd.exec();

        if (result == QDialog::Rejected)
        {
            return;
        }
    }
}


void Widget::on_createChart_clicked()
{
    if (ui->tableWidget->rowCount() == 0)
    {
        QMessageBox::warning
                (
                    this,
                    tr("Предупреждение"),
                    "Пустая таблица"
                );
        return;
    }
    int result{};
    CreateChartDialog ccd(this, ui->tableWidget);

    ccd.setWindowTitle("Построение диаграммы");
    result = ccd.exec();

    if (result == QDialog::Rejected)
    {
        return;
    }
}


void Widget::on_editField_clicked()
{
    if (ui->tableWidget->rowCount() == 0)
    {
        QMessageBox::warning
                (
                    this,
                    tr("Предупреждение"),
                    "Пустая таблица"
                );
        return;
    }

    int result{};
    EditFieldDialog efd(this, ui->tableWidget);

    efd.setWindowTitle("Изменение записи");
    result = efd.exec();

    if (result == QDialog::Rejected)
    {
        return;
    }

    int column;
    if (efd.getChoose() == EditFieldDialog::DATE) {
        column = DISCHARGE;
    } else {
        column = COMMENT;
    }
    ui->tableWidget->setItem(efd.getIndex(), column, new QTableWidgetItem(efd.getData()));
}

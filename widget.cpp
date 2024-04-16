#include "widget.h"
#include "./ui_widget.h"
#include "addRecordDialog.h"
#include "sortTableDialog.h"
#include "searchFieldDialog.h"
#include "createChartDialog.h"
#include "editFieldDialog.h"
#include <QFileDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QStringList title{};
    ui->setupUi(this);
    setWindowTitle("Регистратура ветеринарной клиники");
    ui->tableWidget->setColumnCount(11);

    title << "Вид" << "Порода" << "Пол" << "Кличка"
          << "Владелец" << "Комментарий" << "Отделение"
          << "Оказываемая услуга" << "Стоимость услуги"
          << "Дата поступления" << "Дата выписки";
    ui->tableWidget->setHorizontalHeaderLabels(title);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_addRecord_clicked()
{
    QString type{};
    QString breed{};
    QString gender{};
    QString pet{};
    QString owner{};
    QString comment{};
    QString department{};
    QString service{};
    double cost{};
    QString receipt{};
    QString discharge{};

    int result{};
    int lastRow{};
    AddRecordDialog ard(this);

    ard.setWindowTitle("Добавление записи пациента");
    result = ard.exec();

    if (result == QDialog::Rejected)
    {
        return;
    }

    type = ard.getType();
    breed = ard.getBreed();
    gender = ard.getGender();
    pet = ard.getPet();
    owner = ard.getOwner();
    comment = ard.getComment();
    department = ard.getDepartment();
    service = ard.getService();
    cost = ard.getCost();
    receipt = ard.getReceipt();
    discharge = ard.getDischarge();

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
}


void Widget::on_openFile_clicked()
{
    QString fileName{};

    fileName = QFileDialog::getOpenFileName(this,
                       tr("Открыть файл"), "C://", "Все файлы (*.*)");
    QMessageBox::information(this, tr("Имя файла"), fileName);//Вместо этого код открытия файла
}


void Widget::on_saveFile_clicked()
{
    QString fileName{};

    fileName = QFileDialog::getOpenFileName(this,
                       tr("Сохранить файл"), "C://", "Все файлы (*.*)");
    QMessageBox::information(this, tr("Имя файла"), fileName);//Вместо этого код сохранения файла
}


void Widget::on_sortTable_clicked()
{
    int result{};
    SortTableDialog std(this);

    std.setWindowTitle("Сортировка таблицы");
    result = std.exec();

    if (result == QDialog::Rejected)
    {
        return;
    }

    //Код сортировки
}


void Widget::on_searchField_clicked()
{
    int result{};
    SearchFieldDialog sfd(this);

    sfd.setWindowTitle("Поиск по полю");
    result = sfd.exec();

    if (result == QDialog::Rejected)
    {
        return;
    }

    //Код поиска
}


void Widget::on_createChart_clicked()
{
    int result{};
    CreateChartDialog ccd(this);

    ccd.setWindowTitle("Построение диаграммы");
    result = ccd.exec();

    if (result == QDialog::Rejected)
    {
        return;
    }

    //Код вывода диаграммы
}


void Widget::on_editField_clicked()
{
    int result{};
    EditFieldDialog efd(this);

    efd.setWindowTitle("Построение диаграммы");
    result = efd.exec();

    if (result == QDialog::Rejected)
    {
        return;
    }

    //Код редактирования поля
}


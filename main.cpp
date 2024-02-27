#include "mainwindow.h"
#include "classdate.h"

#include <QApplication>
#include <QTableView>
#include <QStandardItemModel>
#include <QLabel>
#include <QString>

#include <string>

enum Column {

};

int main(int argc, char *argv[])
{
    QApplication a( argc, argv );
    //MainWindow w;
    //w.show();

    /*
    QWidget* widget = new QWidget;
    widget->setWindowTitle("Project");

    widget->setMinimumWidth( 1600 );
    widget->setMinimumHeight( 900 );

    QStandardItemModel* model = new QStandardItemModel(10, 11);

    model->setItem( 0, 0, new QStandardItem(1));
    model->setItem( 0, 1, new QStandardItem("Кошка домашняя, бенгальская"));
    model->setItem( 0, 2, new QStandardItem("М"));
    model->setItem( 0, 3, new QStandardItem("Симба"));
    model->setItem( 0, 4, new QStandardItem("Петров А.Н."));
    model->setItem( 0, 5, new QStandardItem("Гигиенические услуги"));
    model->setItem( 0, 6, new QStandardItem("Удаление клыка"));
    model->setItem( 0, 7, new QStandardItem(1100));
    model->setItem( 0, 8, new QStandardItem("Пирогов Г.В."));
    model->setItem( 0, 9, new QStandardItem("12.05.2021"));
    model->setItem( 0, 10, new QStandardItem("15.05.2021"));

    model->setItem( 1, 0, new QStandardItem(2));
    model->setItem( 1, 1, new QStandardItem("Радужный удав"));
    model->setItem( 1, 2, new QStandardItem("Ж"));
    model->setItem( 1, 3, new QStandardItem("Селеста"));
    model->setItem( 1, 4, new QStandardItem("Иванов П.И."));
    model->setItem( 1, 5, new QStandardItem("Терапия"));
    model->setItem( 1, 6, new QStandardItem("Лечение гиперавитаминоза"));
    model->setItem( 1, 7, new QStandardItem(2500));
    model->setItem( 1, 8, new QStandardItem("Смирнова П.А."));
    model->setItem( 1, 9, new QStandardItem("04.06.2021"));
    model->setItem( 1, 10, new QStandardItem("04.07.2021"));

    model->setHeaderData( 0, Qt::Horizontal, "id" );
    model->setHeaderData( 1, Qt::Horizontal, "Вид" );
    model->setHeaderData( 2, Qt::Horizontal, "Пол" );
    model->setHeaderData( 3, Qt::Horizontal, "Кличка" );
    model->setHeaderData( 4, Qt::Horizontal, "Владелец" );
    model->setHeaderData( 5, Qt::Horizontal, "Отделение" );
    model->setHeaderData( 6, Qt::Horizontal, "Оказываемая услуга" );
    model->setHeaderData( 7, Qt::Horizontal, "Стоимость услуги" );
    model->setHeaderData( 8, Qt::Horizontal, "Ветеринар" );
    model->setHeaderData( 9, Qt::Horizontal, "Дата поступления" );
    model->setHeaderData( 10, Qt::Horizontal, "Дата выписки" );

    QTableView* view = new QTableView( widget );
    view->setModel( model );
    view->setWordWrap( true );
    view->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    view->setCornerButtonEnabled( true );


    widget->show();*/

    Date* date1 = new Date(3, 9, 2005);
    Date* date2 = new Date(3, 11, 2005);

    QLabel* label = new QLabel(QString::fromStdString(std::to_string(Date::CompareDates(date1, date2))));
    label->show();

    return a.exec();
}
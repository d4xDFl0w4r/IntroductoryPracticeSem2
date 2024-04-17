#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QShortcut>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_addRecord_clicked();

    void on_openFile_clicked();

    void on_saveFile_clicked();

    void on_sortTable_clicked();

    void on_searchField_clicked();

    void on_createChart_clicked();

    void on_editField_clicked();

private:
    Ui::Widget *ui;

    enum Column
    {
        TYPE,
        BREED,
        GENDER,
        PET,
        OWNER,
        COMMENT,
        DEPARTMENT,
        SERVICE,
        COST,
        RECEIPT,
        DISCHARGE
    };

    QShortcut *keyCtrlS;
    QShortcut *keyCtrlO;
    QShortcut *keyCtrlN;
};
#endif // WIDGET_H

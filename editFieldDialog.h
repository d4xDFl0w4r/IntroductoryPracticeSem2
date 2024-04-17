#ifndef EDITFIELDDIALOG_H
#define EDITFIELDDIALOG_H

#include <QDialog>
#include <QTableWidget>

namespace Ui {
class EditFieldDialog;
}

class EditFieldDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditFieldDialog(QWidget *parent = nullptr, QTableWidget *table = nullptr);
    ~EditFieldDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_comboBox_activated(int index);

private:
    Ui::EditFieldDialog *ui;
};

#endif // EDITFIELDDIALOG_H

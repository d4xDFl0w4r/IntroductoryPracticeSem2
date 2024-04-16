#ifndef SEARCHFIELDDIALOG_H
#define SEARCHFIELDDIALOG_H

#include <QDialog>

namespace Ui {
class SearchFieldDialog;
}

class SearchFieldDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchFieldDialog(QWidget *parent = nullptr);
    ~SearchFieldDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_comboBox_activated(int index);

private:
    Ui::SearchFieldDialog *ui;
};

#endif // SEARCHFIELDDIALOG_H

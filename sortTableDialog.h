#ifndef SORTTABLEDIALOG_H
#define SORTTABLEDIALOG_H

#include <QDialog>

namespace Ui {
class SortTableDialog;
}

class SortTableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SortTableDialog(QWidget *parent = nullptr);
    ~SortTableDialog();

private slots:
    void on_comboBox_2_activated(int index);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::SortTableDialog *ui;
};

#endif // SORTTABLEDIALOG_H

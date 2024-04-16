#ifndef SORTTABLEDIALOG_H
#define SORTTABLEDIALOG_H

#include <QDialog>

namespace Ui {
class SortTableDialog;
}

class SortTableDialog : public QDialog
{
    Q_OBJECT
    int _choose{};

public:
    explicit SortTableDialog(QWidget *parent = nullptr);
    ~SortTableDialog();

    int getChoose() const;

private slots:
    void on_comboBox_2_activated(int index);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::SortTableDialog *ui;
};

#endif // SORTTABLEDIALOG_H

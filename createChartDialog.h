#ifndef CREATECHARTDIALOG_H
#define CREATECHARTDIALOG_H

#include <QDialog>

namespace Ui {
class CreateChartDialog;
}

class CreateChartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateChartDialog(QWidget *parent = nullptr);
    ~CreateChartDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::CreateChartDialog *ui;
};

#endif // CREATECHARTDIALOG_H

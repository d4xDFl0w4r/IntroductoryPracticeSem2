#ifndef CREATECHARTDIALOG_H
#define CREATECHARTDIALOG_H

#include <QDialog>
#include <QTableWidget>

namespace Ui {
class CreateChartDialog;
}

class CreateChartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateChartDialog(QWidget *parent = nullptr, QTableWidget *table = nullptr);
    ~CreateChartDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::CreateChartDialog *ui;

    enum Department
    {
        THERAPY,
        DENTISTRY,
        NEUROLOGY,
        TRAUMATOLOGY,
        SURGERY,
        OPHTALMOLOGY,
        BLOOD_ANALYSIS,
        VACCINATION,
        CARDIOLOGY
    };
};

#endif // CREATECHARTDIALOG_H

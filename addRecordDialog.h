#ifndef ADDRECORDDIALOG_H
#define ADDRECORDDIALOG_H

#include <QDialog>

namespace Ui {
class AddRecordDialog;
}

class AddRecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecordDialog(QWidget *parent = nullptr);
    ~AddRecordDialog();

    QString getType() const;
    QString getBreed() const;
    QString getGender() const;
    QString getPet() const;
    QString getOwner() const;
    QString getComment() const;
    QString getDepartment() const;
    QString getService() const;
    double getCost() const;
    QString getReceipt() const;
    QString getDischarge() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddRecordDialog *ui;

    void handler_Text_Changed(const QString& text);
    bool EmptyFields();
    bool NotRusLetters(const QString& text);
    bool NotRusFields();
};

#endif // ADDRECORDDIALOG_H

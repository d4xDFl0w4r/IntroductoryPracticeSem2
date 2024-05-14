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

    int getIndex();
    int getChoose();
    QString getData();

    enum Choose {
        Text,
        Date
    };

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_comboBox_activated(int index);

private:
    Ui::EditFieldDialog *ui;
    int choose;

    void handler_Text_Changed(const QString& text);
    bool NotRusLetters(const QString &text);
};

#endif // EDITFIELDDIALOG_H

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
        TEXT,
        DATE
    };

    enum Column {
	    COMMENT = 5,
	    DISCHARGE = 10
    };

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_comboBox_activated(int index);

private:
    Ui::EditFieldDialog *ui;
    QTableWidget *table;
    int choose;

    void handler_IndexChanged(const int& index);
    void handler_TextChanged(const QString& text);
    bool NotRusLetters(const QString &text);
};

#endif // EDITFIELDDIALOG_H

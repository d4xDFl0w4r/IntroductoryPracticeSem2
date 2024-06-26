#ifndef SEARCHFIELDDIALOG_H
#define SEARCHFIELDDIALOG_H

#include <QDialog>

namespace Ui {
class SearchFieldDialog;
}

class SearchFieldDialog : public QDialog
{
    Q_OBJECT
    int _choose{};

public:
    explicit SearchFieldDialog(QWidget *parent = nullptr);
    ~SearchFieldDialog();

    int getChoose() const;
    QString getEdit() const;
    QString getDate() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_comboBox_activated(int index);

private:
    Ui::SearchFieldDialog *ui;

    void handler_Text_Changed(const QString& text);
    bool NotRusLetters(const QString &text);
};

#endif // SEARCHFIELDDIALOG_H

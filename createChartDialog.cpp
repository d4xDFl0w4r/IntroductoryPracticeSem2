#include "createChartDialog.h"
#include "ui_createChartDialog.h"

#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

CreateChartDialog::CreateChartDialog(QWidget *parent, QTableWidget *table)
    : QDialog(parent)
    , ui(new Ui::CreateChartDialog)
{
    ui->setupUi(this);

    int departments[9]{};

    for (int row = 0; row < table->rowCount(); row++)
    {
        QString department = table->item(row, 6)->text();
        if (department == QString("Терапия"))
        {
            departments[THERAPY]++;
        }
        else if (department == "Стоматология")
        {
            departments[DENTISTRY]++;
        }
        else if (department == "Неврология")
        {
            departments[NEUROLOGY]++;
        }
        else if (department == "Травматология")
        {
            departments[TRAUMATOLOGY]++;
        }
        else if (department == "Хирургия")
        {
            departments[SURGERY]++;
        }
        else if (department == "Офтальмология")
        {
            departments[OPHTALMOLOGY]++;
        }
        else if (department == "Анализ крови с расшифровкой")
        {
            departments[BLOOD_ANALYSIS]++;
        }
        else if (department == "Вакцинация")
        {
            departments[VACCINATION]++;
        }
        else if (department == "Кардиология")
        {
            departments[CARDIOLOGY]++;
        }
    }

    QPieSeries *series = new QPieSeries();
    if (departments[THERAPY] > 0)
        series->append("Терапия", departments[THERAPY]);
    if (departments[DENTISTRY] > 0)
        series->append("Стоматология", departments[DENTISTRY]);
    if (departments[NEUROLOGY] > 0)
        series->append("Неврология", departments[NEUROLOGY]);
    if (departments[TRAUMATOLOGY] > 0)
        series->append("Травматология", departments[TRAUMATOLOGY]);
    if (departments[SURGERY] > 0)
        series->append("Хирургия", departments[SURGERY]);
    if (departments[OPHTALMOLOGY] > 0)
        series->append("Офтальмология", departments[OPHTALMOLOGY]);
    if (departments[BLOOD_ANALYSIS] > 0)
        series->append("Анализ крови с расшифровкой", departments[BLOOD_ANALYSIS]);
    if (departments[VACCINATION] > 0)
        series->append("Вакцинация", departments[VACCINATION]);
    if (departments[CARDIOLOGY] > 0)
        series->append("Кардиология", departments[CARDIOLOGY]);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Распределение пациентов по отделениям");

    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->horizontalFrame);
}

CreateChartDialog::~CreateChartDialog()
{
    delete ui;
}

void CreateChartDialog::on_buttonBox_accepted()
{
    accept();
}


void CreateChartDialog::on_buttonBox_rejected()
{
    reject();
}


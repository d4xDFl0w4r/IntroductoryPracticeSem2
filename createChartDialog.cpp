#include "createChartDialog.h"
#include "ui_createChartDialog.h"

#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>

void handle_hovered(QPieSlice* slice, bool state);
QString label = "";

CreateChartDialog::CreateChartDialog(QWidget *parent, QTableWidget *table)
    : QDialog(parent)
    , ui(new Ui::CreateChartDialog)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());

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
        else if (department == "Кардиология и ЭКГ")
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
        series->append("Анализ крови", departments[BLOOD_ANALYSIS]);
    if (departments[VACCINATION] > 0)
        series->append("Вакцинация", departments[VACCINATION]);
    if (departments[CARDIOLOGY] > 0)
        series->append("Кардиология", departments[CARDIOLOGY]);

    series->setHoleSize(0.25);

    QVector<QPieSlice*> slices;
    for (int i = 0; i < series->slices().count(); i++) {
        slices.push_back(series->slices().at(i));
        slices[i]->setLabelVisible(true);
    }

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);

    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTitle("Распределение пациентов по отделениям");
    chart->setTheme(QChart::ChartThemeQt);

    QChartView *chartView = new QChartView(chart);
    chartView->setFixedSize(this->geometry().width() - 25, this->geometry().height() - 55);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame);

    connect(series, &QPieSeries::hovered, this, handle_hovered);
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

void handle_hovered(QPieSlice* slice, bool state) {
    if (state) {
        slice->setExploded(true);
        label = slice->label();
        slice->setLabel(label + ": " + QString::number(round(slice->percentage() * 10000) / 100) + "%");
    }  else {
        slice->setExploded(false);
        slice->setLabel(label);
    }
}

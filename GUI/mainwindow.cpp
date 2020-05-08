#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // -------------------------------- Init GUI Pointers -----------------------------------------
    mainWidget = new QWidget();
    mainLayout = new QHBoxLayout();
    memoryLayout = new QVBoxLayout();
//    chartView = new QChartView();
//    chart = new QChart();
//    stackedSeries = new QHorizontalStackedBarSeries();

    sWidget = new QStackedWidget();
    widget1 = new HolesWidget();
    widget2 = new ProcessWidget();
    //-----------------------------Assigning Layouts and Widgets---------------------------------------------------
    this->setCentralWidget(mainWidget);
    mainWidget->setLayout(mainLayout);
    mainLayout->addWidget(sWidget);
    mainLayout->addLayout(memoryLayout);

    sWidget->addWidget(widget1);
    sWidget->addWidget(widget2);

    /*sWidget->setCurrentIndex() depending on pressing next or back*/
    sWidget->setCurrentIndex(1);
    this->setWindowTitle("Processes Init");

}

MainWindow::~MainWindow()
{
}


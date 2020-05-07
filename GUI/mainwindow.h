#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QGroupBox>
#include <QTableWidget>
#include <QHeaderView>
#include <QGroupBox>

#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QHorizontalStackedBarSeries>
//#include <QValueAxis>
//#include <QSizePolicy>
#include "processstack.h"

QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget* mainWidget;
    QHBoxLayout* mainLayout;
    QVBoxLayout* memoryLayout;
    QVBoxLayout* memLayout;
    QVBoxLayout* processLayout;
    QHBoxLayout* btnsLayout;
    QStackedWidget* sWidget;
    QWidget* widget1;
    QWidget* widget2;
    QLabel* memory;
    QPushButton* btnAddHole;
    QPushButton* btnDelHole;
    QPushButton* btnNext;
    QPushButton* btnAddSeg;
    QPushButton* btnDelSeg;
    QPushButton* btnNextSeg;
    QPushButton* btnDone;


    QListWidget* processesList;
    QFormLayout* formLayout;
    QLabel* memLabel;
    QLineEdit* memSizeEdit;
    QTableWidget* memTable;
    QHeaderView* tableHeader;
    QChartView* chartView;
    QChart *chart;
    QHorizontalStackedBarSeries *stackedSeries;

    QStackedWidget* pStackWidget;
    ProcessStack* pStack;
    friend class GUIController;

};
#endif // MAINWINDOW_H

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


//#include <QValueAxis>
//#include <QSizePolicy>

#include "holeswidget.h"
#include "processwidget.h"

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget* mainWidget;
    QHBoxLayout* mainLayout;
    QVBoxLayout* memoryLayout;
//    QVBoxLayout* processLayout;
//    QHBoxLayout* btnsLayout;
    QStackedWidget* sWidget;
    HolesWidget* widget1;
    ProcessWidget* widget2;
//    QPushButton* btnAddSeg;
//    QPushButton* btnDelSeg;
//    QPushButton* btnNextSeg;
//    QPushButton* btnDone;


//    QListWidget* processesList;

//    QChartView* chartView;
//    QChart *chart;
//    QHorizontalStackedBarSeries *stackedSeries;

//    QStackedWidget* pStackWidget;
//    ProcessStack* pStack;
    friend class GUIContoller;

};
#endif // MAINWINDOW_H

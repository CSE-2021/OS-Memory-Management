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

#include "shape.h"
#include "sketch.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>


//#include <QValueAxis>
//#include <QSizePolicy>
#include "processstack.h"

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
    QGroupBox* memBox;
    QVBoxLayout* dummyLayout;
    QHBoxLayout* btns1Layout;
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

    QGraphicsView *v;
    Sketch* sc;
    Shape* Memory;


    QListWidget* processesList;
    QFormLayout* formLayout;
    QLabel* memLabel;
    QLineEdit* memSizeEdit;
    QTableWidget* memTable;
    QHeaderView* tableHeader;
//    QChartView* chartView;
//    QChart *chart;
//    QHorizontalStackedBarSeries *stackedSeries;

    QStackedWidget* pStackWidget;
    ProcessStack* pStack;





    friend class GUIController;

};
#endif // MAINWINDOW_H

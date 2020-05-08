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


<<<<<<< HEAD
    QGraphicsView *v;
    Sketch* sc;
    Shape* Memory;

=======
//    QListWidget* processesList;
>>>>>>> 7cb871d00a2c235535f323dcebf49423c41693f7

//    QChartView* chartView;
//    QChart *chart;
//    QHorizontalStackedBarSeries *stackedSeries;

<<<<<<< HEAD
    QStackedWidget* pStackWidget;
    ProcessStack* pStack;





    friend class GUIController;
=======
//    QStackedWidget* pStackWidget;
//    ProcessStack* pStack;
    friend class GUIContoller;
>>>>>>> 7cb871d00a2c235535f323dcebf49423c41693f7

};
#endif // MAINWINDOW_H

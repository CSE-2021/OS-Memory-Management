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
    friend class GUIController;
    QWidget* mainWidget;
    QHBoxLayout* mainLayout;
    QVBoxLayout* memoryLayout;
    QStackedWidget* sWidget;
    HolesWidget* widget1;
    ProcessWidget* widget2;
    QGraphicsView *v;
    Sketch* sc;
    Shape* Memory;



};
#endif // MAINWINDOW_H

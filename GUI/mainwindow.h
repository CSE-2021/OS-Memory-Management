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
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>
#include <QPainter>

//#include <QValueAxis>
//#include <QSizePolicy>

#include "holeswidget.h"
#include "processwidget.h"
#include "chart.h"
#include "sketch.h"
#include "shape.h"

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget* mainWidget;
    QHBoxLayout* mainLayout;
    QVBoxLayout* memoryLayout;
    QStackedWidget* sWidget;
    HolesWidget* widget1;
    ProcessWidget* widget2;
    QGraphicsView *v;
    Sketch* sc;
    Shape* Memory;
    Shape* segment;
void guiInit();
void Draw();
void drawMemory();

    friend class GUIContoller;

};
#endif // MAINWINDOW_H

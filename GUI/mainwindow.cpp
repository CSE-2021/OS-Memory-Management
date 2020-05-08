#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // -------------------------------- Init GUI Pointers -----------------------------------------
    mainWidget = new QWidget();
    mainLayout = new QHBoxLayout();
    memoryLayout = new QVBoxLayout();
    widget1 = new HolesWidget();
    widget2 = new ProcessWidget();
    v = new QGraphicsView();
    sc= new Sketch();
    sWidget = new QStackedWidget();

    //----------------------------------------trying chart-----------------------------------------------------------
    Memory= new Shape(1103,64,1258,275,Shape::RECTANGLE,5);
      Memory->setText("Memory" ,Shape::MIDDLE);

        sc->drawShape(Memory);



    //-----------------------------Assigning Layouts and Widgets---------------------------------------------------

    this->setCentralWidget(mainWidget);
    mainWidget->setLayout(mainLayout);
    mainLayout->addWidget(sWidget);
    mainLayout->addLayout(memoryLayout);

    sWidget->addWidget(widget1);
    sWidget->addWidget(widget2);



    sWidget->setCurrentIndex(0);
    this->setWindowTitle("Holes Init");
     memoryLayout->addWidget(v);
     v->setScene(sc);
}

MainWindow::~MainWindow()
{
}


#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // -------------------------------- Init GUI Pointers -----------------------------------------
    guiInit();
    //----------------------------------------trying chart-----------------------------------------------------------
    drawMemory();
    //-----------------------------Assigning Layouts and Widgets---------------------------------------------------
    Draw();

}
void MainWindow::guiInit()
{
    mainWidget = new QWidget();
    mainLayout = new QHBoxLayout();
    memoryLayout = new QVBoxLayout();
    sWidget = new QStackedWidget();
    widget1 = new HolesWidget();
    widget2 = new ProcessWidget();
    v = new QGraphicsView();
    sc= new Sketch();
}
void MainWindow::Draw()
{
    this->setCentralWidget(mainWidget);
    mainWidget->setLayout(mainLayout);
    mainLayout->addWidget(sWidget);
    mainLayout->addLayout(memoryLayout);

    sWidget->addWidget(widget1);
    sWidget->addWidget(widget2);

    /*sWidget->setCurrentIndex() depending on pressing next or back*/
    sWidget->setCurrentIndex(0);
    this->setWindowTitle("Processes Init");

}
void MainWindow::drawMemory()
{
    Memory= new Shape(1103,64,1258,275,Shape::RECTANGLE,3);
    Memory->setText("Memory" ,Shape::MIDDLE);
    sc->drawShape(Memory);

    memoryLayout->addWidget(v);
    v->setScene(sc);
}
MainWindow::~MainWindow()
{
}


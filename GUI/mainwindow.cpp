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
    this->setWindowTitle("Holes Init");

}
void MainWindow::drawMemory()
{
    Shape* dummy = new Shape(0,0,300,50,Shape::RECTANGLE2,4,QBrush(Qt::red,Qt::CrossPattern));
    dummy->setText("Memory",Shape::MIDDLE);
    sc->drawShape(dummy);
    memoryLayout->addWidget(v);
    v->setScene(sc);
}
MainWindow::~MainWindow()
{
}


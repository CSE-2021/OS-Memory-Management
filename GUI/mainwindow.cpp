#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // --------------------------------------------- Init GUI Pointers ---------------------------------------------
    mainWidget = new QWidget();
    mainLayout = new QHBoxLayout();
    memoryLayout = new QVBoxLayout();
    chartView = new QChartView();
    chart = new QChart();
    stackedSeries = new QHorizontalStackedBarSeries();

    sWidget = new QStackedWidget();
    pStack = new ProcessStack();
    memLayout = new QVBoxLayout();
    processLayout = new QVBoxLayout();
    widget1 = new QWidget();
    widget2 = new QWidget();
    btnAddHole = new QPushButton("Add Hole");
    btnDelHole = new QPushButton("Delete Hole");
    btnNext = new QPushButton("Next");

    btnsLayout= new QHBoxLayout();
    btnAddSeg= new QPushButton("Add Segment");
    btnDelSeg= new QPushButton ("Delete Segment");
    btnNextSeg = new QPushButton("Next Process");
    btnDone = new QPushButton("Previous Process");

    memory = new QLabel("Memory");
    formLayout = new QFormLayout();
    memLabel = new QLabel("Memory Size:");
    memLabel->setFont(QFont("Magma",15));
    memSizeEdit = new  QLineEdit();

//    processesInfo = new QGroupBox("Process 1", this);

//    memSize->setFont(QFont("Magma",15,Qt::black));
    formLayout->addRow(memLabel,memSizeEdit);
    formLayout->addRow(btnAddHole,btnDelHole);


    memTable = new QTableWidget();
    tableHeader = memTable->horizontalHeader();

    memTable->setColumnCount(3);
    QStringList list = {"Hole Name","Base Address","Limit"};
    memTable->setHorizontalHeaderLabels(list);
    tableHeader->setSectionResizeMode(QHeaderView::Stretch);

    processesList = new QListWidget();
    pStackWidget = new QStackedWidget();
//    QVector<Process> processes;
//    QStringList p;
//    processes = Process::all();
//    qDebug()<<processes[0].getName();
//    for (Process i: processes){
//         qDebug()<<i.getName();
//         p.append(i.getName());
//     }



    //---------------------------------------Object Names------------------------------------------
    memory->setObjectName("MemoryLabel");
    memLabel->setObjectName("MemorySizeLabel");
    memSizeEdit->setObjectName("MemorySizeEdit");


    //---------------------------------------StyleSheets---------------------------------------
    memory->setAlignment(Qt::AlignTop);
    memory->setFixedHeight(47);

    btnDelHole->setFixedWidth(100);
    memTable->setAlternatingRowColors(true);
    memTable->setStyleSheet("alternate-background-color:lightgray;text-align:center");
    formLayout->setFormAlignment(Qt::AlignCenter); //to be changed


    //-----------------------------------------Assigning Layouts and Widgets---------------------------------------------------
    this->setCentralWidget(mainWidget);
    mainWidget->setLayout(mainLayout);
    mainLayout->addWidget(sWidget);
    mainLayout->addLayout(memoryLayout);

    chart->addSeries(stackedSeries);
    chartView->setChart(chart);
    memoryLayout->addWidget(chartView);



    sWidget->addWidget(widget1);
    sWidget->addWidget(widget2);
//    sWidget->setCurrentWidget(widget2);

    widget1->setLayout(memLayout);
    memLayout->addWidget(memory);
    memLayout->addLayout(formLayout);
    memLayout->addWidget(memTable);

    widget2->setLayout(processLayout);
    /*sWidget->setCurrentIndex() depending on pressing next or back*/
    sWidget->setCurrentIndex(0);
/*in GUICONTROLLER
    pStackWidget->setCurrentIndex(processesList.currentIndex());
*/
    processLayout->addWidget(pStackWidget);
    pStackWidget->addWidget(pStack);
    pStackWidget->setCurrentWidget(pStack);

    processLayout->addLayout(btnsLayout);
    btnsLayout->addWidget(btnAddSeg);
    btnsLayout->addWidget(btnDelSeg);
    btnsLayout->addWidget(btnNextSeg);
    btnsLayout->addWidget(btnDone);
    QGroupBox *processList = new QGroupBox("Processes");
    QGridLayout *lay = new QGridLayout();
    processList->setLayout(lay);
    lay->addWidget(processesList,0,0,1,1);;
    processLayout->addWidget(processList);

    QStringList p = {"P1","P2"};
     processesList->addItems(p);



}

MainWindow::~MainWindow()
{
}


#include "processwidget.h"

ProcessWidget::ProcessWidget(QWidget* parent): QWidget(parent)
{
    //-------------------------------GUI Init Pointers------------------------------------------
    guiInit();
    //----------------------------------Ordering Layouts------------------------------------------
    draw();
     //    QVector<Process> processes;
     //    QStringList p;
     //    processes = Process::all();
     //    qDebug()<<processes[0].getName();
     //    for (Process i: processes){
     //         qDebug()<<i.getName();
     //         p.append(i.getName());
     //     }
}
void ProcessWidget::guiInit()
{
    mainLayout = new QVBoxLayout();
    btnsLayout = new QHBoxLayout();
    btnAddSeg= new QPushButton("Add Segment");
    btnDelSeg= new QPushButton ("Delete Segment");
    btnNextPro = new QPushButton("Allocate New Process");
    btnPrevPro = new QPushButton("Deallocate Process");
    pStackWidget = new QStackedWidget();
    pStack = new ProcessStack(this,"P1");
    processList = new QGroupBox("Processes");
    lay= new QGridLayout();
    processesList = new QListWidget();
    processesList->setAlternatingRowColors(true);
    p = new QStringList({"P1"});
    btnReset = new QPushButton("Reset");
}
void ProcessWidget::draw()
{
    this->setLayout(mainLayout);
    mainLayout->addWidget(pStackWidget);
    pStackWidget->addWidget(pStack);
    pStackWidget->setCurrentWidget(pStack);
    mainLayout->addLayout(btnsLayout);
    mainLayout->addWidget(processList);
    mainLayout->addWidget(btnReset,0,Qt::AlignRight);


    btnsLayout->addWidget(btnAddSeg);
    btnsLayout->addWidget(btnDelSeg);
    btnsLayout->addWidget(btnPrevPro);
    btnsLayout->addWidget(btnNextPro);
    /*in GUICONTROLLER
        pStackWidget->setCurrentIndex(processesList.currentIndex());
    */
    processList->setLayout(lay);
    lay->addWidget(processesList,0,0,1,1);

    processesList->addItems(*p);
//    addProcess();
}
void ProcessWidget::addProcess()
{
    for(int i=0;i<p->size();i++)
    {
        pStack = new ProcessStack(this,p->value(i));
        pStackWidget->addWidget(pStack);
    }

}

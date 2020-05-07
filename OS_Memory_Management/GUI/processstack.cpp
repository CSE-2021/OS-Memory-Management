#include "processstack.h"

ProcessStack::ProcessStack(QWidget *parent)
    : QWidget(parent)
{
// --------------------------------------------- Init GUI Pointers ---------------
   stackedLayout = new QVBoxLayout();
//   processWidget = new QStackedWidget();
   segLayout = new QFormLayout();
   processLbl = new QLabel("Processes");
   ProcessNameEdit = new QLineEdit();
//   ProcessNameEdit->setPlaceholderText("P"+QString(i));
   segLbl = new QLabel("Number Of Segments:");
   segNumEdit = new QLineEdit();
   segLayout->addRow(processLbl,ProcessNameEdit);
   segLayout->addRow(segLbl,segNumEdit);

   processTable = new QTableWidget();
   tableHead = processTable->horizontalHeader();

   processTable->setColumnCount(3);
   QStringList list = {"Segment Name","Base Address","Limit"};
   processTable->setHorizontalHeaderLabels(list);
   tableHead->setSectionResizeMode(QHeaderView::Stretch);




 //---------------------------------------StyleSheets---------------------------------------
   processLbl->setStyleSheet("font:20pt;color:cyan; border-bottom-width: 1px; border-bottom-style: solid;border-radius: 0px;");
   processLbl->setAlignment(Qt::AlignTop);
   processLbl->setFixedHeight(47);
 //-----------------------------------------Assigning Layouts and Widgets-----------------------

   this->setLayout(stackedLayout);
   stackedLayout->addWidget(processLbl);
   stackedLayout->addLayout(segLayout);
   stackedLayout->addWidget(processTable);
//   stackedLayout->addWidget(processWidget);
//   processWidget->addWidget(processTable);




}

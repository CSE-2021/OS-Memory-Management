#include "processstack.h"

ProcessStack::ProcessStack(QWidget *parent) : QGroupBox(parent){
// --------------------------------------------- Init GUI Pointers ---------------
   mainLayout = new QVBoxLayout();
   this->setTitle("Process 2");

   processTable = new QTableWidget();
   processTable->setAlternatingRowColors(true);
   tableHead = processTable->horizontalHeader();

   processTable->setColumnCount(3);
   QStringList list = {"Segment Name","Base Address","Limit"};
   processTable->setHorizontalHeaderLabels(list);
   tableHead->setSectionResizeMode(QHeaderView::Stretch);

   this->setLayout(mainLayout);
   mainLayout->addWidget(processTable);
}

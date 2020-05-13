#include "processstack.h"

ProcessStack::ProcessStack(QWidget *parent,QString s) : QGroupBox(parent){
// --------------------------------------------- Init GUI Pointers ---------------
   mainLayout = new QVBoxLayout();
   this->setTitle(s);
   processName = new QLineEdit(this);
   processName->setPlaceholderText("change process name");
   processTable = new QTableWidget();
   processTable->setAlternatingRowColors(true);
   tableHead = processTable->horizontalHeader();

   processTable->setColumnCount(3);
   QStringList list = {"Segment Name","Base Address","Limit"};
   processTable->setHorizontalHeaderLabels(list);
   tableHead->setSectionResizeMode(QHeaderView::Stretch);

   this->setLayout(mainLayout);
   mainLayout->addWidget(processName);
   mainLayout->addWidget(processTable);
}

#include "holeswidget.h"

HolesWidget::HolesWidget(QWidget* parent): QGroupBox(parent)
{
    //--------------------------------- Init GUI Pointers------------------------------------
    mainLayout = new QVBoxLayout();
    formLayout = new QFormLayout();
    memSizeLbl = new QLabel("Memory Size:");
    memSizeEdit = new  QLineEdit();
    memTable = new QTableWidget();
    tableHeader = memTable->horizontalHeader();
    memTable->setColumnCount(3);
    QStringList list = {"Hole Name","Base Address","Limit"};
    memTable->setHorizontalHeaderLabels(list);
    tableHeader->setSectionResizeMode(QHeaderView::Stretch);
    btns1Layout = new QHBoxLayout();
    btnAddHole = new QPushButton("Add Hole");
    btnDelHole = new QPushButton("Delete Hole");
    btnNext = new QPushButton("Next");

    //---------------------------------Objects Names---------------------------------------
    this->setObjectName("HolesWidget");
    memSizeLbl->setObjectName("MemorySizeLabel");
    memSizeEdit->setObjectName("MemorySizeEdit");
    memTable->setObjectName("MemoryTable");
    //---------------------------------Ordering Layouts-------------------------------------
    this->setTitle("Memory");
    this->setLayout(mainLayout);
    mainLayout->addLayout(formLayout);
    formLayout->addRow(memSizeLbl,memSizeEdit);
    mainLayout->addWidget(memTable);
    mainLayout->addLayout(btns1Layout);
    btns1Layout->addWidget(btnAddHole);
    btns1Layout->addWidget(btnDelHole);
    btns1Layout->addWidget(btnNext);

}

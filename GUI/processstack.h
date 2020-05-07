#ifndef PROCESSSTACK_H
#define PROCESSSTACK_H

#include <QWidget>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QGroupBox>

class ProcessStack : public QGroupBox{
    Q_OBJECT

public:
    ProcessStack(QWidget *parent = nullptr);
    QVBoxLayout* mainLayout;
    QTableWidget* processTable;
    QHeaderView * tableHead;
    QGroupBox *processesInfo;

};

#endif // PROCESSSTACK_H

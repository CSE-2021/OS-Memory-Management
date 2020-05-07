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



class ProcessStack : public QWidget
{
    Q_OBJECT

public:
    ProcessStack(QWidget *parent = nullptr);
//    QStackedWidget * processWidget;
    QVBoxLayout* stackedLayout;
    QHBoxLayout* buttonsLayout;
    QFormLayout* segLayout;
    QTableWidget* processTable;
    QLabel * processLbl;
    QLineEdit* ProcessNameEdit;
    QHeaderView * tableHead;
    QLabel * segLbl;
    QLineEdit * segNumEdit;

};

#endif // PROCESSSTACK_H

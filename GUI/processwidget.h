#ifndef PROCESSWIDGET_H
#define PROCESSWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QListWidget>
#include "processstack.h"

class ProcessWidget :public QGroupBox
{
    Q_OBJECT
public:
    ProcessWidget(QWidget* parent = nullptr);
private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* btnsLayout;
    QPushButton* btnAddSeg;
    QPushButton* btnDelSeg;
    QPushButton* btnNextSeg;
    QPushButton* btnPrev;
    QGroupBox *processList;
    QStackedWidget* pStackWidget;
    ProcessStack* pStack;
    QGridLayout *lay;
    QListWidget* processesList;

   friend class GUIController;
};

#endif // PROCESSWIDGET_H

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

class ProcessWidget :public QWidget{
    Q_OBJECT
public:
    ProcessWidget(QWidget* parent = nullptr);
    QStackedWidget* pStackWidget;
    ProcessStack* pStack;
    QPushButton* btnAddSeg;
    QPushButton* btnDelSeg;
private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* btnsLayout;
    QPushButton* btnNextSeg;
    QPushButton* btnPrev;
    QGroupBox *processList;
    QGridLayout *lay;
    QListWidget* processesList;

    void guiInit();
    void draw();
    friend class GUIController;
};

#endif // PROCESSWIDGET_H

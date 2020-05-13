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
    QPushButton* btnNextPro;
    QPushButton* btnPrevPro;
    QPushButton* btnReset;
    QListWidget* processesList;
    QStringList* p ;

private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* btnsLayout;

    QGroupBox *processList;
    QGridLayout *lay;


    void guiInit();
    void draw();
    void addProcess();
    friend class GUIController;
};

#endif // PROCESSWIDGET_H

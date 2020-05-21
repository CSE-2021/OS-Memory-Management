#ifndef GUICONTOLLER_H
#define GUICONTOLLER_H

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QTableWidget>
#include <QLineEdit>
#include <QComboBox>
#include "../GUI/mainwindow.h"
#include "../GUI/holeswidget.h"
#include "../GUI/processwidget.h"
#include "memory_controller.h"
#include <qdebug.h>
class GUIContoller : public QObject
{
    Q_OBJECT
public:
    static void RegisterObject(MainWindow *m);
private:
    static MainWindow* main;
    static MemoryController* m;
    static void onNxtClicked();
    static void addHole();
    static void delHole();
//    static void onNxtProClicked();
//    static void onPrevProClicked();
    static void onAllocateNewClicked();
    static void onAllocateClicked();
    static void onDeallocateClicked();
    static void onResetClicked();
    static void onProClicked();
    static void addSeg();
    static void delSeg();
    static void onProNameChanged();
    static void updateProCount();
    static QString setBtnAllocate();
    static void onMemSizeChanged();



};

#endif // GUICONTOLLER_H

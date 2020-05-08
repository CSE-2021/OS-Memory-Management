#ifndef GUICONTOLLER_H
#define GUICONTOLLER_H

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QTableWidget>
#include <QComboBox>
#include "../GUI/mainwindow.h"
#include "../GUI/holeswidget.h"
#include "../GUI/processwidget.h"
class GUIContoller : public QObject
{
    Q_OBJECT
public:
    static void RegisterObject(MainWindow *m);
private:
    static MainWindow* main;
    static HolesWidget* w1;
    static void onNxtClicked();
    static void addHole();
    static void delHole();
    static void onNxtProClicked();
    static void addSeg();
    static void delSeg();


};

#endif // GUICONTOLLER_H

#ifndef GUICONTOLLER_H
#define GUICONTOLLER_H
#include <QObject>

<<<<<<< HEAD

class GUIContoller: public QObject
{
    Q_OBJECT

public:
    GUIContoller();


signals :
    void click();
public slots :
    void onclicked();
=======
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include "../GUI/mainwindow.h"
#include "../GUI/holeswidget.h"
#include "../GUI/processwidget.h"
class GUIContoller : public QObject
{
    Q_OBJECT
public:
    GUIContoller();
private:
    static MainWindow* main;
    static HolesWidget* w1;
private slots:
    void onNxtClicked();
>>>>>>> 7cb871d00a2c235535f323dcebf49423c41693f7

};

#endif // GUICONTOLLER_H

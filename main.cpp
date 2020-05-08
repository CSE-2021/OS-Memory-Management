#include "GUI/mainwindow.h"
#include "Controllers/guicontoller.h"
#include <QApplication>
#include <qfile.h>
#include "qtextstream.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile styleFile (":/style/stylesheet.css");
    styleFile.open(QIODevice::ReadOnly);
    QString style = styleFile.readAll();
    a.setStyleSheet(style);

    MainWindow w;
    GUIContoller::RegisterObject(&w);
    w.show();
    return a.exec();
}

#include "GUI/mainwindow.h"

#include <QApplication>
#include <qfile.h>
#include "qtextstream.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QFile styleFile(":/style/stylesheet.css");
//        if(styleFile.open(QIODevice::ReadOnly))
//        {
//            QTextStream textStream(&styleFile);
//            QString styleSheet = textStream.readAll();
//            styleFile.close();
//            a.setStyleSheet(styleSheet);
//        }
    QFile styleFile (":/style/stylesheet.css");
    styleFile.open(QIODevice::ReadOnly);
    QString style = styleFile.readAll();
    a.setStyleSheet(style);

    MainWindow w;
    w.show();
    return a.exec();
}

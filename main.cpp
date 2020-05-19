#include "GUI/mainwindow.h"
#include "Controllers/guicontoller.h"
#include <QApplication>
#include <qfile.h>
#include "qtextstream.h"

#include "Controllers/memory_controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QFile styleFile (":/style/stylesheet.css");
//    styleFile.open(QIODevice::ReadOnly);
//    QString style = styleFile.readAll();
//    a.setStyleSheet(style);

//    MainWindow w;
//    GUIContoller::RegisterObject(&w);
//    w.show();

    MemoryController memCont(50, AllocatorType::FIRST_FIT);
    memCont.deallocateSegment(0,5);
    memCont.deallocateSegment(10,20);
//    memCont.deallocateSegment(15,5);
//        for (deque<Segment *>::iterator i = memCont.getSegments()->begin(); i != memCont.getSegments()->end(); i++) {
//            qDebug() << "Name: " << (*i)->getName();
//            qDebug() << "Base: " << (*i)->getBase();
//            qDebug() << "Limit: " << (*i)->getLimit();
//        }
    QVector<QString> names = {"T1","T2"};
    QVector<unsigned long> limits = {5,5};
    qDebug() << memCont.allocateProcess("P1", names, limits);
    for (deque<Segment *>::iterator i = memCont.getSegments()->begin(); i != memCont.getSegments()->end(); i++) {
        qDebug() << "Name: " << (*i)->getName();
        qDebug() << "Base: " << (*i)->getBase();
        qDebug() << "Limit: " << (*i)->getLimit();
    }
    qDebug() << "***************** Deallocating ***********";
    memCont.deallocateProcess("P1");
    for (deque<Segment *>::iterator i = memCont.getSegments()->begin(); i != memCont.getSegments()->end(); i++) {
        qDebug() << "Name: " << (*i)->getName();
        qDebug() << "Base: " << (*i)->getBase();
        qDebug() << "Limit: " << (*i)->getLimit();
    }
    qDebug() << "Finished";

    return a.exec();
}

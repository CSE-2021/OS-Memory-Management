#include "GUI/mainwindow.h"
#include "Controllers/guicontoller.h"
#include <QApplication>
#include <qfile.h>
#include "qtextstream.h"
#include<QStyleFactory>

#include "Controllers/memory_controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("Fusion"));
    QFile styleFile (":/style/stylesheet.css");
    styleFile.open(QIODevice::ReadOnly);
    QString style = styleFile.readAll();
    a.setStyleSheet(style);

    MainWindow w;
    GUIContoller::RegisterObject(&w);
    w.show();

//    MemoryController memCont(50);
//    memCont.setAllocationType(AllocatorType::FIRST_FIT);
//    memCont.deallocateSegment(0,5);
//    memCont.deallocateSegment(20,5);
//    QVector<QString> names = {"T1","T2"};
//    QVector<unsigned long> limits = {10,5};
//    qDebug() << "Allocation : " <<  memCont.allocateProcess("P1", names, limits);
//    for (deque<Segment *>::iterator i = memCont.getSegments()->begin(); i != memCont.getSegments()->end(); i++) {
//        qDebug() << "Name: " << (*i)->getName();
//        qDebug() << "Base: " << (*i)->getBase();
//        qDebug() << "Limit: " << (*i)->getLimit();
//    }
//    memCont.deallocateSegment(25,5);
//    qDebug() << "Reallocation : " << memCont.reallocateProcess("P1");

//    qDebug() << "***************** reallocating ***********";
//    memCont.reallocateProcess("P1");
//    for (deque<Segment *>::iterator i = memCont.getSegments()->begin(); i != memCont.getSegments()->end(); i++) {
//        qDebug() << "Name: " << (*i)->getName();
//        qDebug() << "Base: " << (*i)->getBase();
//        qDebug() << "Limit: " << (*i)->getLimit();
//    }

//    qDebug() << "***************** deallocate ***********";
//    memCont.deallocateProcess("P1");
//    for (deque<Segment *>::iterator i = memCont.getSegments()->begin(); i != memCont.getSegments()->end(); i++) {
//        qDebug() << "Name: " << (*i)->getName();
//        qDebug() << "Base: " << (*i)->getBase();
//        qDebug() << "Limit: " << (*i)->getLimit();
//    }
//    qDebug() << "Finished";




    return a.exec();
}

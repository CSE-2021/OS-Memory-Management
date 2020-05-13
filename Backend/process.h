#ifndef PROCESS_H_
#define PROCESS_H_

#include <QString>
#include <QVector>
#include "segment.h"

class Process
{
private:
    QString name;
    bool isAllocated;
    QVector<Segment *> *segments = new QVector<Segment *>();
    // Static
    static unsigned long id;

public:
    Process(QString name);
    QVector<Segment *> *getSegments();
    void addSegment(Segment *segment);
    QString getName();
    void setName(QString name);
    bool getIsAllocated();
    void setIsAllocated(bool isAllocated);
    // Static
    static string generateProcessName();
};

#endif // PROCESS_H_

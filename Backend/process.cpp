#include "process.h"

unsigned long Process::id = 0;

Process::Process(QString name) : name{name}
{
}

QVector<Segment *> *Process::getSegments()
{
    return segments;
}

void Process::addSegment(Segment *segment)
{
    segments->push_back(segment);
}

QString Process::getName()
{
    return name;
}

void Process::setName(QString name)
{
    this->name = name;
}

bool Process::getIsAllocated()
{
    return isAllocated;
}

void Process::setIsAllocated(bool isAllocated)
{
    this->isAllocated = isAllocated;
}

string Process::generateProcessName()
{
    ++id;
    return "system" + Process::id;
}

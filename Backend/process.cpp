#include "process.h"

unsigned long Process::id = 0;

Process::Process(QString name)
{
}

QVector<Segment *> *Process::getSegments()
{
}

void Process::addSegment(Segment *segment)
{
}

QString Process::getName()
{
}

void Process::setName(QString name)
{
}

bool Process::getIsAllocated()
{
}

void Process::setIsAllocated(bool isAllocated)
{
}

string Process::generateProcessName()
{
}

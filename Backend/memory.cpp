#include "memory.h"



Memory::Memory(unsigned long size) : size{size}
{
    segments = new deque<Segment *>();
    processes = new QVector<Process *>();
    segmentToProcess = new map<Segment *, Process *>();
    segments->push_back(new Segment(QString("system"),0,size,SegmentType::ALLOCATED));
}

deque<Segment *> *Memory::getSegments()
{
    return segments;
}

QVector<Process *> *Memory::getProcesses()
{
    return processes;
}

unsigned long Memory::getSize()
{
    return size;
}

map<Segment *, Process *> *Memory::getSegmentToProcess()
{
    return segmentToProcess;
}

QString Memory::getProcessName(Segment *segment)
{
    return (*segmentToProcess)[segment]->getName();
}

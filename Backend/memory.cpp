#include "memory.h"



Memory::Memory(unsigned long size) : size{size}
{
    segments = new deque<Segment *>();
    processes = new QVector<Process *>();
    segmentToProcess = new map<Segment *, Process *>();
    Segment *segment = new Segment(QString("system"),0,size,SegmentType::ALLOCATED);
    Process *process = new Process(Process::generateProcessName());
    process->addSegment(segment);
    segments->push_back(segment);
    processes->append(process);
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

#ifndef FIRST_FIT_ALLOCATOR_H_
#define FIRST_FIT_ALLOCATOR_H_

#include "memory.h"
#include "allocator.h"
#include <QString>

class FirstFitAllocator : public Allocator
{
protected:
    virtual void allocateSegment(QString name, unsigned long limit);

public:
    FirstFitAllocator(Memory *memory);
    bool allocateProcess(QString processName, QVector<QString> *segmentsNames, QVector<unsigned long> *limits);
    virtual bool reallocateProcess(Process *process);
};

#endif // FIRST_FIT_ALLOCATOR_H_

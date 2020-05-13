#ifndef BEST_FIT_ALLOCATOR_H_
#define BEST_FIT_ALLOCATOR_H_

#include "memory.h"
#include "allocator.h"
#include <QString>

class BestFitAllocator : public Allocator
{
protected:
    virtual void allocateSegment(QString name, unsigned long limit);

public:
    BestFitAllocator(Memory *memory);
    bool allocateProcess(QString processName, vector<QString> *segmentsNames, vector<unsigned long> *limits);
    virtual bool reallocateProcess(Process *process);
};

#endif // BEST_FIT_ALLOCATOR_H_

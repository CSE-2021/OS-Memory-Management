#ifndef BEST_FIT_ALLOCATOR_H_
#define BEST_FIT_ALLOCATOR_H_

#include "memory.h"
#include "allocator.h"
#include <QString>

class BestFitAllocator : public Allocator
{
protected:
    virtual void allocateSegment(string name, unsigned long limit);

public:
    BestFitAllocator(Memory *memory);
    bool allocateProcess(string processName, vector<string> *segmentsNames, vector<unsigned long> *limits);
    virtual bool reallocateProcess(Process *process);
};

#endif // BEST_FIT_ALLOCATOR_H_

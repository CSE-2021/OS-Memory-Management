#ifndef FIRST_FIT_ALLOCATOR_H_
#define FIRST_FIT_ALLOCATOR_H_

#include "memory.h"

class FirstFitAllocator
{
protected:
    virtual void allocateSegment(string name, unsigned long limit);

public:
    FirstFitAllocator(Memory *memory);
    bool allocateProcess(string processName, vector<string> *segmentsNames, vector<unsigned long> *limits);
    virtual bool reallocateProcess(Process *process);
};

#endif // FIRST_FIT_ALLOCATOR_H_
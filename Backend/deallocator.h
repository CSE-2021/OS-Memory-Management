#ifndef DEALLOCATOR_H_
#define DEALLOCATOR_H_

#include "memory.h"

class Deallocator
{
private:
    Memory *memory;

    void deallocateSegment(Segment *segmentPtr);

public:
    Deallocator(Memory *memory);
    void deallocateProcess(Process *processPtr);
    void deallocateSegment(long base, unsigned long limit);
};

#endif // DEALLOCATOR_H_
#ifndef ALLOCATOR_H_
#define ALLOCATOR_H_

#include "memory.h"

class Allocator
{
private:
    bool checkIfAvailable(vector<unsigned long> *limits);

protected:
    Memory *memory;
    virtual void allocateSegment(string name, unsigned long limit) = 0;

public:
    Allocator(Memory *memory);
    bool allocateProcess(string processName, vector<string> *segmentsNames, vector<unsigned long> *limits);
    virtual bool reallocateProcess(Process *process) = 0;
};

#endif // ALLOCATOR_H_
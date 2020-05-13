#include "first_fit_allocator.h"

FirstFitAllocator::FirstFitAllocator(Memory *memory):Allocator(memory)
{
}

bool FirstFitAllocator::allocateProcess(QString processName, vector<QString> *segmentsNames, vector<unsigned long> *limits)
{
}

void FirstFitAllocator::allocateSegment(QString name, unsigned long limit)
{
}

bool FirstFitAllocator::reallocateProcess(Process *process)
{
}

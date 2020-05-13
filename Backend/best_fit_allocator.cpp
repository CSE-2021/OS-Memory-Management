#include "best_fit_allocator.h"

BestFitAllocator::BestFitAllocator(Memory *memory):Allocator(memory)
{
}

bool BestFitAllocator::allocateProcess(QString processName, vector<QString> *segmentsNames, vector<unsigned long> *limits)
{
}

void BestFitAllocator::allocateSegment(QString name, unsigned long limit)
{
}

bool BestFitAllocator::reallocateProcess(Process *process)
{
}

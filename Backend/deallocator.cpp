#include "deallocator.h"

Deallocator::Deallocator(Memory *memory)
{
	this->memory = memory;
}

void Deallocator::deallocateProcess(Process *processPtr)
{
	// step 1: converting type of segments to Free and base to -1

	for (int i = 0; i < (*(processPtr->getsegments())).size(); i++)

	{
		((*(processPtr->getSegments()))[i])->setBase(-1);

		((*(processPtr->getSegments()))[i])->setSegmentType(FREE);
	}
	// step 2: making isallocated value =0 for process

	processPtr->setIsAllocated(true);
}

void Deallocator::deallocateSegment(long base, unsigned long limit)
{
}

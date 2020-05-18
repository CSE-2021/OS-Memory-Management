#include "deallocator.h"

Deallocator::Deallocator(Memory *memory)
{
	this->memory = memory;
}

void Deallocator::deallocateProcess(Process *processPtr)
{
	// step 1: converting type of segments to Free 

	for (int i = 0; i < (*(processPtr->getsegments())).size(); i++)

	{
		
		((*(processPtr->getSegments()))[i])->setSegmentType(FREE);
		
		deallocateSegment(((*(processPtr->getSegments()))[i])->getBase(),
							((*(processPtr->getSegments()))[i])->getLimit());
		
		
	}
	// step 2: making isallocated value =0 for process

	processPtr->setIsAllocated(true);
}

void Deallocator::deallocateSegment(long base, unsigned long limit)
{
	deque <segments *> *d= memory->getSegments();
	//searching for targeted segment
	int i ;
	for (i=0; i < d->size() ; i++)
	{
			if( (base == (*d)[i]->getBase() ) && (limit == (*d)[i]->getLimit() ) )
			{	(*d)[i]->setSegmentType(FREE);
					break;}
				 
	}
	
	if ((i!=0) &&( (*d)[i-1]->getSegmentType()==FREE ) )
	   merge_holes ((*d)[i-1],(*d)[i],i-1);
	   
	if ((i!=(d->size()-1)) &&( (*d)[i+1]->getSegmentType()==FREE ) )
	   merge_holes ((*d)[i],(*d)[i+1]);
}


void Deallocator::merge_holes(Segment *f ,Segment *s )
{
	long base = f->getBase();
	unsigned long limit =f->getLimit()+s->getLimit();
	f->setBase(-1);
	s->setBase(-1);
	Segment *temp =f;
	f = new Segment("dummy",base,limit,FREE);
	((memory->getSegments())->erase(s);
	
	if (temp->getName()=="dummy") delete [] temp ;
	if (s->getName()=="dummy") delete [] s ;
	
}










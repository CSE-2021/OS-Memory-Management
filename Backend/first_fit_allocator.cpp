#include "first_fit_allocator.h"

FirstFitAllocator::FirstFitAllocator(Memory *memory):Allocator(memory)
{
}

bool FirstFitAllocator::allocateProcess(QString processName, QVector<QString> *segmentsNames, QVector<unsigned long> *limits)
{
	//check if limit vector has same no of elements as segment names vector and not empty

	if ( (segmentsNames->size() != limits->size() ) || (limits->size()==0 )  )
          return false;
      
          
    else{
		
			Qvector <int> holes ;
			Qvector <int> hole_base ;
			holes.pushback(0);
		
		// making avector of holes (size and index) pf current memory 
		for (int i=0; i< memory->getSize() ;i++ ) 
		{
					//derefrencing pointer to deque of memory segments then getting the i's element
					//   segment type to identify possible holes
			if  ( (*(memory->getSegments()))[i].getSegmentType() == FREE ) 
			
			{
			 (*holes.end())++ ;//increment hole space
			 // save the index that marks the base of hole
			 if (*holes.end()==1) hole_base.pushback(i); 
			}
			
			 //if memory segment not free (end of ahole ) , add anew element for next hole
			else if (*holes.end()!=0)holes.pushback(0);
			
		}
			
		/////////	
		
		// checking if all segments can fit in holes (first fit)	
		for (int i=0; i< limits->size() ;i++ )
		{
				
				
		}
			
				
		
		
		
		
				
		}
	
}





void FirstFitAllocator::allocateSegment(QString name, unsigned long limit)
{
}

bool FirstFitAllocator::reallocateProcess(Process *process)
{
}

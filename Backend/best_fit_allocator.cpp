#include "best_fit_allocator.h"

BestFitAllocator::BestFitAllocator(Memory *memory):Allocator(memory)
{
}

void merge (const Qvector<int> &holes,const Qvector<int> &hole_base, Qvector<pair<int,int>> & merged )
{
for(int i=0; i<hole_base.size(); i++)
    
        merged.pushback(make_pair(holes[i], hole_base[i]));

}	 


void seperate (const Qvector<int> &holes,const Qvector<int> &hole_base, Qvector<pair<int,int>> & merged )
{
for(int i=0; i<hole_base.size(); i++)
    {
      holes[i]=merged[i].first;
      hole_base[i]=merged[i].second;
	}
}
/*
bool sortinrev(const pair<int,int> &a, const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
} 
*/

bool BestFitAllocator::allocateProcess(QString processName, QVector<QString> *segmentsNames,
										QVector<unsigned long> *limits ,bool reallocate=false , Process * ptr = NULL )
{
	//check if limit vector has same no of elements as segment names vector and not empty

	if ( (segmentsNames->size() != limits->size() ) || (limits->size()==0 )  )
          return false;
      
          
    else{
		////	segment and process creation ///////////////////////////////////////
		
		if (!reallocate) // if this function wasnt called from reallocate function	
		{	Process * p = new Process (processName);
			
			for (int i=0; i< segmentsNames->size() ; i++ )
			{
				//default values for base and type 
				Segment * s = new Segment ( (*segmentsNames)[i],-1, (*limits) [i],FREE);
				//adding segment to process
				p->addSegment(s);
			
			}
		}
		
		else { // if this function was called by reallocate function
			
			Process * p = &ptr;
			
			}
			
			
		///////////////////////////////////////////////////////////////////////////	
			Qvector<pair<int,int>> merged;
			Qvector <long> seg_base;
			Qvector <int> holes ;
			Qvector <int> hole_base ;
			holes.pushback(0);
		
		// making avector of holes (size and index) pf current memory 
		for (int i=0; i< memory->getSize() ;i++ ) 
		{
					//derefrencing pointer to deque of memory segments then getting the i's element
					//segment type (free/allocated) to identify possible holes
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
		
		int seg_vect_size=-1;
		
		// checking if all segments can fit in holes (first fit)	
		// and adding their base to seg_base vector
		for (int li=0; i< limits->size() ;li++ ) // limit index
		{
			
			
			//// merging the base and size vectors to sort both descendingly according to size
			// needs to be sorted for every segment again :(
			merge (holes,hole_base, merged );
			sort (merged.begin() ,merged.end() );
			seperate (holes,hole_base, merged );
			
			///////////////////////////////////////////////////////
			
			if (!seg_base.empty()) seg_vect_size = seg_base.size(); // update var with initial size of vector
			
			for	(int hi=0; i< holes.size() ;hi++ ) //holes index
			{
				if ( (*limits)[li] <= holes[hi] ) { // if li's segment fits into hi's hole ..
											holes[hi]-=(*limits)[li]; //resize hole
											hole_base[hi]+=(*limits)[li]; //update the hole base 
											
									//add the hole base to vector of 'possible' future segment base vector
									// 'possible ' means if all segments of process fitted into holes  
											seg_base.pushback((long)hole_base[hi]);
											break ; //already found
											}
				
				
			}
			//if seg_base vect size doesnt increase
			//it means no hole was found for any segment 
			if ( seg_vect_size == seg_base.size() ) 
							//			return false ; // kill -_-
							// new part //////
						
						// set all bases of segments to -1 (done) (default)
						// set all segments type to free (done) (default)
						// set isallocated process to false
						
						{
							p->setIsAllocated(false);
							return false;
						}		
		}
			
		//if the prog reaches this point it means that process is eligible for allocation 		
		
		// step 1 : updating segment base (using seg_base vector )  and segment type
		
		for (int i=0; i< seg_base.size() ;i++)
		{
		
		((*(p->getSegments()))[i])->setBase(seg_base[i]);
		
		((*(p->getSegments()))[i])->setSegmentType(ALLOCATED);		
		
		
		}
		
		//step 2 : updating process status to allocated process
		p->setIsAllocated(true);
		
		//finally !!!
		
		return true;
		
}


}


/*
void BestFitAllocator::allocateSegment(QString name, unsigned long limit)
{
}
*/


bool BestFitAllocator::reallocateProcess(Process *process)
{
	Qvector segmentsNames;
	for(auto &var : *(process->getSegments()))
		segmentsNames.push_back(var.getName());
		
		
		Qvector limits;
	for(auto &var : *(process->getSegments()))
		segmentsNames.push_back(var.getLimit());
	
	return allocateProcess(process->getName(), &segmentsNames,
					&limits ,true ,&process);



}


















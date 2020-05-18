#include "first_fit_allocator.h"

FirstFitAllocator::FirstFitAllocator(Memory *memory) : Allocator(memory)
{
}




Process * FirstFitAllocator:: createProcess (QString processName, QVector<QString> *segmentsNames,
                                        QVector<unsigned long> *limits, bool reallocate, Process *ptr)
{
	//check if limit vector has same no of elements as segment names vector and not empty

	if ((segmentsNames->size() != limits->size()) || (limits->size() == 0))
		return NULL;

	else
	{
		////	segment and process creation ///////////////////////////////////////

			Process *p;

		if (!reallocate) // if this function wasnt called from reallocate function
		{
			p = new Process(processName);

			for (int i = 0; i < segmentsNames->size(); i++)
			{
				//default values for base and type
				Segment *s = new Segment((*segmentsNames)[i], -1, (*limits)[i], FREE);
				//adding segment to process
				p->addSegment(s);
			}
		}

		else
		{ // if this function was called by reallocate function

			p = ptr;
		}

	
	return p ;
	
}
}



bool FirstFitAllocator::check_if_allocation_possible (Process * p , int seg_no , QVector<int> &holes
                                ,QVector < QPair<int ,Segment * >> &seg)
{
    int fitted_seg_no = 0 ,old_no=0;
		for (int li = 0; li < seg_no ; li++) // limit index
		{
			unsigned long limit = (*(p->getSegments()))[li]->getLimit() ;
			old_no= fitted_seg_no;

			for (int hi = 0; i < holes.size(); hi++) //holes index
			{
				if ((int)(limit ) <=holes[hi])
				{									// if li's segment fits into hi's hole ..
					holes[hi] -= (int) limit;		//resize hole
                    seg.push_back(qMakePair(hi,(*(p->getSegments()))[li] ) );
					
					
					fitted_seg_no++;
					break; //already found
				}
				
			}
		// if no of fitted segments vent increased (segment cant be placed in memory)
				if (old_no == fitted_seg_no) return false; 
		
		}
	return true;
}


void FirstFitAllocator:: extract_memory_holes (QVector<int> &holes , QVector<int> &hole_base)
{
	
		// making avector of holes (size and index) pf current memory
		for (int i = 0;i< (*(memory->getSegments())).size(); i++)
		{
			//derefrencing pointer to deque of memory segments then getting the i's element
			//segment type (free/allocated) to identify possible holes
			if ((*(memory->getSegments()))[i].getSegmentType() == FREE)
			{
				(holes[holes.size()-1])+=((*(memory->getSegments()))[i].getLimit(); //adding the size of hole to holes vect 
				// save the index that marks the base of hole
					hole_base.push_back(i);
			}

			//if memory segment not free  , add anew element for next hole
			else if (holes[holes.size()-1] != 0)
				holes.push_back(0);
		}

		
		/////////


}





bool FirstFitAllocator::allocateProcess(QString processName, QVector<QString> *segmentsNames,
                                        QVector<unsigned long> *limits, bool reallocate , Process *ptr)
{
			// create new process on heap with default values base=-1 
			// isallocated =0  , segmentType = FREE
			
		Process * p = createProcess(processName , segmentsNames ,limits,reallocate,ptr);
		
		if (p==NULL) return false; // problem with given parameters
		
		//adding process to vect of processes in memory 
		(memory->getProcesses())->push_back(p);
		//number of segments in given process
		int no_of_seg = limits->size();
		///////////////////////////////////////////////////////////////////////////
		
        QVector<int> holes; // sizes of free segments vect
        QVector<int> hole_base; // index of free segments vect
        QVector < QPair<int ,Segment * > > seg ;
		holes.push_back(0);
			
		//////////////////////////////////////////////////////////////
		// fill the free sigments' sizes and index vectors
		extract_memory_holes(holes,hole_base);
		/////////////////
		//checking if allocation of the process is possible using first fit
		if(hole_base.empty()) return false; // checking if no holes available
		
		//if allocation not possible terminate function
		if ( ! check_if_allocation_possible (p , no_of_seg , holes ,seg) ) return false;
		
		//sort(seg.begin(),seg.end());
		///////////////
		//allocating..
		
		deque<Segment *> * d =memory->getSegments();
		deque<Segment *>::iterator it = d->begin();
		
		for (int i=hole_base.size()-1; i>=0 ; i--)
		{
			it=d->begin()+hole_base[i] ;
		
            QStack <Segment* > stk;
			for (int s = seg.size()-1 ;s>=0; s--)
			{
				if (seg[s].first==i) stk.push(seg[s].second);
			
			}
			
			long base =hole_base[i];
			Segment *ss =stk.pop();
			ss->setBase(base);
			ss->setSegmentType(ALLOCATED);
			*d[hole_base[i]] = ss;
			
			while (!stk.empty())
			{
					base+= ss->getLimit();
					it++;
					ss =stk.pop();
					ss->setBase(base);
					ss->setSegmentType(ALLOCATED);
					d->insert(it,ss);
			}
		
			base+= ss->getLimit();
			if (holes[i]>0) 
			{
				Segment * dummy = new Segment (dummy,base,(unsigned long)holes[i],FREE) ;
				d->insert(it,dummy);
			}
		
		
		
		}
		
		p->setIsAllocated(true);	
		return true;
	}












	/*
void FirstFitAllocator::allocateSegment(QString name, unsigned long limit)
{
}
*/

	bool FirstFitAllocator::reallocateProcess(Process * process)
	{

        QVector <QString> segmentsNames;//CHANGED
		for (auto &var : *(process->getSegments()))
			segmentsNames.push_back(var.getName());

        QVector<unsigned long> limits;
		for (auto &var : *(process->getSegments()))
            limits.push_back(var.getLimit());//CHANGED

		return allocateProcess(process->getName(), &segmentsNames,
							   &limits, true, &process);
	}

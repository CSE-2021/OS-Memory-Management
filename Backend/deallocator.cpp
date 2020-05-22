#include "deallocator.h"
#include <algorithm>

using std::find;

Deallocator::Deallocator(Memory *memory)
{
	this->memory = memory;
}

void Deallocator::deallocateProcess(Process *processPtr)
{
	// step 1: converting type of segments to Free 

    for (int i = 0; i < (*(processPtr->getSegments())).size(); i++)

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
    deque < Segment *> *d= memory->getSegments();
	//searching for targeted segment
    //int i ;
    deque<Segment *>::iterator holePlace;
    for (deque<Segment *>::iterator i = d->begin(); i != d->end() ; i++)	{
        unsigned long startLoc = (*i)->getBase();
        unsigned long finishLoc = startLoc + (*i)->getLimit();
        if(base+limit <= finishLoc && base >= startLoc){
            Segment *s1 = nullptr;
            Segment *s2 = new Segment("HOLE", base, limit, SegmentType::FREE);
            Segment *s3 = nullptr;
            int indexOfProcessToBeRemoved = memory->getProcesses()->indexOf((*(memory->getSegmentToProcess()))[*i]);
            delete (*i);
            deque<Segment *>::iterator currentPlace = d->erase(i);
            delete ((*(memory->getProcesses()))[indexOfProcessToBeRemoved]);
            memory->getProcesses()->remove(indexOfProcessToBeRemoved);
            if (base != startLoc) {
                s1 = new Segment("system", startLoc, base - startLoc, SegmentType::ALLOCATED);
                Process *process = new Process(Process::generateProcessName());
                process->addSegment(s1);
                memory->getProcesses()->append(process);
            }
            if (base+limit != finishLoc) {
                s3 = new Segment("system", base+limit, finishLoc - base - limit, SegmentType::ALLOCATED);
                Process *process = new Process(Process::generateProcessName());
                process->addSegment(s3);
                memory->getProcesses()->append(process);
            }
            if (s1 != nullptr) {
                currentPlace = d->insert(currentPlace, s1) + 1;
            }
            currentPlace = d->insert(currentPlace, s2) + 1;
            holePlace = currentPlace - 1;
            if (s3 != nullptr) {
                currentPlace = d->insert(currentPlace, s3) + 1;
            }
            break;
        }
    }
//    if (holePlace == d->begin()) {
        
//    } else if (holePlace + 1 == d->end()) {
        
//    } else {
        
//    }
    if (holePlace != d->begin()) {
        if ((*(holePlace - 1))->getSegmentType() == SegmentType::FREE) {
            merge_holes((*(holePlace - 1)), *holePlace);
        }
    }
    if (holePlace + 1 != d->end()) {
        if ((*(holePlace + 1))->getSegmentType() == SegmentType::FREE) {
            merge_holes(*holePlace, (*(holePlace + 1)));
        }
    }
//	int i;
//	if ((i!=0) &&( (*d)[i-1]->getSegmentType()==FREE ) )
//       merge_holes ((*d)[i-1],(*d)[i]);
	   
//    if ((i!=(int)(d->size()-1)) &&( (*d)[i+1]->getSegmentType()==FREE ) )
//	   merge_holes ((*d)[i],(*d)[i+1]);
}


void Deallocator::merge_holes(Segment *f ,Segment *s )
{
//	long base = f->getBase();
    unsigned long limit =f->getLimit()+s->getLimit();
    f->setLimit(limit);
    delete s;
    memory->getSegments()->erase(find(memory->getSegments()->begin(), memory->getSegments()->end(), s));
	
//	if (temp->getName()=="dummy") delete temp ;
//	if (s->getName()=="dummy") delete s ;
	
}










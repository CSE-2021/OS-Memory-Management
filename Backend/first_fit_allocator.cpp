#include "first_fit_allocator.h"
#include <QStack>

FirstFitAllocator::FirstFitAllocator(Memory *memory) : Allocator(memory){}

Process *FirstFitAllocator::createProcess(QString processName, QVector<QString> *segmentsNames,
                                          QVector<unsigned long> *limits, bool reallocate, Process *ptr){

    //check if limit vector has same no of elements as segment names vector and not empty
    if ((segmentsNames->size() != limits->size()) || (limits->size() == 0)) return nullptr;
    else{
		////	segment and process creation ///////////////////////////////////////

        Process *p;
        // if this function wasnt called from reallocate function
        if (!reallocate){
			p = new Process(processName);
            for (int i = 0; i < segmentsNames->size(); i++){
				//default values for base and type
                Segment *s = new Segment((*segmentsNames)[i], -1, (*limits)[i], ALLOCATED);
				//adding segment to process
				p->addSegment(s);
            }
            (memory->getProcesses())->push_back(p);
        }else{
            // if this function was called by reallocate function
			p = ptr;
		}	
        return p ;
    }
}



bool FirstFitAllocator::check_if_allocation_possible(Process * p , int seg_no , QVector<int> &holes
                                ,QVector< QPair<int ,Segment * >> &seg){
		for (int li = 0; li < seg_no ; li++) // limit index
		{
			unsigned long limit = (*(p->getSegments()))[li]->getLimit() ;
            bool flag = false;

            for (int hi = 0; hi < holes.size(); hi++) //holes index
			{
				if ((int)(limit ) <=holes[hi])
				{									// if li's segment fits into hi's hole ..
					holes[hi] -= (int) limit;		//resize hole
                    seg.push_back(qMakePair(hi,(*(p->getSegments()))[li] ) );
					
					
                    flag = true;
					break; //already found
				}
				
			}
		// if no of fitted segments vent increased (segment cant be placed in memory)
                if (!flag) return false;
		
		}
	return true;
}


void FirstFitAllocator:: extract_memory_holes (QVector<int> &holes , QVector<int> &hole_base){
    // making avector of holes (size and index) pf current memory
    for (int i = 0;i< (int)memory->getSegments()->size(); i++)		{
        //derefrencing pointer to deque of memory segments then getting the i's element
        //segment type (free/allocated) to identify possible holes
        if ((*(memory->getSegments()))[i]->getSegmentType() == FREE){
            holes.append((*(memory->getSegments()))[i]->getLimit()); //adding the size of hole to holes vect
            hole_base.push_back(i);
        }
    }
}
#include <QDebug>
bool FirstFitAllocator::allocateProcess(QString processName, QVector<QString> *segmentsNames,
                                        QVector<unsigned long> *limits, bool reallocate , Process *ptr){
    // create new process on heap with default values base=-1
    // isallocated =0  , segmentType = FREE

    Process * p = createProcess(processName , segmentsNames ,limits,reallocate,ptr);
    if (p==nullptr) return false; // problem with given parameters
    //number of segments in given process
    int no_of_seg = limits->size();
    ///////////////////////////////////////////////////////////////////////////

    QVector<int> holes; // sizes of free segments vect
    QVector<int> hole_base; // index of free segments vect
    QVector < QPair<int ,Segment * > > seg ;


    //////////////////////////////////////////////////////////////
    // fill the free sigments' sizes and index vectors
    extract_memory_holes(holes,hole_base);
    qDebug() << "Holes:" << holes;
    qDebug() << "Segment No. :" << hole_base;

    /////////////////
    //checking if allocation of the process is possible using first fit
    if(hole_base.empty()) return false; // checking if no holes available

    //if allocation not possible terminate function
    if (!check_if_allocation_possible (p , no_of_seg , holes ,seg)) return false;
    for(QPair<int ,Segment*> p : seg){
        qDebug() << "Pair" << p.first << p.second->getName();
    }
    //allocating..
    deque<Segment *> * d =memory->getSegments();
    for(QPair<int ,Segment*> p : seg){
        for (deque<Segment *>::iterator i = d->begin(); i != d->end(); i++) {
            if ((*i)->getLimit() >= p.second->getLimit() && (*i)->getSegmentType() == SegmentType::FREE) {
                p.second->setBase((*i)->getBase());
                qDebug() << p.second->getBase();
                (*i)->setBase((*i)->getBase() + p.second->getLimit());
                qDebug() << (*i)->getBase();
                (*i)->setLimit((*i)->getLimit() - p.second->getLimit());
                qDebug() << (*i)->getLimit();
                i = d->insert(i, p.second) + 1;
                qDebug() << (*i)->getLimit();
                if ((*i)->getLimit() == 0) d->erase(i);
                break;
            }
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
            segmentsNames.push_back(var->getName());

        QVector<unsigned long> limits;
		for (auto &var : *(process->getSegments()))
            limits.push_back(var->getLimit());//CHANGED

		return allocateProcess(process->getName(), &segmentsNames,
                               &limits, true, process);
	}

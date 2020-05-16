#ifndef BEST_FIT_ALLOCATOR_H_
#define BEST_FIT_ALLOCATOR_H_

#include "memory.h"
#include "allocator.h"
#include <QString>

class BestFitAllocator : public Allocator
{
	
private:	
   //  void allocateSegment(QString name, unsigned long limit);
	  
	  void merge (const Qvector<int> &holes,const Qvector<int> &hole_base, Qvector<pair<int,int>> & merged );
	  void seperate (const Qvector<int> &holes,const Qvector<int> &hole_base, Qvector<pair<int,int>> & merged );
	//  bool sortinrev(const pair<int,int> &a, const pair<int,int> &b) ;
	  
public:
    BestFitAllocator(Memory *memory);
    virtual bool allocateProcess(QString processName, QVector<QString> *segmentsNames, QVector<unsigned long> *limits);
    virtual bool reallocateProcess(Process *process);
};

#endif // BEST_FIT_ALLOCATOR_H_

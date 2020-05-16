#ifndef BEST_FIT_ALLOCATOR_H_
#define BEST_FIT_ALLOCATOR_H_

#include "memory.h"
#include "allocator.h"
#include <QString>

class BestFitAllocator : public Allocator
{
	/*
private:
     void allocateSegment(QString name, unsigned long limit);
*/
public:
    BestFitAllocator(Memory *memory);
    virtual bool allocateProcess(QString processName, QVector<QString> *segmentsNames, QVector<unsigned long> *limits);
    virtual bool reallocateProcess(Process *process);
};

#endif // BEST_FIT_ALLOCATOR_H_

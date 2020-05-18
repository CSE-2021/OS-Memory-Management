#ifndef FIRST_FIT_ALLOCATOR_H_
#define FIRST_FIT_ALLOCATOR_H_

#include "memory.h"
#include "allocator.h"
#include <QString>
#include <QVector>
#include "segment.h"
class FirstFitAllocator : public Allocator
{
	/*
private:
    void allocateSegment(QString name, unsigned long limit);
*/
public:
    FirstFitAllocator(Memory *memory);
    Process *createProcess (QString processName, QVector<QString> *segmentsNames,
                                            QVector<unsigned long> *limits, bool reallocate = false, Process *ptr = NULL);
    virtual bool allocateProcess(QString processName, QVector<QString> *segmentsNames,
						QVector<unsigned long> *limits,bool reallocate=false , Process * ptr = NULL);
    virtual bool reallocateProcess(Process *process);
    void extract_memory_holes (QVector<int> &holes , QVector<int> &hole_base);
    bool check_if_allocation_possible (Process * p , int seg_no , QVector<int> &holes
                                    ,QVector < QPair<int ,Segment * >> &seg);
};

#endif // FIRST_FIT_ALLOCATOR_H_

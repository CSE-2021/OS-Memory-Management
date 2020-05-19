#ifndef BEST_FIT_ALLOCATOR_H_
#define BEST_FIT_ALLOCATOR_H_

#include "memory.h"
#include "allocator.h"
#include <QString>
#include <QVector>
#include <QStack>

class BestFitAllocator : public Allocator
{
	
private:	
			

   //  void allocateSegment(QString name, unsigned long limit);
      void merge ( QVector<int> &holes, QVector<int> &hole_base, QVector<QPair<int,int>> & merged ); //const
      void seperate ( QVector<int> &holes, QVector<int> &hole_base, QVector<QPair<int,int>> & merged );//const
	//  bool sortinrev(const pair<int,int> &a, const pair<int,int> &b) ;
	  
public:
    BestFitAllocator(Memory *memory);
    virtual bool allocateProcess(QString processName, QVector<QString> *segmentsNames, 
						QVector<unsigned long> *limits,bool reallocate=false , Process * ptr = NULL);
    virtual bool reallocateProcess(Process *process);
    Process * createProcess (QString processName, QVector<QString> *segmentsNames,
                                            QVector<unsigned long> *limits, bool reallocate = false, Process *ptr = NULL);
    bool check_if_allocation_possible (Process * p , int seg_no , QVector<int> &holes
                                    , QVector<int> &hole_base,QVector<QPair<int,int>> merged,QVector < QPair<int ,Segment * >> &seg);
    void extract_memory_holes (QVector<int> &holes , QVector<int> &hole_base);
};

#endif // BEST_FIT_ALLOCATOR_H_

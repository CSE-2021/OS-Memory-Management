#ifndef MEMORY_CONTROLLER_H_
#define MEMORY_CONTROLLER_H_

#include "../Backend/memory.h"
#include "../Backend/segment.h"
#include "../Backend/allocator.h"
#include "../Backend/first_fit_allocator.h"
#include "../Backend/best_fit_allocator.h"
#include "../Backend/deallocator.h"
#include <QString>
#include <QMap>

using std::deque;

typedef enum AllocatorType{FIRST_FIT, BEST_FIT}AllocatorType;

class MemoryController{
public:
    MemoryController(unsigned long size, AllocatorType type);
    bool allocateProcess(QString name, QVector<QString> &segmentsNames, QVector<unsigned long> &segmentsLimits);
    void deallocateSegment(unsigned long base, unsigned long limit);
    void deallocateProcess(QString name);
    deque<Segment*>* getSegments();
    QVector<Process*>* getProcesses();

private:
    Memory *mem;
    Allocator *allecator;
    Deallocator *deallecator;
    QMap <QString, Process*> processMap;
};

#endif // MEMORY_CONTROLLER_H_

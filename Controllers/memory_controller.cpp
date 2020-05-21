#include "memory_controller.h"

MemoryController::MemoryController(unsigned long size){
    mem = new Memory(size);
    deallecator = new Deallocator(mem);

}

void MemoryController::setAllocationType(AllocatorType t){
    if(t == FIRST_FIT) allecator = new FirstFitAllocator(mem);
    else allecator = new BestFitAllocator(mem);
}


bool MemoryController::allocateProcess(QString name, QVector<QString> &segmentsNames, QVector<unsigned long> &segmentsLimits){
    return allecator->allocateProcess(name, &segmentsNames, &segmentsLimits);
}

void MemoryController::deallocateSegment(unsigned long base, unsigned long limit){
    deallecator->deallocateSegment(base, limit);
}

void MemoryController::deallocateProcess(QString name){
    for (Process *p : *(mem->getProcesses())){
        if(!p->getName().compare(name)){
            deallecator->deallocateProcess(p);
            break;
        }
    }
}

bool MemoryController::reallocateProcess(QString name){
    for (Process *p : *(mem->getProcesses())){
        if(!p->getName().compare(name)){
            return allecator->reallocateProcess(p);
            break;
        }
    }
    return false;
}


deque<Segment*>* MemoryController::getSegments(){
    return mem->getSegments();
}

QVector<Process*>* MemoryController::getProcesses(){
    return mem->getProcesses();
}

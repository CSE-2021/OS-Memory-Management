#include "memory_controller.h"

MemoryController::MemoryController(unsigned long size, AllocatorType type){
    mem = new Memory(size);
    deallecator = new Deallocator(mem);
    if(type == FIRST_FIT) allecator = new FirstFitAllocator(mem);
    else allecator = new BestFitAllocator(mem);
}


bool MemoryController::allocateProcess(QString name, QVector<QString> &segmentsNames, QVector<unsigned long> &segmentsLimits){
    bool out = allecator->allocateProcess(name, &segmentsNames, &segmentsLimits);
}

void MemoryController::deallocateSegment(unsigned long base, unsigned long limit){

}

void MemoryController::deallocateProcess(QString name){
//    deallecator->deallocateProcess()
}

deque<Segment*>* MemoryController::getSegments(){
    return mem->getSegments();
}

QVector<Process*>* MemoryController::getProcesses(){
    return mem->getProcesses();
}

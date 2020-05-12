#ifndef MEMORY_H_
#define MEMORY_H_

#include <deque>
#include <map>
#include <vector>
#include <string>
#include "segment.h"
#include "process.h"

using std::deque;
using std::map;
using std::string;
using std::vector;

class Memory
{
private:
    unsigned long size;
    deque<Segment *> *segments = new deque<Segment *>();
    vector<Process *> *processes = new vector<Process *>();
    map<Segment *, Process *> *segmentToProcess = new map<Segment *, Process *>();

public:
    Memory(unsigned long size);
    deque<Segment *> *getSegments();
    vector<Process *> *getProcesses();
    unsigned long getSize();
    map<Segment *, Process *> *getSegmentToProcess();
    string getProcessName(Segment *segmentPtr);
};

#endif // MEMORY_H_
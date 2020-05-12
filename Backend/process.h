#ifndef PROCESS_H_
#define PROCESS_H_

#include <string>
#include <vector>
#include "segment.h"

using std::string;
using std::vector;

class Process
{
private:
    string name;
    bool isAllocated;
    vector<Segment *> *segments = new vector<Segment *>();
    // Static
    static unsigned long id;

public:
    Process(string name);
    vector<Segment *> *getSegments();
    void addSegment(Segment *segment);
    string getName();
    void setName(string name);
    bool getIsAllocated();
    void setIsAllocated(bool isAllocated);
    // Static
    static string generateProcessName();
};

#endif // PROCESS_H_
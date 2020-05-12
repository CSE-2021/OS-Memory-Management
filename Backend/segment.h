#ifndef SEGMENT_H_
#define SEGMENT_H_

#include <string>

using std::string;

enum SegmentType
{
    FREE,
    ALLOCATED
};

class Segment
{
private:
    string name;
    long base;
    unsigned long limit;
    SegmentType segmentType;

public:
    Segment(string name, long base, unsigned long limit, SegmentType segmentType);
    string getName();
    void setName(string name);
    long getBase();
    void setBase(long base);
    unsigned long getLimit();
    void setLimit(unsigned long limit);
    SegmentType getSegmentType();
    void setSegmentType(SegmentType segmentType);
    // Static
    static const string defaultSegmentName;
};

#endif // SEGMENT_H_
#ifndef SEGMENT_H_
#define SEGMENT_H_

#include <QString>

using std::string;

enum SegmentType{FREE, ALLOCATED};

class Segment{
private:
    QString name;
    long base;
    unsigned long limit;
    SegmentType segmentType;

public:
    Segment(QString name, long base, unsigned long limit, SegmentType segmentType);
    QString getName();
    void setName(QString name);
    long getBase();
    void setBase(long base);
    unsigned long getLimit();
    void setLimit(unsigned long limit);
    SegmentType getSegmentType();
    void setSegmentType(SegmentType segmentType);
    // Static
    static const QString defaultSegmentName;
};

#endif // SEGMENT_H_

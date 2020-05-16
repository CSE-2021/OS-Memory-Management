#include "segment.h"

const QString Segment::defaultSegmentName = "system";

Segment::Segment(QString name, long base, unsigned long limit, SegmentType segmentType) : name{name}, base{base}, limit{limit}, segmentType{segmentType}
{
}

QString Segment::getName()
{
    return name;
}

void Segment::setName(QString name)
{
    this->name = name;
}

long Segment::getBase()
{
    return base;
}

void Segment::setBase(long base)
{
    this->base = base;
}

unsigned long Segment::getLimit()
{
    return limit;
}

void Segment::setLimit(unsigned long limit)
{
    this->limit = limit;
}

SegmentType Segment::getSegmentType()
{
    return segmentType;
}

void Segment::setSegmentType(SegmentType segmentType)
{
    this->segmentType = segmentType;
}

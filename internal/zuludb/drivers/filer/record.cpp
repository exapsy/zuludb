#include "./record.hpp"

#include <cstring>

Record::Record () {}
Record::Record (ZL_RecordStruct record)
{
    id_ = record.id;
    data_ = record.data;
}

Record::~Record () {}

char*
    Record::getData ()
{
    return data_;
}

uint32_t
    Record::getID ()
{
    return id_;
}

uint32_t
    Record::getIndex ()
{
    return index_;
}

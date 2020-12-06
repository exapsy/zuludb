#include <iostream>
#ifndef DATABASE_H
#define DATABASE_H

class Database;

typedef struct RecordStruct {
    uint32_t id;
    char* data;
} ZL_RecordStruct;

/*
 * Record stores a table's record data
 */
class Record {
   public:
    Record ();
    ~Record ();
    Record (ZL_RecordStruct);
    uint32_t getID ();
    uint32_t getIndex ();
    uint32_t setIndex ();
    char* getData ();

   private:
    uint32_t id_;
    uint32_t index_;
    char* data_;
};

#endif


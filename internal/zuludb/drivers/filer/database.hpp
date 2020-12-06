#include <fstream>
#include <iostream>
#include <string>

#include "./record.hpp"

typedef struct ZL_DatabaseIndexArgs {
    Record record;
    uint32_t index;
} ZL_DatabaseIndexArgs;

typedef struct ZL_DatabaseIndex {
    uint32_t index;
    uint32_t id;
    uint32_t size;
} ZL_DatabaseIndex;

/*
 * Database stores a databases meta information
 */
class Database {
   public:
    Database (const char* filename);
    ~Database ();
    bool isOpen ();
    void close ();
    void write (Record record);
    Record getRecordByID (uint32_t id);
    ZL_DatabaseIndex getIndexByRecordID (uint32_t id);
    std::string getIndexFilename ();
    std::string getFilename ();

   private:
    std::fstream _stream;
    std::fstream _indexStream;
    char* _filename;

    void index (ZL_DatabaseIndexArgs);
};


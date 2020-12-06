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
    Database (std::string filename);
    ~Database ();
    void close ();
    void write (Record record);
    Record getRecordByID (uint32_t id);
    ZL_DatabaseIndex getIndexByRecordID (uint32_t id);
    std::string getIndexFilename ();

   private:
    std::fstream stream_;
    std::fstream indexStream_;
    std::string filename_;

    void index (ZL_DatabaseIndexArgs);
};


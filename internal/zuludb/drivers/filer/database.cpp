#include "./database.hpp"

#include <cstring>
#include <fstream>
#include <iostream>

Database::Database (std::string filename) : filename_ (filename)
{
    stream_ = std::fstream (filename,
			    std::fstream::app | std::fstream::in
				| std::fstream::out | std::fstream::binary);
    indexStream_
	= std::fstream (getIndexFilename (),
			std::fstream::app | std::fstream::in | std::fstream::out
			    | std::fstream::binary);
}

Database::~Database ()
{
    stream_.close ();
    indexStream_.close ();
}

void
    Database::close ()
{
    stream_.close ();
}

void
    Database::write (Record record)
{
    std::string data;
    data.append (reinterpret_cast<char*> (record.getID ()));
    data.append (reinterpret_cast<char*> (record.getData ()));
    stream_.write (data.c_str (), sizeof (char) * data.length ());
    // Index record
    ZL_DatabaseIndexArgs indexArgs = {};
    indexArgs.index = stream_.tellg ();
    indexArgs.record = record;
    index (indexArgs);
}

void
    Database::index (ZL_DatabaseIndexArgs args)
{
    uint32_t totalDataColumns = 2;
    std::string indexStr;
    indexStr.append (reinterpret_cast<char*> (args.record.getID ()));
    indexStr.append (reinterpret_cast<char*> (args.index));
    indexStream_.write (indexStr.c_str (), sizeof (char) * indexStr.length ());
}

Record
    Database::getRecordByID (uint32_t id)
{
    // Seek position (avoid ID which we know)
    auto recordIndexData = getIndexByRecordID (id);
    stream_.seekg (recordIndexData.index + sizeof (id));

    // Extract record
    char* recordData;
    stream_.read (recordData, recordIndexData.size);

    // Reconstruct record
    ZL_RecordStruct rStruct = {};
    rStruct.data = recordData;
    rStruct.id = id;
    Record r (rStruct);

    return r;
}

ZL_DatabaseIndex
    Database::getIndexByRecordID (uint32_t id)
{
    ZL_DatabaseIndex index{};
    return index;
}

std::string
    Database::getIndexFilename ()
{
    std::string indexFilename (filename_);
    indexFilename.append (".index");
    return indexFilename;
}

#include "./database.hpp"

#include <cstring>
#include <fstream>
#include <iostream>

Database::Database (const char* filename)
{
    this->_filename = (char*) malloc (strlen (filename));
    std::strcpy (this->_filename, filename);
    this->_stream
	= std::fstream (getFilename (),
			std::fstream::app | std::fstream::in | std::fstream::out
			    | std::fstream::binary);
    this->_indexStream
	= std::fstream (this->getIndexFilename (),
			std::fstream::app | std::fstream::in | std::fstream::out
			    | std::fstream::binary);
}

Database::~Database ()
{
    this->_stream.close ();
    this->_indexStream.close ();
    free (this->_filename);
}

bool
    Database::isOpen ()
{
    return this->_stream.is_open ();
}

void
    Database::close ()
{
    this->_stream.close ();
}

void
    Database::write (Record record)
{
    std::string data;
    data.append (reinterpret_cast<char*> (record.getID ()));
    data.append (reinterpret_cast<char*> (record.getData ()));
    this->_stream.write (data.c_str (), sizeof (record.getData ()));
    // Index record
    ZL_DatabaseIndexArgs indexArgs = {};
    indexArgs.index = this->_stream.tellg ();
    indexArgs.record = record;
    this->index (indexArgs);
}

void
    Database::index (ZL_DatabaseIndexArgs args)
{
    // Allocate 2 * uint32_t
    char* indexStr = (char*) malloc (sizeof (uint32_t) * 2);
    // Add ID
    std::strcpy (indexStr, reinterpret_cast<char*> (args.record.getID ()));
    // Add index
    std::strcpy (indexStr, reinterpret_cast<char*> (args.index));
    // Write to file
    this->_indexStream.write (indexStr, sizeof (char) * std::strlen (indexStr));
}

Record
    Database::getRecordByID (uint32_t id)
{
    // Seek position (avoid ID which we know)
    auto recordIndexData = this->getIndexByRecordID (id);
    this->_stream.seekg (recordIndexData.index + sizeof (id));

    // Extract record
    char* recordData;
    this->_stream.read (recordData, recordIndexData.size);

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
}

std::string
    Database::getFilename ()
{
    return this->_filename;
}
std::string
    Database::getIndexFilename ()
{
    std::string indexFilename (this->_filename);
    indexFilename.append (".index");
    return indexFilename;
}

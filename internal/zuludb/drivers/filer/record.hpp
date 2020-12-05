#include <iostream>
#ifndef DATABASE_H
#define DATABASE_H

class Database;

/*
 * Record stores a table's record data
 */
class Record {
	public:
		Record();
		Record(uint32_t id, const char data[]);
		uint32_t getID();
		uint32_t getIndex();
		uint32_t setIndex();
		char* getData();
	private:
		uint32_t id;
		uint32_t _index;
		char* data;
};

#endif

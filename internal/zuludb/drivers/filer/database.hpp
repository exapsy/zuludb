#include <iostream>
#include <fstream>
#include <string>

#include "./record.hpp"

/*
 * Database stores a databases meta information
 */
class Database {
	public:
		Database(std::string filename);
		void open();
		bool isOpen();
		void close();
		void write(Record record);
		std::string getIndexFilename();
		std::string getFilename();
	private:
		std::fstream* _stream;
		std::fstream* _indexStream;
		char* _filename;

		void index(Record record, uint32_t index);
};


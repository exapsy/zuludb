#include <iostream>
#include <fstream>
#include <cstring>

#include "./database.hpp"

Database::Database(const char* filename) {
	this->_filename = (char*) malloc(strlen(filename));
	std::strcpy(this->_filename, filename);
	this->_stream = std::fstream(
			//getFilename(),
			"db.txt",
			std::fstream::app
			| std::fstream::in
			| std::fstream::out
	);
	this->_indexStream = std::fstream(
			getIndexFilename(),
			std::fstream::app
			| std::fstream::in
			| std::fstream::out
	);
}

Database::~Database() {
	this->_stream.close();
	this->_indexStream.close();
	free(this->_filename);
}

bool Database::isOpen() {
	return this->_stream.is_open();
}

void Database::open() {
	this->_stream.open(this->_filename);
	this->_indexStream.open(this->_filename);
}

void Database::close() {
	this->_stream.close();
}

void Database::write(Record record) {
	this->_stream.write(
		record.getData(),
		sizeof(char) * std::strlen(record.getData())
	);
}

void Database::index(Record record, uint32_t index) {
	// Allocate 2 * uint32_t
	char* indexStr = (char*) malloc(sizeof(char) * 2);
	// Add ID
	std::strcpy(indexStr, reinterpret_cast<char*>(record.getID()));
	// Add index
	std::strcpy(indexStr, reinterpret_cast<char*>(record.getID()));
	// Write to file
	this->_indexStream.write(
		indexStr,
		sizeof(uint32_t)
	);
}

std::string Database::getFilename() {
	return this->_filename;
}
std::string Database::getIndexFilename() {
	return std::strcat(this->_filename, ".index");
}

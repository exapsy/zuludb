#include <cstring>

#include "./record.hpp"

Record::Record(ZL_RecordStruct record) {
	this->_id = record.id;
	this->_data = record.data;
}

Record::~Record() {
}

char* Record::getData() {
	return this->_data;
}

uint32_t Record::getID() {
	return this->_id;
}

uint32_t Record::getIndex() {
	return this->_index;
}

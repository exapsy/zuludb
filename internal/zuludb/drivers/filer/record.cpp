#include <cstring>

#include "./record.hpp"

Record::Record(uint32_t id, const char data[]) {
	this->id = id;
	std::strcpy(this->data, data);
}

char* Record::getData() {
	return this->data;
}

uint32_t Record::getID() {
	return this->id;
}

uint32_t Record::getIndex() {
	return this->_index;
}

#include <iostream>
#include "../../internal/zuludb/drivers/filer/database.hpp"

int main() {
	std::cout << "Opening stream\n";
	std::string filename = "db";
	Database db(filename);
	db.open();

	std::cout << "Writing data\n";
	const char* data = "";
	Record record(1, data);
	db.write(record);
	std::cout << "Data written\n";

	return EXIT_SUCCESS;
}

#include <iostream>
#include <cstring>
#include "../../internal/zuludb/drivers/filer/database.hpp"
#include "../../internal/zuludb/drivers/filer/record.hpp"

int main() {
	Database db("db");

	char data[] = "Hello bitches";

	ZL_RecordStruct r{};
	r.id = 1;
	r.data = data;
	Record record(r);

	db.write(record);

	return EXIT_SUCCESS;
}

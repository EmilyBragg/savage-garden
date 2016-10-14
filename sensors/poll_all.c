#include <stdio.h>
#include <sqlite3.h>
#include "database_interactions.h"


int main(void) {
	sqlite3* db = initialize_db();
	char* errbuf = 0;	
	record(db, "test_sensor2", 456.35);
	sqlite3_close(db);
	return 0;	


}

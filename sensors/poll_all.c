#include <stdio.h>
#include <sqlite3.h>
#include "database_interactions.h"


int main(void) {
	sqlite3* db = initialize_db();
	char* errbuf = 0;	
	sqlite3_exec(db, "insert into SENSOR_READINGS(ID, VALUE) VALUES('test_sensor', 5556);", NULL, 0, &errbuf);

	sqlite3_close(db);
	return 0;	


}

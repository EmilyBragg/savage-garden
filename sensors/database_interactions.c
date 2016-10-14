#include "database_interactions.h"
sqlite3* initialize_db(void) {
	
	sqlite3 *db;
	char *errbuf = 0;
	int rc;
	
	if (rc = sqlite3_open(SENSOR_DB, &db)) {
		printf("Couldn't open database: %s\n", sqlite3_errmsg(db));
	} else {
		printf("Opened sensor db.\n");
	}

	
	char* sql = "CREATE TABLE IF NOT EXISTS SENSOR_READINGS(" \
		  "ID TEXT PRIMARY KEY NOT NULL," \
		  "VALUE INT NOT NULL," \
		  "TS DATETIME DEFAULT CURRENT_TIMESTAMP);";

	if (sqlite3_exec(db, sql, NULL, 0, &errbuf)) {
		printf("Failed to create table: %s\n", errbuf);
		sqlite3_free(errbuf);
	} else {
		printf("Created table\n");
	}
	return db;

};

void record(sqlite3* db, SensorID s, reading) {
	


};

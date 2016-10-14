#include "database_interactions.h"

sqlite3* initialize_db(void) {
	
	sqlite3 *db;
	char* errbuf = 0;
	int rc;
	
	if (rc = sqlite3_open(SENSOR_DB, &db)) {
		printf("Couldn't open database: %s\n", sqlite3_errmsg(db));
	} else {
		printf("Opened sensor db.\n");
	}

	
	std::string sql = "CREATE TABLE IF NOT EXISTS SENSOR_READINGS(" \
		  "ID TEXT NOT NULL," \
		  "VALUE INT NOT NULL," \
		  "TS DATETIME DEFAULT CURRENT_TIMESTAMP,"\
		  "PRIMARY KEY (ID, VALUE));";

	if (sqlite3_exec(db, sql.c_str(), NULL, 0, &errbuf)) {
		printf("Failed to create table: %s\n", errbuf);
		sqlite3_free(errbuf);
	} else {
		printf("Created table\n");
	}
	return db;

};

void record(sqlite3* db, std::string sensor, float reading) {
	char* errbuf = 0;
	std::string query = "INSERT into SENSOR_READINGS(ID, VALUE) VALUES('" + sensor+ "'," + std::to_string(reading) + ");";
	if (sqlite3_exec(db, query.c_str(), NULL, 0, &errbuf)) {
		printf("%s\n", errbuf);
		// error
	} else {
		// inserted values
	}	


};

#include <stdio.h>
#include <sqlite3.h>

#define SENSOR_DB "sensor.db"

//SELECT id, datetime(ts, 'localtime') from SENSOR_READINGS;

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

//int modify_table();

//int connect(); 


int main(void) {
	sqlite3* db = initialize_db();
	char* errbuf = 0;	
	sqlite3_exec(db, "insert into SENSOR_READINGS(ID, VALUE) VALUES('test_sensor', 5556);", NULL, 0, &errbuf);

	sqlite3_close(db);
	return 0;	


}

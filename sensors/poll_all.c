#include <stdio.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void initialize_db(void) {
	
	sqlite3 *db;
	char *errbuf = 0;
	int rc;
	
	if (rc = sqlite3_open("sensor.db", &db)) {
		printf("Couldn't open database: %s\n", sqlite3_errmsg(db));
	} else {
		printf("Opened sensor db.\n");
	}
	

	char* sql = "CREATE TABLE SENSOR_READINGS(" \
		  "ID TEXT PRIMARY KEY NOT NULL," \
		  "VALUE INT NOT NULL," \
		  "TS DATETIME DEFAULT CURRENT_TIMESTAMP);";

	if (sqlite3_exec(db, sql, callback, 0, &errbuf)) {
		printf("Failed to create table: %s\n", errbuf);
		sqlite3_free(errbuf);
	} else {
		printf("Created table\n");
	}

	sqlite3_close(db);

};

//int modify_table();

//int connect(); 

int main(void) {
	initialize_db();
	return 0;	


}

#include <stdio.h>
#include <sqlite3.h>

#define SENSOR_DB "sensor.db"


//SELECT id, datetime(ts, 'localtime') from SENSOR_READINGS;
sqlite3* initialize_db(void);


void record(sqlite3* db, SensorType s, reading);


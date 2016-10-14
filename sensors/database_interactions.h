#include <stdio.h>
#include <string>
#include <sqlite3.h>
#include "sensor.h"

#define SENSOR_DB "sensor.db"


//SELECT id, datetime(ts, 'localtime') from SENSOR_READINGS;
sqlite3* initialize_db(void);


void record(sqlite3* db, std::string s, float reading);
SensorReading* retrieve_readings_n_days(std::string sensor, int days);
SensorReading retrieve_current_value(std::string sensor);
SensorReading* retrieve_current_state();



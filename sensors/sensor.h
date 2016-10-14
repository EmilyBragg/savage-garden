#include <stdio.h>
#include <stdlib.h>

typedef struct SensorReading{
	float reading;
	time_t timestamp;
} SensorReading;

class Sensor {
	public:
		float read();
	private:
		int measure();
		float normalize(int measured);
		int range;
		int offset;
};



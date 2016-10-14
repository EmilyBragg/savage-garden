#include <stdio>
#include <stdlib>

class Sensor {
	public:
		float read();
	private:
		int measure();
		float normalize(int measured);
		int range;
		int offset;
};



#ifndef Sensors_h
#define Sensors_h

#include "Arduino.h"

#define RT0 10000
#define T0 298.15 //273.15 + 25 = 298.15K
#define B 3950

#define R1 10000
#define THERMISTOR_PIN A0


class Sensors {
public:
	Sensors();
	float getTemperature();
};


#endif
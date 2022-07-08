#ifndef Sensors_h
#define Sensors_h

#include "Arduino.h"
#include "GPSPos.h"

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#define RT0 10000
#define T0 298.15 //273.15 + 25 = 298.15K
#define B 3950

#define R1 10000
#define THERMISTOR_PIN A0

#define GPS_RXPIN 3
#define GPS_TXPIN 4
#define GPS_BAUD 9600


class Sensors {
public:
	Sensors();
	void update();
	const float getTemperature();
	const GPSPos getGPSPosition();
private:
	TinyGPSPlus gps;
	SoftwareSerial gpsSerial;
};


#endif

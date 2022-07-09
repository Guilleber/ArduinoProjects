#ifndef Sensors_h
#define Sensors_h

#include "Arduino.h"

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#define RT0 (uint16_t)10000
#define T0 (float)298.15 //273.15 + 25 = 298.15K
#define B (uint16_t)3950

#define R1 (uint16_t)10000
#define THERMISTOR_PIN A0

#define GPS_RXPIN (uint8_t)3 //white
#define GPS_TXPIN (uint8_t)4 //green
#define GPS_BAUD (uint16_t)9600


class Sensors {
public:
	Sensors();
	void update();
	const float getTemperature();
	TinyGPSPlus* getGPSData();
private:
	TinyGPSPlus gps {};
	SoftwareSerial gpsSerial {GPS_RXPIN, GPS_TXPIN};
};


#endif

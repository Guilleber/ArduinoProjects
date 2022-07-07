#include "Sensors.h"
#include "Arduino.h"


Sensors::Sensors() {
	return;
}

const float Sensors::getTemperature() {
	float RT, VR, ln, TX, VRT;
	
	VRT = analogRead(THERMISTOR_PIN);
	VRT = (5. / 1023.) * VRT;
	VR = 5. - VRT;
	RT = VRT / (VR / R1);

	ln = log(RT / RT0);
	TX = (1 / ((ln / B) + (1 / T0)));

	TX = TX - 273.15;
	return TX;
}
#include "Controller.h"
#include "Arduino.h"

//#include "GPSTrackingMemory.h"
#include "Sensors.h"

#include <TinyGPS++.h>


Controller::Controller() {
	return;
}

void Controller::switchScreen() {
	return;
}

void Controller::sleep(int time) {
	int start = millis();
	do {
		this->sensors.update();
	} while(millis() - start < time);
	return;
}

const void Controller::refreshFrame() {
	TinyGPSPlus* gps = this->sensors.getGPSData();
  if (gps->location.isValid()) {
  	Serial.print(gps->location.lat(), 10);
  	Serial.print(" ");
  	Serial.println(gps->location.lng(), 10);
  } else {
    Serial.println("Error !");
  }
	return;
}

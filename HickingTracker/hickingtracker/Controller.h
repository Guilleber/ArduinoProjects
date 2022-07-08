#ifndef Controller_h
#define Controller_h

#include "Arduino.h"

#include "GPSTrackingMemory.h"
#include "GPSPos.h"
#include "Sensors.h"


class Controller {
public:
	Controller();
	void switchScreen();
	void sleep(int time);
	const void refreshFrame();
private:
	const void drawFrame();

	Sensors sensors;
	GPSTrackingMemory tracking_mem;
};


#endif
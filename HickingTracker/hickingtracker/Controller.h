#ifndef Controller_h
#define Controller_h

#include "Arduino.h"

//#include "GPSTrackingMemory.h"
#include "Sensors.h"

#include <TinyGPS++.h>

enum Screen {General, Location, Map};


class Controller {
public:
	Controller();
	void switchScreen();
	void sleep(int time);
	const void refreshFrame();
private:
	//const void drawFrame();
  
  Screen curr_screen = General;

	Sensors sensors {};
	//GPSTrackingMemory tracking_mem;
};


#endif

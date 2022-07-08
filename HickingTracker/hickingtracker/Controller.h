#ifndef Controller_h
#define Controller_h

#include "Arduino.h"

//#include "GPSTrackingMemory.h"
#include "Sensors.h"

#include <TinyGPS++.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define NB_SCREENS 2;
enum Screen {General, Map};

#define TFT_CS   10
#define TFT_RST  8
#define TFT_DC   9

#define TFT_MOSI 11
#define TFT_SCLK 13


class Controller {
public:
	Controller();
  void init();
	void switchScreen();
	void sleep(int time);
	const void refresh();
private:
  Screen curr_screen = General;

	Sensors sensors {};
  Adafruit_ST7735 disp {TFT_CS, TFT_DC, TFT_RST};
	//GPSTrackingMemory tracking_mem;
};


#endif

#ifndef Controller_h
#define Controller_h

#include "Arduino.h"

#include "GPSTrackingMemory.h"
#include "Utils.h"
#include "Sensors.h"

#include <TinyGPS++.h>
#include <Adafruit_GFX.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define NB_SCREENS 2;
enum Screen {Main, Detail};

#define TFT_CS   10
#define TFT_RST  8
#define TFT_DC   9

#define TFT_MOSI 11
#define TFT_SCLK 13

#define BUTTON_PIN 2


class Controller {
public:
	Controller();
  void init();
	void switchScreen();
	void sleep(int time);
	const void refresh();
private:
  Screen curr_screen = Detail;

	Sensors sensors {};
  Adafruit_ST7735 disp {TFT_CS, TFT_DC, TFT_RST};
	//GPSTrackingMemory tracking_mem;
};


#endif

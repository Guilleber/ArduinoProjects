#ifndef Controller_h
#define Controller_h

#include "Arduino.h"

//#include "GPSTrackingMemory.h"
#include "Sensors.h"

#include <TinyGPS++.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define NB_SCREENS (uint8_t)2;
enum Screen {Main, Detail};

#define TFT_CS   (uint8_t)10
#define TFT_RST  (uint8_t)8
#define TFT_DC   (uint8_t)9

#define TFT_MOSI (uint8_t)11
#define TFT_SCLK (uint8_t)13

#define BUTTON_PIN (uint8_t)2

#define LOCAL_TIME (int8_t)-4


class Controller {
public:
	Controller();
  void init();
	void switchScreen();
	void sleep(const int time);
	const void refresh();
private:
  Screen curr_screen = Detail;

	Sensors sensors {};
  Adafruit_ST7735 disp {TFT_CS, TFT_DC, TFT_RST};
	//GPSTrackingMemory tracking_mem;
};


#endif

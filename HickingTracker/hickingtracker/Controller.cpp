#include "Controller.h"
#include "Arduino.h"

//#include "GPSTrackingMemory.h"
#include "Sensors.h"

#include <TinyGPS++.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>


Controller::Controller() {
	return;
}

void Controller::init() {
  this->disp.initR(INITR_BLACKTAB);
  this->disp.setRotation(1);
  this->disp.fillScreen(ST77XX_BLACK);
  Serial.begin(9600);
}

void Controller::switchScreen() {
  this->curr_screen = (this->curr_screen + 1)%NB_SCREENS;
	return;
}

void Controller::sleep(int period) {
	unsigned long start = millis();
  Serial.println(start);
	do {
		this->sensors.update();
	} while(millis() - start < period);
  Serial.println(millis());
	return;
}

const void Controller::refresh() {
	TinyGPSPlus* gps = this->sensors.getGPSData();
  //this->disp.fillScreen(ST77XX_BLACK);
  this->disp.setCursor(0, 0);
  this->disp.setTextColor(ST77XX_WHITE);
  this->disp.setTextWrap(true);
  this->disp.print("Hello world!");
	return;
}

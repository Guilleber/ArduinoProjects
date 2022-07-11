#include "Controller.h"
#include "Arduino.h"

#include "GPSTrackingMemory.h"
#include "Sensors.h"

#include <TinyGPS++.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <SD.h>


Controller::Controller() {
	return;
}

void Controller::init() {
  this->disp.initR(INITR_BLACKTAB);
  this->disp.setRotation(1);
  this->disp.fillScreen(ST77XX_BLACK);
  this->refresh();

  //init SD card
  if(SD.begin(SD_PIN))
    this->is_SD_initialized = true;
}

void Controller::switchScreen() {
  this->curr_screen = (this->curr_screen + 1)%NB_SCREENS;
  this->disp.fillScreen(ST77XX_BLACK);
  this->refresh();
	return;
}

void Controller::sleep(int period) {
	unsigned long start = millis();
	do {
		this->sensors.update();
	} while(millis() - start < period);
	return;
}

const void Controller::refresh() {
  noInterrupts();
	TinyGPSPlus* gps = this->sensors.getGPSData();

  if(curr_screen == Main) {
    this->disp.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
    this->disp.setTextSize(3);
    this->disp.setCursor(40, 25);
    if(gps->time.isValid()) {
      int local_hour = (gps->time.hour()+LOCAL_TIME)%24;
      if(local_hour < 10)
        this->disp.print('0');
      this->disp.print(local_hour);
      this->disp.print(F(":"));
      if(gps->time.minute() < 10)
        this->disp.print('0');
      this->disp.print(gps->time.minute());
    } else {
      this->disp.print(F("##:##"));
    }
    this->disp.setTextSize(1);
    
    this->disp.setCursor(50, 70);
    this->disp.print(F("Lat: "));
    if (gps->location.isValid())
      this->disp.print(gps->location.lat(), 2);
    else
      this->disp.print(F("None"));
    this->disp.print(' ');

    this->disp.setCursor(50, 80);
    this->disp.print(F("Lng: "));
    if (gps->location.isValid())
      this->disp.print(gps->location.lng(), 2);
    else
      this->disp.print(F("None"));
    this->disp.print(F(" "));

    this->disp.setCursor(50, 90);
    this->disp.print(F("Temp: "));
    this->disp.print((uint8_t)this->sensors.getTemperature());
    this->disp.print(F(" C  "));
  } else if(curr_screen == Detail) {
    this->disp.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
    this->disp.setTextSize(2);
    this->disp.setCursor(55, 4);
    if(gps->time.isValid()) {
      int local_hour = (gps->time.hour()+LOCAL_TIME)%24;
      if(local_hour < 10)
        this->disp.print('0');
      this->disp.print(local_hour);
      this->disp.print(":");
      if(gps->time.minute() < 10)
        this->disp.print('0');
      this->disp.print(gps->time.minute());
    } else {
      this->disp.print(F("##:##"));
    }

    this->disp.drawLine(2, 26, 158, 26, ST77XX_WHITE);

    this->disp.setTextSize(1);
    this->disp.setCursor(2, 34);
    this->disp.print(F("LATITUDE  : "));
    if (gps->location.isValid()) {
      if(gps->location.lat() >= 0)
        this->disp.print(" ");
      this->disp.print(gps->location.lat(), 2);
    } else
      this->disp.print(F(" ##.##"));
    this->disp.print(' ');

    this->disp.setCursor(2, 44);
    this->disp.print(F("LONGITUDE : "));
    if (gps->location.isValid()) {
      if(gps->location.lng() >= 0)
        this->disp.print(" ");
      this->disp.print(gps->location.lng(), 2);
    } else
      this->disp.print(F(" ##.##"));
    this->disp.print(F(" "));

    this->disp.setCursor(2, 64);
    this->disp.print(F("ALTITUDE  :  "));
    if (gps->altitude.isValid()) {
      this->disp.print((uint16_t)gps->altitude.meters());
      if(gps->altitude.meters() < 1000)
        this->disp.print(' ');
      if(gps->altitude.meters() < 100)
        this->disp.print(' ');
      if(gps->altitude.meters() < 10)
        this->disp.print(' ');
      this->disp.print('m');
    } else
      this->disp.print(F("####m"));

    this->disp.setCursor(2, 74);
    this->disp.print(F("AIR TEMP  : "));
    int temp = (int8_t)this->sensors.getTemperature();
    if(temp >= 0)
      this->disp.print(' ');
    this->disp.print(temp);
    this->disp.print(F("  C"));
  }
  interrupts();
	return;
}

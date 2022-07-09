#include "Controller.h"
#include "Arduino.h"

#include "GPSTrackingMemory.h"
#include "Utils.h"
#include "Sensors.h"

#include <TinyGPS++.h>
#include <Adafruit_GFX.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>


Controller::Controller() {
	return;
}

void Controller::init() {
  this->disp.initR(INITR_BLACKTAB);
  this->disp.setRotation(1);
  this->disp.fillScreen(ST77XX_BLACK);
  this->refresh();
  
  Serial.begin(9600);
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
    GFXcanvas1 time_canvas(125, 25);
    time_canvas.setFont(&FreeMonoBold18pt7b);
    time_canvas.setCursor(0, 22);
    if(gps->time.isValid()) {
      int local_hour = getLocalHour(gps->time.hour());
      if(local_hour < 10)
        time_canvas.print('0');
      time_canvas.print(local_hour);
      time_canvas.print(F(":"));
      if(gps->time.minute() < 10)
        time_canvas.print('0');
      time_canvas.print(gps->time.minute());
    } else {
      time_canvas.print(F("##:##"));
    }
    this->disp.drawBitmap(30, 25, time_canvas.getBuffer(), 125, 25, ST77XX_WHITE, ST77XX_BLACK);
    
    this->disp.setCursor(50, 70);
    this->disp.print(F("Lat: "));
    if (gps->location.isValid())
      this->disp.print(gps->location.lat(), 4);
    else
      this->disp.print(F("None"));
    this->disp.print(' ');

    this->disp.setCursor(50, 80);
    this->disp.print(F("Lng: "));
    if (gps->location.isValid())
      this->disp.print(gps->location.lng(), 4);
    else
      this->disp.print(F("None"));
    this->disp.print(F(" "));

    this->disp.setCursor(50, 90);
    this->disp.print(F("Temp: "));
    this->disp.print((int)this->sensors.getTemperature());
    this->disp.print(F(" C  "));
  } else if(curr_screen == Detail) {
    this->disp.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
    GFXcanvas1 time_canvas(85, 16);
    time_canvas.setFont(&FreeMonoBold12pt7b);
    time_canvas.setCursor(0, 14);
    if(gps->time.isValid()) {
      int local_hour = getLocalHour(gps->time.hour());
      if(local_hour < 10)
        time_canvas.print('0');
      time_canvas.print(local_hour);
      time_canvas.print(":");
      if(gps->time.minute() < 10)
        time_canvas.print('0');
      time_canvas.print(gps->time.minute());
    } else {
      time_canvas.print(F("##:##"));
    }
    this->disp.drawBitmap(45, 5, time_canvas.getBuffer(), 85, 16, ST77XX_WHITE, ST77XX_BLACK);

    this->disp.drawLine(2, 26, 158, 26, ST77XX_WHITE);
  }
  interrupts();
	return;
}

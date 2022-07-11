#include "GPSTrackingMemory.h"
#include "Arduino.h"
#include <SPI.h>
#include <SD.h>


void format_timestamp(char timestamp[], int year, int month, int day, int hour, int minute) {
  sprintf(timestamp, "%04d%02d%02dT%02d%02dZ", year, month, day, hour, minute);
  return;
}


GPSTrackingMemory::GPSTrackingMemory(char name[]) {
  Serial.println("20221127T1245Z");
  SD.open("20221127T1245Z", FILE_WRITE);
  Serial.println(SD.exists("20221127T1245Z"));
  return;
}

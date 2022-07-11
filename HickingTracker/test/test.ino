#include <SD.h>
#include <SPI.h>


void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(SD.begin(10));
}

#include "Sensors.h"


Sensors sensors;

void setup() {
  Serial.begin(9600);
  sensors = Sensors();
}

void loop() {
  float TX = sensors.getTemperature();

  Serial.print("Temperature:");
  Serial.print("\t");
  Serial.print(TX);
  Serial.print("C\t\t");
  Serial.print(TX + 273.15);        //Conversion to Kelvin
  Serial.print("K\t\t");
  Serial.print((TX * 1.8) + 32);    //Conversion to Fahrenheit
  Serial.println("F");
  delay(1000);
}

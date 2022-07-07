#include "Sensors.h"

#define INT_PIN 3


Sensors sensors;

volatile int state = 0;

void plop() {
  state = (state+1)%5;
  Serial.print(state);
  Serial.print("\n");
}

void setup() {
  Serial.begin(9600);
  sensors = Sensors();
  pinMode(INT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INT_PIN), plop, FALLING);
}

void loop() {
  delay(1000);
}

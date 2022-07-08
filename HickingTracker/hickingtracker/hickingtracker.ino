#include "Controller.h"


Controller controller;

void setup() {
  Serial.begin(9600);
}

void loop() {
	controller.refreshFrame();
	controller.sleep(1000);
}

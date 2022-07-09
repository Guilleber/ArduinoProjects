#include "Controller.h"


Controller controller;

void setup() {
  controller.init();
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonPressed, FALLING);
}

void loop() {
	controller.refresh();
	controller.sleep(1000);
}

void buttonPressed(){
  if(!digitalRead(2)) {
    controller.switchScreen();
  }
}

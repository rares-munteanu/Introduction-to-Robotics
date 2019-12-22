#include "Button.h"

button::button(unsigned short buttonPin, unsigned short debounceTime): buttonPin(buttonPin), debounceTime(debounceTime) {
  pinMode(buttonPin, INPUT_PULLUP);
}

bool button::isPressed() {
  bool pressed = false;
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    if (millis() - lastPressTime > debounceTime)
      pressed = true;
    lastPressTime = millis();
  }
  return pressed;
}

unsigned short button::getButtonPin() {
  return buttonPin;
}

void debugButton(button &a) {
  Serial.println(digitalRead(a.buttonPin));
}

void debug2Button(button &a) {
  if (a.isPressed()) {
    Serial.print("Button from pin ");
    Serial.print(a.getButtonPin());
    Serial.println(" pressed.");
  }
}

#include "Joystick.h"

joystick::joystick(const short xPin, const short yPin, unsigned minTreshold, unsigned maxTreshold, bool bothAxisSameTime = false): swButtonPin(0), xAxisPin(xPin), yAxisPin(yPin),
  minTreshold(minTreshold), maxTreshold(maxTreshold), bothAxisSameTime(bothAxisSameTime) {
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
}
joystick::joystick(const short xPin, const  short yPin, const short swPin, unsigned minTreshold, unsigned maxTreshold , bool bothAxisSameTime = false): swButtonPin(swPin), xAxisPin(xPin), yAxisPin(yPin),
  minTreshold(minTreshold), maxTreshold(maxTreshold), bothAxisSameTime(bothAxisSameTime) {
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(swButtonPin, INPUT_PULLUP);
}

void joystick::readJoystick() {
  xValue = analogRead(xAxisPin);
  yValue = analogRead(yAxisPin);
}

void joystick::readSwButton() {
  swButtonState = digitalRead(swButtonPin);
}

bool joystick::movedLeft() {
  readJoystick();
  bool moved = false;
  if (xValue < minTreshold) {
    if (joyXMoved == false and ((!bothAxisSameTime and joyMoved == false) or (bothAxisSameTime)))
      moved = true;
    joyXMoved = true;
    joyMoved = true;
  }
  else if (xValue > minTreshold and xValue < maxTreshold) {
    joyXMoved = false;
    joyMoved = false;
  }
  return moved;
}

bool joystick::movedRight() {
  readJoystick();
  bool moved = false;
  if (xValue > maxTreshold) {
    if (joyXMoved == false and ((!bothAxisSameTime and joyMoved == false) or (bothAxisSameTime)))
      moved = true;
    joyXMoved = true;
    joyMoved = true;
  }
  else if (xValue > minTreshold and xValue < maxTreshold) {
    joyXMoved = false;
    joyMoved = false;
  }
  return moved;
}

bool joystick::movedUp() {
  readJoystick();
  bool moved = false;
  if (yValue < minTreshold) {
    if (joyYMoved == false and ((!bothAxisSameTime and joyMoved == false) or (bothAxisSameTime)))
      moved = true;
    joyYMoved = true;
    joyMoved = true;
  }
  else if (yValue > minTreshold and yValue < maxTreshold) {
    joyYMoved = false;
    joyMoved = false;
  }
  return moved;
}

bool joystick::movedDown() {
  readJoystick();
  bool moved = false;
  if (yValue > maxTreshold) {
    if (joyYMoved == false and ((!bothAxisSameTime and joyMoved == false) or (bothAxisSameTime)))
      moved = true;
    joyYMoved = true;
    joyMoved = true;
  }
  else if (yValue > minTreshold and yValue < maxTreshold) {
    joyYMoved = false;
    joyMoved = false;
  }
  return moved;
}
bool joystick::buttonPressed() {
  readSwButton();
  bool ok = false;
  if (swButtonState == LOW) {
    if (millis() - lastPressTime > debounceTime) {
      ok = true;
    }
    lastPressTime = millis();
  }
  return ok;
}

void debugJoystick(joystick &a) {
  a.readJoystick();
  a.readSwButton();
  Serial.print("X: ");
  Serial.print(a.xValue);
  Serial.print(" Y: ");
  Serial.print(a.yValue);
  Serial.print(" Button: ");
  Serial.println(a.swButtonState);
}

void debug2Joystick(joystick &a) {
  a.readJoystick();
  a.readSwButton();
  if (a.movedUp())
    Serial.println("UP");
  if (a.movedDown())
    Serial.println("DOWN");
  if (a.movedLeft())
    Serial.println("LEFT");
  if (a.movedRight())
    Serial.println("RIGHT");
  if (a.buttonPressed())
    Serial.println("PRESSED");
}

#ifndef JOYSTICK
#define JOYSTICK

const int xAxisPin = A0;
const int yAxisPin = A1;
const int swButtonPin = A5;

const unsigned minTreshold = 300;
const unsigned maxTreshold = 700;
const unsigned debounceInterval = 50;

unsigned lastPressedTime = 0;

int xValue  = 0;
int yValue = 0;
int buttonState = HIGH;
bool joyXMoved = false;
bool joyYMoved = false;

void readJoystick() {
  xValue = analogRead(xAxisPin);
  yValue = analogRead(yAxisPin);
  buttonState = digitalRead(swButtonPin);
}

bool movedLeft() {
  bool moved = false;
  if (xValue < minTreshold) {
    if (joyXMoved == false)
      moved = true;
    joyXMoved = true;
  }
  else if (xValue > minTreshold and xValue < maxTreshold) {
    joyXMoved = false;
  }
  return moved;
}

bool movedRight() {
  bool moved = false;
  if (xValue > maxTreshold) {
    if (joyXMoved == false)
      moved = true;
    joyXMoved = true;
  }
  else if (xValue > minTreshold and xValue < maxTreshold) {
    joyXMoved = false;
  }
  return moved;
}

bool movedUp() {
  bool moved = false;
  if (yValue < minTreshold) {
    if (joyYMoved == false)
      moved = true;
    joyYMoved = true;
  }
  else if (yValue > minTreshold and yValue < maxTreshold) {
    joyYMoved = false;
  }
  return moved;
}

bool movedDown() {
  bool moved = false;
  if (yValue > maxTreshold) {
    if (joyYMoved == false)
      moved = true;
    joyYMoved = true;
  }
  else if (yValue > minTreshold and yValue < maxTreshold) {
    joyYMoved = false;
  }
  return moved;
}

bool buttonPressed() {
  bool pressed = false;
  if (buttonState == LOW) {
    if (millis() - lastPressedTime > debounceInterval)
      pressed = true;
    lastPressedTime = millis();
  }
  return pressed;
}

#endif JOYSTICK

const int pinA = 9;
const int pinB = 2;
const int pinC = 3;
const int pinD = 5;
const int pinE = 6;
const int pinF = 8;
const int pinG = 7;
const int pinDP = 4;
const int pinD1 = 10;
const int pinD2 = 11;
const int pinD3 = 12;
const int pinD4 = 13;

const int xAxisPin = A0;
const int yAxisPin = A1;
const int swButtonPin = A5;

const int segSize = 8;
const int noOfDisplays = 4;
const int noOfDigits = 10;

// segments array, similar to before
const int segments[segSize] = {
  pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP
};
// digits array, to switch between them easily
const int displays[noOfDisplays] = {
  pinD1, pinD2, pinD3, pinD4
};

const byte digitMatrix[noOfDigits + 1][segSize - 1] = {
  // a  b  c  d  e  f  g
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1},  // 9
  {0, 0, 0, 0, 0, 0, 0} // pt -1
};

//int actualNumbers[] = { 0, 0, 0, 0};
int actualNumbers[] = { -1, -1, -1, -1};
int pointingDigit[] = {1, 0, 0, 0};

bool joyXMoved = false;
bool joyYMoved = false;
bool buttonPressed = false;

bool lockedOnDigit = false;
bool lockedOnValue = false;

int minTreshold = 300; // min value at the default joystick state
int maxTreshold = 700; // max value at the default joystick state

int xValue = 0;
int yValue = 0;
int buttonState = 1;
int lastButtonState = HIGH;
int reading = 0; //for button

int currentDigit = 0;
int lastDigit = 0;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;


// activate the display no. received as param
void activateDisplay(int& num) {

  for (int k = 0; k < noOfDisplays; k++) {
    digitalWrite(displays[k], HIGH);
  }
  digitalWrite(displays[num], LOW);

}

void displayValue(int value, int decimalPoint) {
  if (value >= 0 && value < 11)
    for (int i = 0; i < segSize - 1; i++)
      digitalWrite(segments[i], digitMatrix[value][i]);
  else
    for (int i = 0; i < segSize - 1; i++)
      digitalWrite(segments[i], digitMatrix[10][i]);

  // write the decimalPoint to DP pin
  digitalWrite(segments[segSize - 1], decimalPoint);
  delay(4);
}


void showDisplay() {
  for (int j = 0; j < noOfDisplays; j++) {
    activateDisplay(j);
    displayValue(actualNumbers[j], pointingDigit[j]);
  }
}


void setup() {
  for (int i = 0; i < segSize; i++)
    pinMode(segments[i], OUTPUT);
  for (int i = 0; i < noOfDisplays; i++)
    pinMode(displays[i], OUTPUT);

  pinMode(xAxisPin, INPUT);
  pinMode(yAxisPin, INPUT);
  pinMode(swButtonPin, INPUT_PULLUP);
}

void loop() {

  xValue = analogRead(xAxisPin);
  yValue = analogRead(yAxisPin);
  reading = digitalRead(swButtonPin);
  showDisplay();

  if (reading != lastButtonState)
    lastDebounceTime = millis();

  if (millis() - lastDebounceTime > debounceDelay) {

    if (reading != buttonState)
      buttonState = reading;

    if (buttonState == LOW) {
      if (lockedOnDigit == false)
        lockedOnDigit = true;
      else if (lockedOnValue == false)
        lockedOnValue = true;
      else
      {
        // reset all locking
        lockedOnDigit = false;
        lockedOnValue = false;
      }
    }
  }
  lastButtonState = reading;

  if (lockedOnDigit == false) {
    if (xValue > maxTreshold && joyXMoved == false) {
      pointingDigit[currentDigit] = 0;
      currentDigit = (currentDigit + 1) % 4;
      pointingDigit[currentDigit] = 1;
      joyXMoved = true;
    }
    if (xValue < minTreshold && joyXMoved == false) {
      pointingDigit[currentDigit] = 0;
      currentDigit = (currentDigit - 1 + 4) % 4;
      pointingDigit[currentDigit] = 1;
      joyXMoved = true;
    }
    if (xValue > minTreshold && xValue < maxTreshold) {
      joyXMoved = false;
    }
  }
  if (lockedOnValue == false && lockedOnDigit == true) {

    if (yValue > maxTreshold && joyYMoved == false) {
      if (actualNumbers[currentDigit] == -1)
        actualNumbers[currentDigit] = 9;
      else
        actualNumbers[currentDigit] = (actualNumbers[currentDigit] - 1 + 10) % 10;
      joyYMoved = true;
    }
    if (yValue < minTreshold && joyYMoved == false) {
      actualNumbers[currentDigit] = (actualNumbers[currentDigit] + 1) % 10;
      joyYMoved = true;
    }
    if (yValue > minTreshold && yValue < maxTreshold) {
      joyYMoved = false;
    }
  }
}

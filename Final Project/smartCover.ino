#include "menu.h"

void setup() {

  Serial.begin(115200);
  mySerial.begin(9600);
  myMP3.begin(mySerial);
  myMP3.volume(voiceVolume);
  myMP3.pause();

  for (int i = 0; i < nrOfSensors; i++)
    pinMode(pressureSensorsPins[i], INPUT);

  pinMode(doutPin, INPUT);
  pinMode(aoutPin, INPUT);
  pinMode(ledPin, OUTPUT);

  lcd.InitLCD(LANDSCAPE);
  touch.InitTouch(LANDSCAPE);
  touch.setPrecision(PREC_HI);

  myButtons.setSymbolFont(Dingbats1_XL);
  myButtons.setTextFont(BigFont);

  lcd.fillScr(backColor);
  drawSignature();
  drawModel();
  welcomeScreen();
  initializeButtons();
}

void loop() {
  if (!_welcomeScreen) {
    drawMenus();
    if (touch.dataAvailable() == true)
    {
      pressedButton = myButtons.checkButtons();
      manageMenus(pressedButton);
    }
  }
  else if (millis() - lastTime[0] > times[0]) {
    _welcomeScreen = false;
  }
  manageBattery();
}

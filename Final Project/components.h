#ifndef COMPONENTS_H
#define COMPONENTS_S

#include <UTFT.h>
#include <URTouch.h>
#include <UTFT_Buttons.h>
#include <SoftwareSerial.h>
#include <DFPlayerMini_Fast.h>
#include "colors.h"

UTFT lcd(ILI9486 , 38, 39, 40, 41);
URTouch  touch( 52, 48, 51, 50, 49);
UTFT_Buttons myButtons(&lcd, &touch);

SoftwareSerial mySerial(10, 11); // RX, TX
DFPlayerMini_Fast myMP3;

//Common Variables
const int ledPin = 7;
int transmission = 0;// 0-manual; 1-automatic
uint16_t backColor = Black; //Pre-established background color - can change in settings
int voiceVolume = 25;
int voiceGender = 2; //Male;

//Some extern functions and variables definition
extern unsigned long long lastTime[];
extern unsigned long long times[];
extern int currentMenu;
void changeMenu(int);
void resetVariables();

bool engineStarted = false; //engine

//MQ3 - alcohol sensor variables
const int doutPin = 8;
const int aoutPin = A0;
int mq3Value;
int limit;
bool measuringMQ3 = false;
bool drunk = false;

//Function to measure the alcohol vapors in the air for 5 seconds 
// when start engine button has ben pressed
void manageBreathalyser() {
  if (measuringMQ3) {
    if (millis() - lastTime[3] < times[3]) {
      mq3Value = analogRead(aoutPin);
      limit = digitalRead(doutPin);
      if (limit == LOW) {
        drunk = true;
        digitalWrite(ledPin, HIGH);
      }
    }
    else {
      lastTime[4] = millis();
      if (drunk == true) {
        changeMenu(8);
      }
      else {
        changeMenu(9);
      }
    }
  }
}

//Function to handle what message appear on the screen
//depending on what decision alcohol sensor has made
void manageMQ3ScreenTime() {
  if (millis() - lastTime[4] > times[4]) {
    if (currentMenu == 8) {
      digitalWrite(ledPin, LOW);
      resetVariables();
      changeMenu(0);
    }
    else if (currentMenu == 9) {
      myMP3.play(voiceGender);
      myMP3.startRepeat();
      engineStarted = true;
      digitalWrite(ledPin, HIGH);
      changeMenu(5);
    }
  }
}


void printMQ3Value() {
  if (millis() - lastTime[5] > times[5]) {
    lcd.printNumI(mq3Value, 285, 180);
    lastTime[5] = millis();
  }
}


//Force sensitive resistors (pressure sensors) variables
const int pressureSensorsPins[4] { A1, A2, A3, A4 };
bool fsrTouched[] {false, false, false, false};
int sensorsValues[4];
const int nrOfSensors  = 4;
int tHold = 70;  // sensitivity
bool shiftingGear = false;


void readSensors() {
  for (int i = 0; i < nrOfSensors; i++) {
    sensorsValues[i] = analogRead(pressureSensorsPins[i]);
    if (sensorsValues[i] > tHold)
      fsrTouched[i] = true;
    else
      fsrTouched[i] = false;
  }
}

bool bothHands() {
  readSensors();
  int nr = 0;
  for (int i = 0; i < nrOfSensors; i++) {
    if (fsrTouched[i])
      nr++;
  }
  if (nr >= 2)
    return true;
  return false;
}

//Function that handles the warning protocol and the transmission two scenarios
// when the driver takes his hands off the steering wheel
void manageHands() {
  if (engineStarted) {
    bool _bothHands = bothHands();
    if (transmission == 0) { // Manual
      if (!_bothHands) {
        if (!shiftingGear and currentMenu == 6) {
          changeMenu(7);
          shiftingGear = true;
          lastTime[6] = millis();
        }
        else if (shiftingGear and currentMenu == 7) {
          if (millis() - lastTime[6] > times[6]) {
            digitalWrite(ledPin, HIGH);
            myMP3.play(voiceGender);
            myMP3.startRepeat();
            changeMenu(5);
            shiftingGear = false;
          }
        }
      }
      else {
        if (!shiftingGear and currentMenu == 5) {
          myMP3.stopRepeat();
          myMP3.pause();
          changeMenu(6);
          digitalWrite(ledPin, LOW);
        }
        else if (shiftingGear and currentMenu == 7 ) {
          changeMenu(6);
          shiftingGear = false;
        }
      }
    }
    else if (transmission == 1) { //Automatic
      if (!_bothHands) {
        if (currentMenu == 6) {
          myMP3.play(voiceGender);
          myMP3.startRepeat();
          changeMenu(5);
          digitalWrite(ledPin, HIGH);
        }
      }
      else if (currentMenu == 5) {
        myMP3.pause();
        myMP3.stopRepeat();
        changeMenu(6);
        digitalWrite(ledPin, LOW);
      }
    }
  }
}

//When getting back to main menu
// some variables need to be resetted
void resetVariables() {
  measuringMQ3 = false;
  drunk = false;
  engineStarted = false;
  shiftingGear = false;
}

#endif

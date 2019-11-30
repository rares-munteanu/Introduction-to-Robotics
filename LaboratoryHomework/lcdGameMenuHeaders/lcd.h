#ifndef LCD
#define LCD

#include <LiquidCrystal.h>

const byte rsPin = 12;
const byte ePin = 11;
const byte d4Pin = 5;
const byte d5Pin = 4;
const byte d6Pin = 3;
const byte d7Pin = 2;
const byte contrastPin = 10;
const unsigned constrastValue = 145;
LiquidCrystal lcd(rsPin, ePin, d4Pin, d5Pin, d6Pin, d7Pin);


#endif LCD

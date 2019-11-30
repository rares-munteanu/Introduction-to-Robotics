#ifndef EPROM_HIGHSCORE
#define EPROM_HIGHSCORE

#include <EEPROM.h>
int addr = 0; //write and read from address 0
byte value;
bool highScoreReaded = false;
//Menu setup
char startName[] = "Player";
unsigned highScore = 0;

void getHighScore() {
  if (!highScoreReaded) {
    highScoreReaded = true;
    highScore = EEPROM.read(addr);
  }
}

void writeHighScore() {
  EEPROM.write(addr, highScore);
}

void clearEEPROM() {
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
}

#endif EPROM_HIGHSCORE

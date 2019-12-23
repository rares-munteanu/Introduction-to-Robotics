#ifndef EEPROM_READ_h
#define EEPROM_READ_h
#include "EEPROM_writeAnything.h"

void clearEEPROM() {
  for (int i = 0; i < EEPROM.length(); i++)
    EEPROM.update(i, 0);
}

//Read last 3 Names and highScores
void readNamesAndScores() {
  int add = 0;
  EEPROM_read(0, highScoreNames[0]);
  add += strlen(highScoreNames[0]) + 1;
  EEPROM_read(add, highScores[0]);
  add += sizeof(unsigned);
  EEPROM_read(add, highScoreNames[1]);
  add += strlen(highScoreNames[1]) + 1;
  EEPROM_read(add, highScores[1]);
  add += sizeof(unsigned);
  EEPROM_read(add, highScoreNames[2]);
  add += strlen(highScoreNames[2]) + 1;
  EEPROM_read(add, highScores[2]);
  add += sizeof(unsigned);
};

void writeNamesAndScores() {
  int add = 0;
  EEPROM_write(0, highScoreNames[0]);
  add += strlen(highScoreNames[0]) + 1;
  EEPROM_write(add, highScores[0]);
  add += sizeof(unsigned);
  EEPROM_write(add, highScoreNames[1]);
  add += strlen(highScoreNames[1]) + 1;
  EEPROM_write(add, highScores[1]);
  add += sizeof(unsigned);
  EEPROM_write(add, highScoreNames[2]);
  add += strlen(highScoreNames[2]) + 1;
  EEPROM_write(add, highScores[2]);
  add += sizeof(unsigned);
}

#endif

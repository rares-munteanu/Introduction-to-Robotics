#ifndef EEPROM_READ_h
#define EEPROM_READ_h

void readNamesFromEeprom() {
  unsigned add;
  add = EEPROM_readAnything(0, highScoreNames[0]);
  add++;
  add = EEPROM_readAnything(add, highScores[0]);
  add++;
  add = EEPROM_readAnything(add, highScoreNames[1]);
  add++;
  add = EEPROM_readAnything(add, highScores[1]);
  add++;
  add = EEPROM_readAnything(add, highScoreNames[2]);
  add++;
  EEPROM_readAnything(add, highScores[2]);
};

void writeScoresToEeprom() {
  unsigned add;
  add = EEPROM_writeAnything(0, highScoreNames[0]);
  add++;
  add = EEPROM_writeAnything(add, highScores[0]);
  add++;
  add = EEPROM_writeAnything(add, highScoreNames[1]);
  add++;
  add = EEPROM_writeAnything(add, highScores[1]);
  add++;
  add = EEPROM_writeAnything(add, highScoreNames[2]);
  add++;
  EEPROM_writeAnything(add, highScores[2]);
}

#endif

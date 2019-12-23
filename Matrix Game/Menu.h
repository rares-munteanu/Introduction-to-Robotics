#ifndef MENU_H
#define MENU_H
#include <LiquidCrystal_I2C.h>
#include "CommonVariables.h"
#include "PROGMEM_readAnything.h"
#include "Joystick.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
joystick joy(A0, A1, A2, 350, 750, false);

char buffer[30]; //A temporary for reading menus titles from PROGMEM
const char cursor = 0x7E;
const char leftArrow = 0x7F;
const char rightArrow = 0x7E;

bool isMenu[] {false, false, false, false, false, false, false, false, false, false, false, false, false, false}; //Used to check if currentMenu is already displayed
const bool showCursor[] PROGMEM {true, false, false, true, false, false, false, false, false, false, false, false, false, false};
bool displayed[] {false, false, false}; // For cursor, name and startingLevel

byte letterPos = 0; //For checking current position in alphabet when changing the player nickname
unsigned long long lastBlink [] {0, 0};   //  ↓
unsigned blinkInterval[] {200, 300};    // For blinking letters from alphabet and starting level when the player wants to modify them
bool blinked[] {false, false};        //      ↑
bool startBlinking[] {false, false}; //       ↑

bool gameInfoUpdated = false;       //  Used to update score level and lives during gameplay
bool endGameInfoUpdated = false;   //   Used to update score level and lives after game has finished

byte currentPos = 0;   //Cursor position
byte currentMenu = 0;
byte startingLevel = 1;

char playerName[11] = {"Player"};
char highScoreNames[3][11] = {"", "", ""};
unsigned highScores[3] = {0, 0, 0};

const byte menusLength[] {4, 3, 3, 2, 3, 4, 2, 2, 2, 1, 1, 2, 2, 3};

const char menusInfo[][4][30] PROGMEM {
  {"Start", "HScore", "Settings", "Info"},
  {"Lives:", "Level:", "Score:"},
  {"Name", "Score", "->"},
  {"Name:", "Starting Lvl:"},
  {"ReverseIt, by", "Rares Munteanu", "->"},
  {"github.com/", "rares-munteanu", "<-" , "->"},
  { "@UnibucRobotics", "<-"},
  {"abcdefghijklmnop", "qrstuvwxyz"},
  {"ABCDEFGHIJKLMNOP", "QRSTUVWXYZ"},
  {"<-"},//Used for displayHighScore function to have a second case for switch
  {"Game Over!"},
  {"You made it", "to HighScore!"},
  {"Congrats, You", "won the game!!"},
  {"Name:", "Lvl:", "Score:"}
};

//Poisiton of menus printing (where to set the cursor)
const byte menusPos[][4][2] PROGMEM {
  {
    {1, 0},
    {8, 0}, //MainMenu
    {1, 1},
    {11, 1}
  },
  {
    {0, 0}, //Start Game Menu
    {8, 0},
    {0, 1}
  },
  {
    {2, 0}, //HScore Menu
    {11, 0},
    {15, 1}
  },
  {
    {1, 0},//Settings Menu
    {1, 1}
  },
  {
    {0, 0},
    {0, 1}, //Info Menu 1
    {15, 1}
  },
  {
    {2, 0},
    {0, 1}, //Info Menu 2
    {0, 0},
    {15, 1}
  },
  {
    {0, 1}, //Info Menu 3
    {7, 0}
  },
  {
    {0, 0}, //Alphabet
    {0, 1}
  },
  {
    {0, 0}, //↑
    {0, 1}
  },
  {
    {0, 0} //HScore second Screen
  },
  {
    {0, 0}, //Game over
    {0, 1}
  },
  {
    {0, 0}, //Made it to highScore
    {0, 1}
  },
  {
    {0, 0}, //Won the game
    {0, 1}
  },
  {
    {0, 0}, //Game information after gameplay
    {0, 1},
    {6, 1}
  },
};

//Cursor position where it's case ( used it only in settings menu and main menu )
const byte cursorPosition[][5][2] PROGMEM{
  {
    {0, 0},
    {7, 0}, //MainMenu
    {0, 1},
    {10, 1}
  },
  {
    //No cursor on Start Game Menu
  },
  {
    //No cursor on HScore Menu
  },
  { //Settings Menu
    {0, 0},
    {0, 1}
  },
  {
    //No cursor on Change Name Menu
  }
};

//Erease cursor from screen
void clearCurrentPos() {
  if (PROGMEM_get(&showCursor[currentMenu])) {
    lcd.setCursor(PROGMEM_get(&cursorPosition[currentMenu][currentPos][0]), PROGMEM_get(&cursorPosition[currentMenu][currentPos][1]));
    lcd.print(F(" "));
  }
}

//Display cursor
void displayCurrentPos() {
  if (PROGMEM_get(&showCursor[currentMenu])) {
    lcd.setCursor(PROGMEM_get(&cursorPosition[currentMenu][currentPos][0]), PROGMEM_get(&cursorPosition[currentMenu][currentPos][1]));
    lcd.print(cursor);
    displayed[0] = true;
  }
}

void displayPlayerName() {
  if (currentMenu == 3) {
    lcd.setCursor(6, 0);
    lcd.print(playerName);
    displayed[1] = true;
  }
}

void displayStartingLevel() {
  if (currentMenu == 3) {
    lcd.setCursor(14, 1);
    lcd.print(startingLevel);
    displayed[2] = true;
  }
}

//Display highScore when the player is in highScore Menu
void displayHScore() {
  switch (currentMenu) {
    case 2: {
        lcd.setCursor(0, 1);
        lcd.print(highScoreNames[0]);
        lcd.setCursor(11, 1);
        lcd.print(highScores[0]);
        break;
      }
    case 9: {
        lcd.setCursor(1, 0);
        lcd.print(highScoreNames[1]);
        lcd.setCursor(12, 0);
        lcd.print(highScores[1]);
        lcd.setCursor(1, 1);
        lcd.print(highScoreNames[2]);
        lcd.setCursor(12, 1);
        lcd.print(highScores[2]);
        break;
      }
  }
}

//Update score level and lives during gameplay
void updateGameInfo() {
  if (currentMenu == 1 and gameStarted) {
    lcd.setCursor(6, 0);
    lcd.print(lives);
    lcd.setCursor(14, 0);
    lcd.print(level);
    lcd.setCursor(6, 1);
    lcd.print(score);
    gameInfoUpdated = true;
  }
}

//Update score level and lives during gameplay
void endGameInfo() {
  if (currentMenu == 13 and gameStarted == false) {
    lcd.setCursor(5, 0);
    lcd.print(playerName);
    lcd.setCursor(4, 1);
    lcd.print(level);
    lcd.setCursor(12, 1);
    lcd.print(score);
    endGameInfoUpdated = true;
  }
}

//Function to display the currentMenu information from menusInfo and update some menu information if it's the case
void displayMenu() {
  if (!isMenu[currentMenu]) {
    lcd.clear();
    for (int i = 0; i < menusLength[currentMenu]; i++) {
      lcd.setCursor(PROGMEM_get(&menusPos[currentMenu][i][0]), PROGMEM_get(&menusPos[currentMenu][i][1]));
      PROGMEM_read(&menusInfo[currentMenu][i], buffer);
      if (strcmp(buffer, "->") == 0)
        lcd.print(rightArrow);
      else {
        if (strcmp(buffer, "<-") == 0)
          lcd.print(leftArrow);
        else
          lcd.print(buffer);
      }
    }
    isMenu[currentMenu] = true;
    displayHScore();
  }
  if (!displayed[0])
    displayCurrentPos();
  if (!displayed[1])
    displayPlayerName();
  if (!displayed[2])
    displayStartingLevel();
  if (!gameInfoUpdated)
    updateGameInfo();
  if (!endGameInfoUpdated)
    endGameInfo();
}

void restoreLetter() {
  lcd.setCursor(letterPos - 16 * (letterPos >= 16), (letterPos >= 16));
  lcd.print(PROGMEM_get(&menusInfo[currentMenu][letterPos >= 16][letterPos - 16 * (letterPos >= 16)]));
}

void blinkLetter() {
  if (millis() - lastBlink[0] > blinkInterval[0]) {
    if (blinked[0] == true) //Is empty space
      restoreLetter();
    else { //Letter is Printed
      lcd.setCursor(letterPos - 16 * (letterPos >= 16), (letterPos >= 16));
      lcd.print(F(" "));
    }
    lastBlink[0] = millis();
    blinked[0] = !blinked[0];
  }
}

void restoreStartingLevel() {
  lcd.setCursor(14, 1);
  lcd.print(startingLevel);
}

void blinkStartingLevel() {
  if (millis() - lastBlink[1] > blinkInterval[1]) {
    if (blinked[1] == true)
      restoreStartingLevel();
    else {
      lcd.setCursor(14, 1);
      lcd.print(F("  "));
    }
    lastBlink[1] = millis();
    blinked[1] = !blinked[1];
  }
}

void changeMenu(byte whatMenu) {
  isMenu[currentMenu] = false;
  currentPos = 0;
  currentMenu = whatMenu;
  displayed[0] = false;
}

byte whatMove() {
  if (joy.movedUp())
    return 1;
  if (joy.movedDown())
    return 2;
  if (joy.movedRight())
    return 3;
  if (joy.movedLeft())
    return 4;
  if (joy.buttonPressed())
    return 5;
  return 0;
}

//Based on whatMove player does this function update the menu consequently
void updateMenu() {
  const byte joyMove = whatMove();
  switch (joyMove) {
    case 1: { //Moved Up , commonly used to exit sub menus
        switch (currentMenu) {
          case 1: {
              changeMenu(0);
              break;
            }
          case 2: {
              changeMenu(0);
              break;
            }
          case 3: {
              if (startBlinking[1]) {
                if (startingLevel < 10)
                  startingLevel ++;
              }
              else
                changeMenu(0);
              break;
            }
          case 4: {
              changeMenu(0);
              break;
            }
          case 7: case 8: {
              startBlinking[0] = false;
              letterPos = 0;
              displayed[1] = false;
              displayed[2] = false;
              if (strlen(playerName) == 0)
                strcpy(playerName, "Player");
              changeMenu(3);
              break;
            }
        }
        break;
      }
    case 2: { //MovedDown, Used for changing alphabet to uppercase and modify starting level value
        switch (currentMenu) {
          case 3: {
              if (startBlinking[1])
                if (startingLevel > 1)
                  startingLevel--;
              break;
            }
          case 7: {
              restoreLetter();
              changeMenu(8);
              break;
            }
          case 8: {
              restoreLetter();
              changeMenu(7);
              break;
            }
        }
        break;
      }
    case 3: { //MovedRight, used for changing the cursor position or changing info and highscore menus or going through alphabet letters when changing the name
        if (PROGMEM_get(&showCursor[currentMenu])) {
          if (!startBlinking[1]) {
            clearCurrentPos();
            currentPos = (currentPos + 1) % menusLength[currentMenu];
            displayed[0] = false;
          }
        }
        else {
          switch (currentMenu) {
            case 2: {
                changeMenu(9);
                displayHScore();
                break;
              }
            case 4: {
                changeMenu(5);
                break;
              }
            case 5: {
                changeMenu(6);
                break;
              }
            case 7: case 8: {
                restoreLetter();
                letterPos = (letterPos + 1) % 26;
                break;
              }
          }
        }
        break;
      }
    case 4: { //MovedLeft, used for changing the cursor position or changing info and highscore menus or going through alphabet letters when changing the name
        if (PROGMEM_get(&showCursor[currentMenu])) {
          if (!startBlinking[1]) {
            clearCurrentPos();
            currentPos = (currentPos - 1 + menusLength[currentMenu]) % menusLength[currentMenu];
            displayed[0] = false;
          }
        }
        else {
          switch (currentMenu) {
            case 5: {
                changeMenu(4);
                break;
              }
            case 6: {
                changeMenu(5);
                break;
              }
            case 7: case 8: {
                restoreLetter();
                letterPos = (letterPos - 1 + 26) % 26;
                break;
              }
            case 9: {
                changeMenu(2);
                displayHScore();
                break;
              }
          }
        }
        break;
      }
    case 5: { //Joystick button is pressed, used to change menus commonly, or setting up name and starting level
        switch (currentMenu) {
          case 0: {
              switch (currentPos) {
                case 0 : {
                    animationStatus[2] = true;
                    animationStatus[1] = false;
                    level = startingLevel;
                    score = 0;
                    lives = 3;
                    goodMoves = 0;
                    gameUpdateIntervals[0] = 3200 - 280 * startingLevel;
                    gameUpdateIntervals[1] = 400 - 35 * startingLevel;
                    playerMove_ = 1;
                    break;
                  }
                case 1: {
                    changeMenu(2);
                    displayHScore();
                    break;
                  }
                case 2: {
                    displayed[1] = false;
                    displayed[2] = false;
                    changeMenu(3);
                    break;
                  }
                case 3: {
                    changeMenu(4);
                    break;
                  }
              }
              break;
            }
          case 3: {
              switch (currentPos) {
                case 0: {
                    changeMenu(7);
                    startBlinking[0] = true;
                    strcpy(playerName, "");
                    break;
                  }
                case 1: {
                    restoreStartingLevel();
                    startBlinking[1] = !startBlinking[1];
                    break;
                  }
              }
              break;
            }
          case 7: case 8: {
              if (strlen(playerName) <= 10) {
                char ch;
                PROGMEM_read(&menusInfo[currentMenu][letterPos >= 16][letterPos - 16 * (letterPos >= 16)], ch);
                strncat(playerName, &ch, 1);
              }
              break;
            }
          case 10: case 11: case 12: {
              changeMenu(13);
              endGameInfoUpdated = false;
              break;
            }
          case 13: {
              changeMenu(0);
              break;
            }
        }
        break;
      }
  }
}

void welcomeScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hello everybody!");
  lcd.setCursor(0, 1);
  lcd.print("Happy Holidays!");
}
bool wScreen = true;
unsigned welcomeScreenInterval = 5000;

#endif

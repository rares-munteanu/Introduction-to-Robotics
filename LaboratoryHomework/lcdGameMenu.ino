#include "joystick.h"
#include "lcd.h"
#include "epromHighScore.h"

bool mainMenu = true;
bool startGameMenu = false;
bool highScoreMenu = false;
bool settingsMenu = false;
bool endedGameMenu = false;


bool changingName = false;
bool changingStartingLevel = false;

unsigned currentNamePos = 0;
unsigned blinkingInterval = 400;
unsigned long lastBlinking = 0;
unsigned long currentBlinking = 0;
char letterBackup;
bool isLetter = true;

bool isMainMenu = false;
bool isStartGameMenu = false;
bool isHighScoreMenu = false;
bool isSettingsMenu = false;
bool isEndedGameMenu = false;

const char currentPos[] = ">";
int cursorColPos = 0;
int cursorRowPos = 0;

unsigned startingLevelValue = 1;
unsigned levelValue = startingLevelValue;

char playerName[50] = "player";


bool playingGame = false;
unsigned long currentTime = 0;
unsigned long lastTime = 0;
unsigned long currentGameTime = 0;// used with lastGameTime
unsigned long lastGameTime = 0; //used for ending the game after 10 seconds
double getSeconds(unsigned long currentTime) {
  return currentTime / 1000.0;
}


void resetDisplayedMenu() {
  isMainMenu = false;
  isStartGameMenu = false;
  isHighScoreMenu = false;
  isSettingsMenu = false;
  isEndedGameMenu = false;
}


void displayEndedGameMenu() {
  lcd.clear();
  lcd.print("CongratsGameOver");
  lcd.setCursor(0, 1);
  lcd.print("PressBtn to exit");
  resetDisplayedMenu();
  isEndedGameMenu = true;
}

void displayCurrentPos() {
  lcd.setCursor(cursorColPos, cursorRowPos);
  lcd.print(currentPos);
}

void displayMainMenu() {
  lcd.clear();
  lcd.print(" Start");
  lcd.print(" HScore ");
  lcd.setCursor(4, 1);
  lcd.print("Settings");
  displayCurrentPos();
  resetDisplayedMenu();
  isMainMenu = true;
}

void displayStartGameMenu() {
  lcd.clear();
  lcd.print("Lives:3 ");
  lcd.print("Lvl:");
  lcd.print(levelValue);
  lcd.setCursor(0, 4);
  lcd.print("Score:");
  lcd.print(3 * levelValue);
  isStartGameMenu = true;
}

void displayHSMenu() {
  lcd.clear();
  lcd.print("HighScore: ");
  lcd.print(highScore);
  lcd.setCursor(0, 1);
  lcd.print("PressBtn to exit");
  resetDisplayedMenu();
  isHighScoreMenu = true;
}

void displaySettingsMenu() {
  lcd.clear();
  lcd.print(" Name:");
  lcd.print(playerName);
  lcd.setCursor(0, 1);
  lcd.print(" Starting Lvl:");
  lcd.print(startingLevelValue);
  resetDisplayedMenu();
  isSettingsMenu = true;
  displayCurrentPos();
}



void displayMenu() {
  lcd.setCursor(0, 0);
  if (mainMenu and !isMainMenu)
    displayMainMenu();
  else if (startGameMenu and !isStartGameMenu)
    displayStartGameMenu();
  else  if (highScoreMenu and !isHighScoreMenu)
    displayHSMenu();
  else  if (settingsMenu and !isSettingsMenu)
    displaySettingsMenu();
  else if (endedGameMenu and !isEndedGameMenu)
    displayEndedGameMenu();
}

void setup() {
  //LCD setup
  lcd.begin(16, 2);
  pinMode(contrastPin, OUTPUT);
  analogWrite(contrastPin, constrastValue);

  //Joystick setup

  pinMode(xAxisPin, INPUT);
  pinMode(yAxisPin, INPUT);
  pinMode(swButtonPin, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  getHighScore();
  displayMenu();
  readJoystick();
  if (movedRight()) {
    if (mainMenu) {
      if (cursorRowPos == 0) {
        if (cursorColPos == 0) {
          cursorColPos = 6;
          isMainMenu = false;
        }
        else if (cursorColPos == 6) {
          cursorRowPos = 1;
          cursorColPos = 3;
          isMainMenu = false;
        }
      }
      else  {
        cursorRowPos = 0;
        cursorColPos = 0;
        isMainMenu = false;
      }
    }
    if (settingsMenu) {
      if (cursorRowPos == 0  and !changingName and !changingStartingLevel) {
        cursorRowPos = 1;
        isSettingsMenu = false;
      }
      else if (changingName) {
        if (!isLetter) {
          playerName[currentNamePos] = letterBackup;
          isLetter = true;
        }
        currentNamePos = (currentNamePos + 1) % strlen(playerName);
      }
    }
  }
  if (movedLeft()) {
    if (mainMenu) {
      if (cursorRowPos == 0) {
        if (cursorColPos == 0) {
          cursorRowPos = 1;
          cursorColPos = 3;
          isMainMenu = false;
        }
        else if (cursorColPos == 6) {
          cursorColPos = 0;
          isMainMenu = false;
        }
      }
      else {
        cursorRowPos = 0;
        cursorColPos = 6;
        isMainMenu = false;
      }
    }
    if (settingsMenu) {
      if (cursorRowPos == 1 and !changingName and !changingStartingLevel) {
        cursorRowPos = 0;
        isSettingsMenu = false;
      }
      else if (changingName) {
        if (!isLetter) {
          playerName[currentNamePos] = letterBackup;
          isLetter = true;
        }
        currentNamePos = (currentNamePos - 1 + strlen(playerName)) % strlen(playerName);
      }
      else if (!changingName and !changingStartingLevel) {
        settingsMenu = false;
        mainMenu = true;
        cursorRowPos = 1;
        cursorColPos = 3;
      }
    }
  }
  if (movedUp()) {
    if (settingsMenu) {
      if (changingName) {
        if (!isLetter) {
          playerName[currentNamePos] = letterBackup;
          isLetter = true;
        }
        if (playerName[currentNamePos] == 'a')
          playerName[currentNamePos] = 'z';
        else
          playerName[currentNamePos] -= 1;
      }
      else if (changingStartingLevel) {
        startingLevelValue = (startingLevelValue + 1) % 16 ;
        isSettingsMenu = false;
      }
    }
  }

  if (movedDown()) {
    if (settingsMenu) {
      if (changingName) {
        if (!isLetter) {
          playerName[currentNamePos] = letterBackup;
          isLetter = true;
        }
        if (playerName[currentNamePos] == 'z')
          playerName[currentNamePos] = 'a';
        else
          playerName[currentNamePos] += 1;
      }
      else if (changingStartingLevel) {
        startingLevelValue = (startingLevelValue - 1 + 16) % 16 ;
        isSettingsMenu = false;
      }
    }
  }

  if (buttonPressed()) {
    if (mainMenu) {
      if (cursorRowPos == 0 and cursorColPos == 0) {
        levelValue = startingLevelValue;
        mainMenu = false;
        startGameMenu = true;
        playingGame = true;
      }
      if (cursorRowPos == 0 and cursorColPos == 6) {
        mainMenu = false;
        highScoreMenu = true;
      }
      if (cursorRowPos == 1 and cursorColPos == 3) {
        mainMenu = false;
        settingsMenu = true;
        cursorRowPos = 0;
        cursorColPos = 0;
      }
    }
    else if (highScoreMenu) {
      highScoreMenu = false;
      mainMenu = true;
    }
    else if (settingsMenu) {
      if (cursorRowPos == 0 and !changingName) {
        changingName = true;
      }
      else if (changingName) {
        if (!isLetter) {
          playerName[currentNamePos] = letterBackup;
          isLetter = true;
        }
        changingName = false;
        isSettingsMenu = false;
      }
      else if (cursorRowPos == 1 and !changingStartingLevel) {
        changingStartingLevel = true;
      }
      else if (changingStartingLevel) {
        changingStartingLevel = false;
      }
    }
    else if (endedGameMenu) {
      resetDisplayedMenu();
      endedGameMenu = false;
      mainMenu = true;
    }
  }
  if (changingName) {
    currentBlinking = millis();
    if (currentBlinking - lastBlinking > blinkingInterval) {
      if (isLetter == true) {
        letterBackup = playerName[currentNamePos];
        playerName[currentNamePos] = ' ';
        isLetter = false;
      }
      else {
        playerName[currentNamePos] = letterBackup;
        isLetter = true;
      }
      lastBlinking = currentBlinking;
      isSettingsMenu = false;
    }
  }
  if (playingGame) {
    currentTime = millis();
    if (getSeconds(currentTime - lastTime) > 5) {
      levelValue += 1;
      lastTime = currentTime = millis();
      isStartGameMenu = false;
    }

    currentGameTime = millis();
    if (getSeconds(currentGameTime - lastGameTime) > 10.5) { // ending the game after 10.5 seconds in order to see the score changing after 10 seconds 
      if (highScore < 3 * levelValue) {
        highScore = 3 * levelValue;
        highScoreReaded = false;
        writeHighScore();
      }

      playingGame = false;
      lastGameTime = currentGameTime = millis();
      resetDisplayedMenu();
      startGameMenu = false;
      endedGameMenu = true;
    }
  }
  else {
    currentTime = lastTime = millis();
    currentGameTime = lastGameTime = millis();
  }
}

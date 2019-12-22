#include "Button.h"
#include "Game.h"
#include "EEPROM_writeAnything.h"
#include <SoftwareSerial.h>
#include <DFPlayerMini_Fast.h>

SoftwareSerial mySerial(6, 5); // RX, TX
DFPlayerMini_Fast myMP3;

button volume(4, 100);
button playPause(3, 100);
button nextSong(2, 100);
unsigned currentVolume = 20;
bool paused = true;

void manageDfPlayer() {
  if (volume.isPressed()) {
    myMP3.volume(30 - currentVolume);
    currentVolume = 30 - currentVolume;
  }
  if (playPause.isPressed()) {
    if (paused)
      myMP3.resume();
    else
      myMP3.pause();
    paused = !paused;
  }
  if (nextSong.isPressed()) {
    myMP3.playNext();
  }
}

button leftButton(8, 100);
button rightButton(9, 100);



void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  matrix.shutdown(0, false); // first driver  turned on always
  matrix.setIntensity(0, 5); // intensity : 0-15;
  matrix.clearDisplay(0); // clear display on first driver
  randomSeed(analogRead(A3));
  mySerial.begin(9600);
  myMP3.begin(mySerial);
  myMP3.play(1);
  welcomeScreen();

}

void manageAnimations() {
  if (animationStatus[1])
    trackAnimation(1);

  if (animationStatus[0])
    trackAnimation(0);

  if (animationStatus[0] and animationsOffset[0] == animationSize[0]) {
    animationStatus[0] = false;
    gameStarted = true;
    changeMenu(1);
    displayMenu();
    Serial.println("Entered");
  }
}

short int playerMove() {
  if (joy.movedUp()) return 1; // corresponding to down arrow
  if (joy.movedDown()) return 0; //corresponding to up arrow etc.
  if (joy.movedLeft()) return 2;
  if (joy.movedRight()) return 3;
  if (leftButton.isPressed()) return 5;
  if (rightButton.isPressed()) return 4;
  return -1; //For no move;
}


byte timeBar[8] {1, 1, 1, 1, 1, 1, 1, 1};
byte timeBarPos = 7;
byte randomArrow;

void displayTimeBar() {
  for (int i = 0; i < 8; i++)
    matrix.setLed(0, i, 0, timeBar[i]);
}
void resetTimeBar() {
  for (int i = 0; i < 8; i++)
    timeBar[i] = 1;
}

//byte scoresValues[]{
byte goodMoves = 0;;

void loop() {
  manageAnimations();
  manageDfPlayer();
  if (!wScreen) {
    if (!gameStarted) {
      displayMenu();
      updateMenu();
      if (startBlinking[0])
        blinkLetter();
      if (startBlinking[1])
        blinkStartingLevel();
    }
    else {
      //      Serial.println(currentMenu);
      if (millis() - lastGameUpdate[0] > gameUpdateIntervals[0] or playerMove_ != -1) { //Time to display another arrow
        if (playerMove_ == -1) {
          gameInfoUpdated = false;
          lives--;
        }
        randomArrow = random(0, 6);
        displayArrow(randomArrow);
        resetTimeBar();
        displayTimeBar();
        timeBarPos = 7;
        lastGameUpdate[0] = millis();
        lastGameUpdate[1] = millis();
      }
      if (millis() - lastGameUpdate[1] > gameUpdateIntervals[1]) {
        matrix.setLed(0, timeBarPos, 0, false);
        timeBarPos --;
        lastGameUpdate[1] = millis();
      }

      playerMove_ = playerMove();

      if (playerMove_ == randomArrow) {
        score += level * 3 + 10;
        goodMoves++;
        if (goodMoves == 10) {
          level++;
          gameUpdateIntervals[0] -= 240;
          gameUpdateIntervals[1] -= 30;
          goodMoves = 0;
        }
        gameInfoUpdated = false;
      }
      else if (playerMove_ != -1) {
        lives--;
        gameInfoUpdated = false;
      }
      if (lives == 0) {
        gameStarted = false;
        changeMenu(10);
        animationStatus[1] = true;
        if (score > highScores[0]) {
          strcpy(highScoreNames[0], playerName);
          highScores[0] = score;
        }
        else if (score > highScores[1]) {
          strcpy(highScoreNames[1], playerName);
          highScores[1] = score;
        }
        else if (score > highScores[2]) {
          strcpy(highScoreNames[2], playerName);
          highScores[2] = score;
        }
      }
      else {

      }
      if (!gameInfoUpdated)
        updateGameInfo();
      //      Serial.println(playerMove_);
      Serial.println(lives);
    }

  }
  else if (millis() > welcomeScreenInterval)
    wScreen = false;

}

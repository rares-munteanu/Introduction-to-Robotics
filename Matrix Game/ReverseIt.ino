#include "Button.h"
#include "Game.h"
#include "EEPROM_read.h"
#include <SoftwareSerial.h>
#include <DFPlayerMini_Fast.h>

//Backgound music setup
SoftwareSerial mySerial(5, 6); // RX, TX
DFPlayerMini_Fast myMP3;
button volume(4, 100);
button playPause(3, 100);
button nextSong(2, 100);
unsigned currentVolume = 7;
bool volPressed = false;
bool paused = false;

void manageDfPlayer() {
  if (volume.isPressed()) {
    if (volPressed)
      myMP3.volume(currentVolume);
    else
      myMP3.volume(15);
    volPressed = !volPressed;
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

//Gaming buttons
button leftButton(8, 100);
button rightButton(9, 100);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  matrix.shutdown(0, false);
  matrix.setIntensity(0, 10);
  matrix.clearDisplay(0);
  randomSeed(analogRead(A3));
  mySerial.begin(9600);
  myMP3.begin(mySerial);
  myMP3.play(1);
  welcomeScreen();
  myMP3.volume(5);
  readNamesAndScores(); //Read the last 3 highScores and names associated
}

//Gameplay moves
short int playerMove() {
  if (joy.movedUp()) return 1; // corresponding to down arrow
  if (joy.movedDown()) return 0; //corresponding to up arrow etc.
  if (joy.movedLeft()) return 2;
  if (joy.movedRight()) return 3;
  if (leftButton.isPressed()) return 5;
  if (rightButton.isPressed()) return 4;
  return -1; //For no move;
}

bool madeHighScore() {
  if (score > highScores[0] or score > highScores[1] or score > highScores[2])
    return true;
  return false;
}

//After gameplay has finished we check if the player made it to highScore and update EEPROM if it's the case
void manageHighScore() {
  if (score > highScores[0]) {
    strcpy(highScoreNames[2], highScoreNames[1]);
    highScores[2] = highScores[1];
    strcpy(highScoreNames[1], highScoreNames[0]);
    highScores[1] = highScores[0];
    strcpy(highScoreNames[0], playerName);
    highScores[0] = score;
  }
  else if (score > highScores[1]) {
    strcpy(highScoreNames[2], highScoreNames[1]);
    highScores[2] = highScores[1];
    strcpy(highScoreNames[1], playerName);
    highScores[1] = score;
  }
  else if (score > highScores[2]) {
    strcpy(highScoreNames[2], playerName);
    highScores[2] = score;
  }
  if (madeHighScore())
    writeNamesAndScores();
}

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
    else { //Game started
      if (millis() - lastGameUpdate[0] > gameUpdateIntervals[0] or playerMove_ != -1) { //Time to display another arrow
        if (playerMove_ == -1) { //If it's time to display another arrow and player did't react decrease one live
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
      if (millis() - lastGameUpdate[1] > gameUpdateIntervals[1]) { //Decrease the time bar
        matrix.setLed(0, timeBarPos, 0, false);
        timeBarPos --;
        lastGameUpdate[1] = millis();
      }

      playerMove_ = playerMove();
      if (playerMove_ == randomArrow) { //Player moved correctly
        score += 3 * level + 7 * timeBarPos; //update the score based on reaction time;
        goodMoves++;
        if (goodMoves == 10) {  //Completed a level
          level++;
          gameUpdateIntervals[0] -= 280; //Decrease react time
          gameUpdateIntervals[1] -= 35;
          goodMoves = 0;
        }
        gameInfoUpdated = false;
      }
      else if (playerMove_ != -1) { //Player moved wrong
        lives--;
        gameInfoUpdated = false;
      }
      if (lives <= 0) { //Player lost
        gameStarted = false;
        if (madeHighScore())
          changeMenu(11);
        else
          changeMenu(10);
        resetAnimations();
        manageHighScore();
      }
      if (level ==  11) { // Player Won the game menu
        level--;
        gameStarted = false;
        changeMenu(12);
        resetAnimations();
        manageHighScore();
      }
      if (!gameInfoUpdated)
        updateGameInfo();
    }
  }
  else if (millis() > welcomeScreenInterval)
    wScreen = false;

}

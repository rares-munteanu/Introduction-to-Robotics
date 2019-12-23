#ifndef COMMON_H
#define COMMON_H

//Variables needed both in Menu.h and Game.h

bool gameStarted = false;
unsigned score = 0;
unsigned level = 1;
int lives = 3;
byte goodMoves = 0;

const unsigned animationSize[] {43, 35, 65};
bool animationStatus[] {false, true, false};
unsigned animationsOffset[] {0, 0, 0};

unsigned long long lastTransition[] {0, 0, 0};
unsigned transitionInterval[] {20, 100, 20};


unsigned long long lastGameUpdate[] {0, 0};
unsigned gameUpdateIntervals[] {3200, 400};
int playerMove_;

#endif

#ifndef COMMON_H
#define COMMON_H

bool gameStarted = false;
//bool beginningAnimatio = false;
unsigned score = 0;
unsigned level = 1;
byte lives = 3;

const unsigned animationSize[] {43, 26, 6, 6};
bool gameStatus[] {true, true, false};
bool animationStatus[] {false, true, false};

unsigned long long lastTransition[] {0, 0, 0, 0};
unsigned transitionInterval[] {40, 100, 600, 40};
unsigned animationsOffset[] {0, 0, 0, 0};

unsigned long long lastGameUpdate[] {0, 0};
unsigned gameUpdateIntervals[] {2400, 300};
int playerMove_;


#endif

#ifndef GAME_H
#define GAME_H

#include "Menu.h"
#include <LedControl.h>

LedControl matrix(12, 11, 10, 1);

const uint64_t animations[][65] PROGMEM = {
  { //Numbers
    //3
    0x0000000000000000, 0x0080000000008000, 0x8040000000004080,
    0xc0200000800020c0, 0xe0100000c00010e0, 0x7088808060808870,
    0x3844404030404438, 0x1c2220201820221c, 0x3844404030404438,
    0x7088808060808870, 0xe0100000c00010e0, 0xc0200000800020c0,
    0x8040000000004080, 0x0080000000008000, 0x0000000000000000,
    //2
    0x0000000000000000, 0x0100000001010100, 0x0300000102020201,
    0x0700010204040403, 0x0f01020408080807, 0x1f0204081010110e,
    0x3e0408102020221c, 0x7c08102040404438, 0x3e0408102020221c,
    0x1f0204081010110e, 0x0f01020408080807, 0x0700010204040403,
    0x0300000102020201, 0x0100000001010100, 0x0000000000000000,
    //1
    0x0000000000000000, 0x8000000000008000, 0xc08080808080c080,
    0xe040404040406040, 0x7020202020203020, 0x3810101010101810,
    0x1c08080808080c08, 0x3810101010101810, 0x7020202020203020,
    0xe040404040406040, 0xc08080808080c080, 0x8000000000008000,
    0x0000000000000000
  },
  // Christmas Tree
  {
    0x0000000000000000, 0x0000000000000018, 0x0000000000002418,
    0x0000000000003c18, 0x0000000000423c18, 0x0000000000663c18,
    0x00000000007e3c18, 0x00000000187e3c18, 0x00000024187e3c18,
    0x0000003c187e3c18, 0x0000423c187e3c18, 0x0000663c187e3c18,
    0x00007e3c187e3c18, 0x00817e3c187e3c18, 0x00c37e3c187e3c18,
    0x00e77e3c187e3c18, 0x00ff7e3c187e3c18, 0x18ff7e3c187e3c18,
    0x00ff7e3c187e3c18, 0x00e77e3c187e3c18, 0x00c37e3c187e3c18,
    0x00817e3c187e3c18, 0x00007e3c187e3c18, 0x0000663c187e3c18,
    0x0000423c187e3c18, 0x0000003c187e3c18, 0x00000024187e3c18,
    0x00000000187e3c18, 0x00000000007e3c18, 0x0000000000663c18,
    0x0000000000423c18, 0x0000000000003c18, 0x0000000000002418,
    0x0000000000000018, 0x0000000000000000
  },
  //Ready?
  {
    0x0000000000000000, 0x8080808080808000, 0xc0c0c0c0c0c0c000,
    0x6060e0e06060e000, 0x30b0f0f03030f000, 0x98d878f89898f800,
    0xcc6c3c7ccccc7c00, 0x66361e3e66663e00, 0x331b0f1f33331f00,
    0x190d070f19190f00, 0x0c0603070c0c0700, 0x8683818386868300,
    0xc3c1c0c1c3c3c100, 0xe16060e06161e000, 0xf03030f03030f000,
    0xf81818f81818f800, 0xfc0c0c7c0c0cfc00, 0x7e06063e06067e00,
    0x3f03031f03033f00, 0x1f01010f01011f00, 0x0f00000700000f00,
    0x8780808380800700, 0xc3c0c0c1c0c08300, 0x616060e06060c100,
    0x303030f03030e000, 0x989898f89898f000, 0xccccccfccccc7800,
    0x6666667e66663c00, 0x3333333f33331e00, 0x1919191f19190f00,
    0x0c0c0c0f0c0c0700, 0x8686868786868300, 0xc3c3c3c3c3c3c100,
    0xe16161616161e000, 0xf03030303030f000, 0xf89898989898f800,
    0x7ccccccccccc7c00, 0x3e66666666663e00, 0x1f33333333331f00,
    0x0f19191919190f00, 0x070c0c0c0c0c0700, 0x0306060686868300,
    0x01030383c3c3c100, 0x808181c161616000, 0xc0c0c0e030303000,
    0x606060f098989800, 0x30303078cccccc00, 0x1818183c66666600,
    0x0c0c0c1e33333300, 0x0606060f19191900, 0x030303070c0c0c00,
    0x0101010306860600, 0x0000000103c38300, 0x800080800161c100,
    0xc000c0c00030e000, 0x600060e08098f000, 0x30003070c0cc7800,
    0x1800183860663c00, 0x0c000c1c30331e00, 0x0600060e18190f00,
    0x030003070c0c0700, 0x0100010306060300, 0x0000000103030100,
    0x0000000001010000, 0x0000000000000000
  },

};

//Function to display one frame of an animation using the it's current hex code
void displayImage(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      matrix.setLed(0, j, i, bitRead(row, j));
    }
  }
}

//Used for update the current animation variables 
void trackAnimation(byte whatAnimation) {
  if (animationsOffset[whatAnimation] >= animationSize[whatAnimation] ) {
    animationsOffset[whatAnimation] = 0;
  }
  uint64_t image;
  memcpy_P(&image, &animations[whatAnimation][animationsOffset[whatAnimation]], 8);
  displayImage(image);
  if (millis() - lastTransition[whatAnimation] > transitionInterval[whatAnimation]) {
    animationsOffset[whatAnimation]++;
    lastTransition[whatAnimation] = millis();
  }
}

const uint64_t arrow[] PROGMEM{
  0x383838fe7c381000, //up
  0x10387cfe38383800, //down
  0x10307efe7e301000, //right
  0x1018fcfefc181000, //left
  0x3f070f1d39712000, //down-left
  0xfce0f0b89c8e0400  //down-right
};

void displayArrow(byte whatArrow) {
  uint64_t image;
  memcpy_P(&image, &arrow[whatArrow], 8);
  displayImage(image);
}


void resetAnimations() {
  animationStatus[0] = false;
  animationStatus[1] = true;
  animationStatus[2] = false;
  animationsOffset[0] = animationsOffset[1] = animationsOffset[2] = 0;
}

void manageAnimations() {

  if (animationStatus[0])
    trackAnimation(0);

  if (animationStatus[1])
    trackAnimation(1);

  if (animationStatus[2])
    trackAnimation(2);

  if (animationStatus[2] and animationsOffset[2] == animationSize[2]) {
    animationStatus[2] = false;
    animationStatus[0] = true;
  }

  if (animationStatus[0] and animationsOffset[0] == animationSize[0]) {
    animationStatus[0] = false;
    gameStarted = true;
    changeMenu(1);
    displayMenu();
  }
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


#endif

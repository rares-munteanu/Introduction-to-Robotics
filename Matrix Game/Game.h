#ifndef GAME_H
#define GAME_H

#include "Menu.h"
#include <LedControl.h>

LedControl matrix(12, 11, 10, 1);




const uint64_t animations[][50] PROGMEM = {
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
    0xff7e3c187e3c1800, 0x7e3c187e3c180000, 0x3c187e3c18000000,
    0x187e3c1800000000, 0x7e3c180000000000, 0x3c18000000000000,
    0x1800000000000000, 0x0000000000000000,
  },
  {
    0x383838fe7c381000, 0x10387cfe38383800, 0x10307efe7e301000,
    0x1018fcfefc181000, 0x3f070f1d39712000, 0xfce0f0b89c8e0400
  }
};


void displayImage(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      matrix.setLed(0, j, i, bitRead(row, j));
    }
  }
}

void trackAnimation(byte whatAnimation) {
  
  if (animationsOffset[whatAnimation] >= animationSize[whatAnimation] ) {
    animationsOffset[whatAnimation] = 0;
  }
  uint64_t image;
  memcpy_P(&image, &animations[whatAnimation][animationsOffset[whatAnimation]], 8);
  displayImage(image);

  if (millis() - lastTransition[whatAnimation] > transitionInterval[whatAnimation]) {
    //    if (++animationsOffset[whatAnimation] >= animationSize[whatAnimation] ) {
    //      animationsOffset[whatAnimation] = 0;
    //    }
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


#endif

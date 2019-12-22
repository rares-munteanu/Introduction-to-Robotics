#ifndef BUTTON_H
#define BUTTON_H

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class button {
  public:
    button(unsigned short buttonPin, unsigned short debounceTime = 50);
    bool isPressed();
    friend void debugButton(button &a);
    friend void debug2Button(button &a);
    unsigned short getButtonPin();
  private:
    const unsigned  debounceTime;
    const unsigned short  buttonPin;
    unsigned short buttonState;
    unsigned long long lastPressTime;
};

#endif

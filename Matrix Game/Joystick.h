#ifndef JOYTSICK_H
#define JOYSTICK_H

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class joystick {
  private:
    const short xAxisPin;
    const short yAxisPin;
    const short swButtonPin;
    const unsigned minTreshold; //= 250;
    const unsigned maxTreshold; // = 750;
    short int xValue;
    short int yValue;
    short int swButtonState;
    bool joyXMoved = false;
    bool joyYMoved = false;
    bool joyMoved = false;
    bool bothAxisSameTime;
    unsigned long long lastPressTime;
    const short debounceTime = 100;

  protected:
    void readJoystick();
    void readSwButton();
  public:
    joystick(short xPin, short yPin, unsigned minTreshold, unsigned maxTreshold, bool bothAxisSameTime);
    joystick(short xPin, short yPin, short swButtonPin, unsigned minTreshold, unsigned maxTreshold, bool bothAxisSameTime);
    bool movedLeft();
    bool movedRight();
    bool movedUp();
    bool movedDown();
    bool buttonPressed();
    friend void debugJoystick(joystick &a);
    friend  void debug2Joystick(joystick &a);
};
#endif

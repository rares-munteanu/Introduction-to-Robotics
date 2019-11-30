# Laboratory Homeworks for the Introduction to Robotics Course

### First Homework 
**fileName**:analogRGBControl   
**Description**:Controlling the colors of the RGB LED by reading the value of the 3 potentiometers (rInValue, gInValue, bInValue) and mapping each one to a color: R(rOutValue), G(gOutValue), or B(bOutValue). I created setColor function inside I used map function to map the values and then function analogWrite to send them to the RGB LED.

### Second Homework 
**fileName**:knockDetector   
**Description**:Detecting a knock in the breadboard using a passive piezo buzzer; after 5 seconds starting a melody on the second piezo buzzer (the active one this time). The melody will sing continously until the push button is pressed.

### Third Homework   
**fileName**:joyStick-4Digits <br/>
**Description**:Cycling through the 4 digits of the display with x-axis of the joystick and then cycle trough the values from 0-9 with y-axis joystick. Decimal point is showing the current position. Press switch button to lock on a digit and then press again to lock completely without to be able to change the digit or the value without pressing again.

### Fourth Homework   
**fileName**:lcdGameMenu <br/>
**Dependencies**: The headers from lcdGameMenuHeaders folder <br/>
**Description**: A game menu made that help player to set the starting level of the game, to set the nickname and to view the highest score. Even if the arduino board is restarted the high score remain because it is saved in EEPROM.<br/>
**Video Link**: https://drive.google.com/file/d/1QhqoxkW4wRrj6_b1OvEgrgxO5icQtjaV/view?usp=sharing <br/
https://www.youtube.com/watch?v=qB3rA0_tDgM&feature=youtu.be

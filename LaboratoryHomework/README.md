# Laboratory Homeworks for the Introduction to Robotics Course

### First Homework 
**fileName**:analogRGBControl   
**Description**:Controlling the colors of the RGB LED by reading the value of the 3 potentiometers (rInValue, gInValue, bInValue) and mapping each one to a color: R(rOutValue), G(gOutValue), or B(bOutValue). I created setColor function inside I used map function to map the values and then function analogWrite to send them to the RGB LED.

### Second Homework
**fileName**:knockDetector   
**Description**:Detecting a knock in the breadboard using a passive piezo buzzer; after 5 seconds starting a melody on the second piezo buzzer (the active one this time). The melody will sing continously until the push button is pressed.

### Third Homework     
**fileName**:joyStick-4Digits
**Description**:Cycling through the 4 digits of the display with x-axis of the joystick and then cycle trough the values from 0-9 with y-axis joystick. Decimal point is showing the current position. Press switch button to lock on a digit and then press again to lock completely without to be able to change the digit or the value without pressing again.

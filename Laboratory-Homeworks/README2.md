# Introduction-to-Robotics

# First Homework :analogRGBControl; Description:
   I used 3 constants  rInValue (red) , gInValue (green) , bInValue (blue) to obtain the input sent by the 3 potentiometers through pins A0, A1 and A2 with analogRead function. After that, in function setColor I use map function to map the value from the input range 0-1023 to output range 0-255. With map function I obtained 3 values rOutValue (red), gOutValue (green), bOutValue (blue). Then I sent the mapped values to the rgb led through pins number 3 5 and 6 represented by constants inputPinR, inputPinG, inputPinB.

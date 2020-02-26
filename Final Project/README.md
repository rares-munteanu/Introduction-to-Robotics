# Final Project 
## Name:  ***Smart Cover*** 
### Description: 
**Smart Cover** is the final project within the 'Introduction to Robotics' course. It is mainly designed for beginner drivers to decrease the car accident rate. It is a smart steering wheel cover that sense the touch of the driver hands with the help of some force-sensing resistor so it's role is mainly to warn the driver when he is not focused on actually driving. It also has an alcohol sensor that will be connected to the turning on mechanism of the car and if it senses alcohol vapors in the air will not alow the driver to turn on the engine. 

<h2 align = "center" >Whole ensemble</h2>
<p align = "center"><img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Final%20Project/Images/12.jpeg" width="70%" height="70%"></p>

#

### Project details:
#### Components used:
 - 1 Arduino Mega
 - 1 3.5" TFT LCD
 - 4 FSR ( force-sensing resistors ) 
 - 1 speaker
 - 1 alcohol sensor
 - 1 LED
 - 1 DFPlayer mini ( small mp3 player )

| Component | Schematic |
|--|--|
| Speaker |<p align="center"><img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Final%20Project/Images/speakerConnection.jpeg" style="transform:rotate(90deg)"></p>  |
| DFPlayer mini | <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/dfPlayer.jpg" width="70%" height="70%"></p>|
| TFT LCD | <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Final%20Project/Images/lcdConnection.png" width="70%" height="70%"></p>|
| Force sensing resistor | <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Final%20Project/Images/fsr.png" width="70%" height="70%"></p>|


#

### *How it actually works:*
First of all, one of the most important tool the smart cover has is the alcohol sensor. The sensor will be connected through a relay to the turning on mechanism of the car and if it senses alcohol vapors in the air, with the help of the arduino board will send a LOW signal to the relay so the driver cannot turn on the engine and obviously cannot drive the car. Further more, if the engine has started, the system should warn the driver if he take his hands from the steering wheel. How? Through the red led and also through the speaker using pre-established voice bots. All you have to do is to configure the driver settings from the menu(more details below). There are two scenarios in this situation. If you have an automatic transmission, then, if you take one, or both of the hands from the steering wheel the warning starts immediately. On the other hand, if you select from the menu that you have a manual transmission, then the system will give you about four seconds to shift the gear before starting the warning protocol. How does the it know respect the rule? The arduino mega board is getting sample results from all of the force sensing resistors and if the values are high for 2 of the sensors then it detects the fact that the driver has both of the hands on the steering wheel.

#

### Exemplifying functionalities
| Details | Animation |
|--|--|
| <p align="center"> - Starting engine - when you press Start engine button the alcohol sensor will measure the air for 5 seconds </p> | <p align="center"><img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Final%20Project/Images/startingEngine.gif" width="80%" height="80%"> <p> |
| <p align="center">If the alcohol sensor detects alcohol in the air will send a signal to the arduino board that handles the situation (turn on red LED, send LOW signal to relay etc).</p>| <p align="center"><img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Final%20Project/Images/detectedAlcohol.gif" width="80%" height="80%"> <p> |
| <p align="center">As I said before the driver will not be allowed to turn on the car if the alcohol is sensed in the air.</p>| <p align="center"><img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Final%20Project/Images/engineTurnedOff.gif" width="80%" height="80%"> <p> |
 | <p align="center">If not alcohol is sensed by the sensor the driver is allowed to turn on the engine and the warning to place his hands on the steering wheel will appear</p>| <p align="center"><img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Final%20Project/Images/goodToGo.gif" width="80%" height="80%"> <p> |

#

### Menu details:
I built several menus on TFT LCD for the driver in order to configure the whole system. In the main menu you can find the start engine button whose functionality I have detailed above and three other menu buttons to enter. In the driver settings menu you can select the bot's voice volume, the voice gender, and the most important, what kind of transmission you have so the system will know what kind of scenario it should apply. In the display settings menu, you can change the graphical interface details like background color, and buttons template. In the info menu there are some brief information about the project. Below you can see how the menus appear.

|  <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Final%20Project/Images/menu1.jpeg"></p>  |  <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Final%20Project/Images/menu4.jpeg" width="100%" height="100%"></p>  |
|---|---|
|  <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Final%20Project/Images/menu3.jpeg"></p> | <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Final%20Project/Images/menu4.jpeg" width="100%" height="100%"></p>  | 

#
## ***Useful links*** 
### [All functionalities video](https://www.youtube.com/watch?v=lj2yGbka7MQ&feature=youtu.be)
### [BOM file Link](https://docs.google.com/spreadsheets/d/1Htry010sDG5Vxl1XxuDkIDsEU6a6pIBbHVVmY9l-o_E/edit#gid=79602340)

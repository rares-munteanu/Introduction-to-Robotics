# Final Project 
## Name:  ***Smart Cover*** 
### Description: 
**Smart Cover** is the final project within the 'Introduction to Robotics' course. It is mainly designed for beginner drivers to decrease the car accident rate. It is a smart steering wheel cover that sense the touch of the driver hands with the help of some force-sensing resistor so it's role is mainly to warn the driver when he is not focused on actually driving. It also has an alcohol sensor that will be connected to the turning on mechanism of the car and if it senses alcohol vapors in the air will not alow the driver to turn on the engine. 
### Project details:

<img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Final%20Project/Images/12.jpeg" width="70%" height="70%">

#### Components used:
 - 1 3.5" TFT LCD
 - 4 FSR ( force-sensing resistors ) 
 - 1 speaker
 - 1 alcohol sensor
 - 1 LED
 - 1 DFPlayer mini ( small mp3 player)

| Component | Schematic |
|--|--|
| Speaker |<p align="center"><img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Final%20Project/Images/speakerConnection.jpeg" style="transform:rotate(90deg)"></p>  |
| DFPlayer mini | <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/dfPlayer.jpg" width="70%" height="70%"></p>|
| MAX7219 driver | <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/matrixDriver.jpg" width="70%" height="70%"></p>|


### Animations on matrix led:
| Name and usage| Animation |
|--|--|
|Christmas Tree while you walk through the menu|  <p align="center"><img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/cTree.gif" width="50%" height="50%"> <p>|
| Start Game animation | <p align="center"><img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/startAnimation.gif" width="50%" height="50%"> <p> |
| Reaction time bar | <p align="center"><img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/timeBar.gif" width="50%" height="50%"> <p>  |

#

### *How to play:* 
There are a joystick and 2 buttons below the led matrix. Random arrows pointing in 6 different positions will appear on screen. Player have to do the exact reversed action. For example if  a pointing up arrow is respawn on the matrix led he has to swipe down with the joystick, if a pointing left-down arrow is respawn, the player has to press right button below the matrix led and so on. Sounds simple, but it is not when there is also time pressure. First row of the matrix represents how much time remained for the player to react. If the time bar dropped to zero, and the player didn't react, he will lose one life (see reaction time bar animation above).

| <p align="center"><img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/downArrow.JPG" width="100%" height="100%"> </p>| <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/upArrow.JPG" width="100%" height="100%"> </p> | <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/leftArrow.JPG" width="100%" height="100%"> </p> |
|---|---|---|
|  <p align="center">  <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/rightArrow.JPG" width="100%" height="100%"></p>|  <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/left-downArrow.JPG" width="100%" height="100%"></p> | <p align="center">  <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/right-downArrow.JPG" width="100%" height="100%"></p> |


### Menu details:
I built several menus on liquid crystal display in order to show important details about the game and make a small setup before the actual gameplay. In "***HScore***" menu you can see last 3 high scores and the names associated. Interesting fact is that every high score made is saved in EEPROM and even though the arduino is shutted down the high scores will remain the same. In "***Settings***" menu the player can change his nickname(see all functionalities video below) and he can choose from what level to start (remember that starting from higher level won't give you an advantage but on the contrary you will get to a certain level with lower score than if you would have started from level 1). In "***Info***" menu there will be displayed the game name, my name, my github link and my robotics course name from University of Bucharest.


|  <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/wScreen.JPG" width="100%" height="100%"></p>  |  <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/mainMenu.JPG" width="100%" height="100%"></p>   |  <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/highScore.JPG" width="100%" height="100%"></p>  |
|---|---|---|
|  <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/settings.JPG" width="100%" height="100%"></p> | <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/info1.JPG" width="100%" height="100%"></p>  | <p align="center"> <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/info2.JPG" width="100%" height="100%"></p>  |

### [All functionalities video](https://www.youtube.com/watch?v=ipwmN_Qqrns&feature=youtu.be)
### [BOM file Link](https://docs.google.com/spreadsheets/d/1Htry010sDG5Vxl1XxuDkIDsEU6a6pIBbHVVmY9l-o_E/edit#gid=79602340)

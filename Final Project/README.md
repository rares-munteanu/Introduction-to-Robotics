# Final Project 
## Name:  ***Smart Cover*** 
### Description: 
**Samrt Cover** is an *interactive* single player game that is challenging players *reaction time*. It is a simple but quite hard game to win. It has a total of 10 levels, each level having it's own time pressure. The player has 3 lives during the entire gameplay, in order to win the game. The *logic* of the game is inspired by the fact that brain tends to *reproduce* the movements it sees. So, a ,,good move" that brings you score in this game is to actually reverse the "instruction" displayed by the led matrix. How this game is actually played I will explain in the following.
### Project details:

<img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/firstImage.jpg" width="70%" height="70%"><img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/secondImage.jpg" width="30%" height="30%">

#### Components used:
 - 1 Liquid Crystal Display
 - 1 8x8 Matrix Led
 - 2 speakers 
 - 1 Joystick
 - 5 buttons 
 - 1 switch button
 - 1 DFPlayer mini ( small mp3 player)

| Component | Schematic |
|--|--|
| Speakers |<p align="center"><img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/speakersImage.jpg" width="70%" height="70%" style="transform:rotate(90deg)"></p>  |
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


# Matrix Game 
## Name:  ***Reverse It*** 
### Description: 
**Reverse It** is an *interactive* single player game that is challenging players *reaction time*. It is a simple but quite hard game to win. It has a total of 10 levels, each level having it's own time pressure. The player has 3 lives during the entire gameplay, in order to win the game. The *logic* of the game is inspired by the fact that brain tends to *reproduce* the movements it sees. So, a ,,good move" that brings you score in this game is to actually reverse the "instruction" displayed by the led matrix. How this game is actually played I will explain in the following.
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
| Speakers |<img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/speakersImage.jpg" width="70%" height="70%">  |
| DFPlayer mini |  <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/dfPlayer.jpg" width="70%" height="70%">|
| MAX7219 driver |  <img src="https://github.com/rares-munteanu/IntroductionToRobotics/blob/master/Matrix%20Game/Images/matrixDriver.jpg" width="70%" height="70%">|









#

### How to play: 

You have a joystick and 2 buttons below the led matrix. Random arrows pointing in 6 different positions will appear on screen. You have to do the reversed action of what arrow is telling you. For example if arrow is pointing down-left you have to press the right  button below the matrix, and so on.


### How the Game meets the requirements:
#### Hardware: 
I have all the compulsory hardware requirements and some speakers with background music.
#### Game Specifications: 
Score will be updated with every player move, and it will not be equal to level. Level will increase
after a certain number of correctly completed moves (10). The complexity (player move time) of the game increases with every level.
The player(s) will have 3 lives for each game played and every wrong move will decrease one life. There will be bonuses, if
the player completed the move in a certatin amount of time(very fast) will get back one life. Last 3 highscores will be saved
to eeprom with player names. I also have animations before starting the game.

#### LCD Display: 
LCD Display also have all the compulsory menus like play game, highscore(saved in eeprom), settings, 
where players can change their names; You can change the starting level and so on. There will be
also an info menu with all the informations about the game. After the game is finished a congratulate menu will appear and pressing the joystick button will get the player back to main menu.

### [Demo Video Link](https://www.youtube.com/watch?v=ipwmN_Qqrns&feature=youtu.be)

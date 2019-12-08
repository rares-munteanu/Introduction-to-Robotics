# Matrix Game  
### Name: Reverse It  
### Description:
**Reverse It** is an interactive single and multiplayer game where "instructions" are spawned on the screen and the player shall
have to reverse them shortly after they have appeared using a joystick in order to increase the score. For the beginning the game "instructions"
will be just random directed arrows (up,left,right,down) displayed on the led matrix. Every level will contain certain number
of arrows displayed (one after another). Reversing them corectly will increase score and after the player finishes the level 
the interval in which he has to execute the reverse move of pointing arrow will decrease.

### How the Game meets the requirements:
#### Hardware: 
I will have all the compulsory hardware requirements and I will add some buzzers to let the player(s) know
if they did the correct or wrong move, and a switch for power on and off.
#### Game Specifications: 
Score will be updated with every player move, and it will not be equal to level. Level will increase
after a certain number of correctly completed moves. The complexity (player move time) of the game increases with every level.
The player(s) will have 3 lives for each game played and every wrong move will decrease one life. There will be bonuses, if
the player completed the move in a certatin amount of time(very fast) will get back one life. Last 3 highscores will be saved
to eeprom with player names. I will add some animations when player manage to win the level. 
#### LCD Display: 
LCD Display will also have all the compulsory menus like play game, highscore(saved in eeprom), settings, 
where players can change their names; on single-player mode you can change the starting level and so on. There will be
also an info menu with all the informations about the game. During the gameplay, on the lcd display there will be informations
about the player(s) like level, lives, score and so on. After every level some informations about each player gameplay will
appear on the lcd display (reaction time, remaining lives, difference of scores etc.). After the game is finished another
menu will appear on the screen with relevant informations about the whole gameplay.



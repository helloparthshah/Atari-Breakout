# Attari-Breakout

### About the game:
This is a classical attari breakout game made entirely in c++. The game uses graphics library of c++ for graphical interfae and animation purposes. 
The game is simple, the player has to bounce the ball on the pad and hit the bricks in of the level. If the player is unable to bounce the ball and the ball reaches the bottom end of the screen, the game is over. The player can record his score and later check in the "Hall of fame" section of the game. 
There are a total of 4 types of bricks in the game.
Firstly, White brick. This is the easy brick which on hitting will directly collapse.
Second, Blue bricks. These are level 2 bricks with medium strength. Hitting these bricks would change them to White bricks and then again hitting them will result in full breakdown of the brick.
Thrid, Red bricks. These are level 3 bricks with high strength. Hitting these bricks would change them to Blue bricks and player has to hit them 2 more times to fully break them.
Lastly, Pink bricks. These are the powerup bricks which provide the player with longer bounce pad for a total of 15 seconds. 
To complete a level player has to breakdown all the bricks of the level. With increasing level, the amount of second and third bricks will change and the speed of the ball will also increase in order to make the game harder.
The scores saved by the players are saved in a separate file "SCORE.txt", and the scores of the top 10 players of all time are shown in the Hall of fame section of the game.

### Libraries used :

+ graphics.h
+ iostream.h
+ conio.h
+ process.h 
+ time.h
+ stdlib.h
+ dos.h
+ stdio.h
+ bios.h
+ fstream.h
+ string.h


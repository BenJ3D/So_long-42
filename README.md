# so_long | bducrocq

So_long is a graphic project using the minilibX provided by the 42 school.

The objective of the game is to collect all the collectible objects to be able to leave the game by a door.

![solong.png](https://lh3.googleusercontent.com/ru-gx2PnyvhT6nUcIG6liUo2oI0QIzx2todNv8XvPdQ3_sPBxaevgtm0W6IQXtNKup84aPJ6U88q0nVGPbGx=w2480-h2176-rw)

### How to play
---
###### Maps
The game is able to play any map you want as long as it follow some specific rules:
* The map has to be a ``.ber`` file.
* It can only contain some of the following characters:

| Character | Object |
| - | - |
| 1 | Wall. |
| 0 | Ground. |
| C | Collectable. |
| E | Exit. |
| P | Player starting position. |
| K | Enemy. (only with so_long_bonus)| 

* The map must be a rectangle surrounded by walls ‘1’.
* It must have at least one exit ‘E’ and one collectable ‘C’. Multi player ‘P’ .

See some examples in the ``maps`` folder of this project.

###### Controls
Use ``WASD`` to move. You move one tile at a time. Enemies move after you do, also one tile at a time, and will kill you when you move into their tile or they move into yours. After picking up all weeds, the exits open and you may leave to see how many moves you’ve used to solve the map.

Close the game with ``esc``.

###### Execute the game
To play you must first generate the game with Makefile:

| Rule | Function |
| - | - |
| ``make`` | Generates so_long and an object file for each .c. |
| ``make clean`` | Deletes all object files. |
| ``make fclean`` | Deletes the object files and the so_long. |
| ``make re`` | makes ``fclean`` and ``make`` again. |

Now launch the game with command : ``./so_long maps/01.ber`` (change the path for other map)

###### Execute the bonus game

| Rule | Function |
| - | - |
| ``make bonus`` | Generates so_long_bonus and an object file for each .c in bonus folder. |``./so_long_bonus maps/01.ber``

Place yourself in the bonus directory and start the game with 

### Contact
---

* 42 Login:	*bducrocq*
* Email:		*benjamin@ben3d.fr*


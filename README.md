# so_long | bducrocq

So_long is a graphic project using the minilibX provided by the 42 school.

The objective of the game is to collect all the collectible objects to be able to leave the game by a door.

![solong.png](https://lh3.googleusercontent.com/fife/AAWUweVnjFn9pwN69yiFJX-9BipOwu-uip-wydZF9Y26uX28Eh7LfhcNsszCepDeh7xbrRg2UK2j6e-iInZUcdIvP2iSdi70W6elHGpHhB7OXKHBJl63yZIOXuaE9ZfNfFohBZlxENg5NfIu2htWefGBD6ygGnzuaohu7Is69tlUWk6EdEdo5czRGvTcS_3OjAFfbSsPA8miYRBCPyATDi_hawoIxLq-jzyXGiGuL0lOYx5q0SXSj_3a2yGrwgeTFrF4TptQCoPMwC0XRy_L1zHsntXSISIIzZg7Y5MrSGT4gDdMuAXzOwGMzjc0cxUtJ1w3q1sO4eha4zUxvCmv1YkzcAqzBo4uWNmzl04VwM7M6hP09xszLF8r5dqEPpaSMqT84dN1PnVPycYyM0ozlbf1hGkXaHr9QPKduKsQAyTA44MK5KOl0mTyVJ0LXrFbH2P4puOxBiuQn9ZJi9ScIeP0Zk5nqk-H7Ycen7suEKq-GIgC31kEtEW9C-LKZnq7TJ5lFmI7GR64bSBPk91I56CZFCKTWu7jYjKzU3A4Y9eHjOBZP2RLb_9YG25EWgwZnyn223iFU7Jh5NzhRDl-ET2n1MzJoKUN56YbKRnL7eWPSP9PEzfEQ-TnQtQqp64QSYKrjzUYv4biRNWrytBxv4cXMm35T3dAYXlz3mGu6Cy4TuDEa2g1q2nPs-QVrKJBphXmqSgbKWEF33uee3hnb695JPT7Jsk2R3MpBTzTix5nblVja1_38AkFdNr8W9cc9Ov5Lcve3e1fWJskHA6euXc=w3590-h2176)

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

![solong01.png](https://lh5.googleusercontent.com/vai01s9SwcDe29DmBb1Tyqm7QE1VIAqF_3D38QYaNvwGWFm0NZawRmPaiFB-ZVnU7gmrawnGxug8rz6IsTpD=w3742-h2176-rw)

### Contact
---

* 42 Login:	*bducrocq*
* Email:		*benjamin@ben3d.fr*

Good luck with your projects!

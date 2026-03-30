*This project has been created as part of the 42 curriculum by ckhondji*

# Description
So_long is a project wich focuses on graphics using minilibx, 42's graphic library, to make a small 2D game. Its main goal is to learn how to use textures, sprites, parsing and event hooks.
The game goal is to collect every collectible and leaving through the door in the least steps possible. Although mine is in a wizard theme, its easily changeable via the "img" folder.


# Instructions

First, use the makefile for compilation. It won't work if you simply compile.
The compilation may give a warning due to an error in the minilibx library (nothing i can do unfortunatly) but it won't affect the program.

You must then launch the "so_long" executable with a map path. It will then open a window with the game. The terminal will be used to show how many times a player moved.

Example: 

    ./so_long maps/map1.ber

You can then move using WASD.
Pressing ESC should quit the program proprely.

The game won't launch if the map is invalid (more in the "Map Instructions" section), if a texture is missing or if it doesn't find the map you indicated.
Client will write "Bravo !" if the game ended.

# Resources

Links: https://harm-smits.github.io/42docs/

AI was used to explain how the X11 events works.
It was NOT used to give full fletched answers or to generate code.

# Map Instructions

The map file is composed of 5 characters:
- 0 for an empty space,
- 1 for a wall,
- C for a collectible,
- E for a map exit,
- P for the player's starting position.

It should only contain 1 exit, 1 starting poisition and at least 1 collectible.

The map should be rectangular and surrounded by walls.
It should contain a valid path from the player's starting position to the exit.

If any of those requirements is not met, the game will not launch.

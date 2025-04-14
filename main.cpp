#include "Game.h"


int main()
{
    Game game;
    game.run();
    return 0;
}

/*
done:
    - basic catcher setup
    - basic note setup
todo:
	- rotation speed
    - stop drawing notes behind circ radius if caught
		 - if not caught, draw notes until the inside radius of the catcher
			- inside edge needs to be in globals
    - note hit detection
	- load song, bpm, song notes, and other data from file/folder
	- add joystick support (once bought)
    - make user adjustable variables
		- resolution
        - refresh rate
        - vsync
        - scroll speed
        - catcher width
    - add ui

 */
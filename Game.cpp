#include "Game.h"


Game::Game()
{
	//Create the window
	window.create(sf::VideoMode(WINDOW_SIZE.x * WINDOW_SCALE, WINDOW_SIZE.y * WINDOW_SCALE), "JOYSTICKY");
	window.setFramerateLimit(FPS);
	window.setVerticalSyncEnabled(true);

	//Load the level
	level.load();
}


void Game::run()
{
	//Game loop
	while (window.isOpen())
	{
		//Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Update the game state
		level.update(window);

		//Render the game
		window.clear();
		level.drawTo(window);
		window.display();
	}
}

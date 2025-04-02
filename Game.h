#pragma once
#include "Level.h"

class Game
{
public:
	Game();
	~Game() = default;
	void run();
private:
	sf::RenderWindow window;
	Level level;
};


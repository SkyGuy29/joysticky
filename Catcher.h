#pragma once
#include "globals.hpp"


class Catcher
{
public:
	Catcher();
	~Catcher() = default;
	void update();
	void drawTo(sf::RenderWindow&);
private:
	sf::CircleShape middle, outline;
	sf::ConvexShape catcher;
};

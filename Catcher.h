#pragma once
#include "globals.hpp"


class Catcher
{
public:
	Catcher();
	~Catcher() = default;
	void update(const sf::RenderWindow&);
	void drawTo(sf::RenderWindow&);
private:
	sf::CircleShape middle, outline;
	sf::ConvexShape catcher;
	sf::Vector2f prevMousePos;
};

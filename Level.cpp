#include "Level.h"


void Level::load()
{
	
}


void Level::update(sf::RenderWindow& window)
{
	catcher.update(window);
}


void Level::drawTo(sf::RenderWindow& window)
{
	catcher.drawTo(window);
}

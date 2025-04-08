#include "Level.h"


Level::Level()
{
	note.setNote(4, PI / 2, 1, 0, false);
}


void Level::load()
{
	
}


void Level::update(sf::RenderWindow& window)
{
	catcher.update(window);
	note.update();
}


void Level::drawTo(sf::RenderWindow& window)
{
	catcher.drawTo(window);
	note.drawTo(window);
}

#include "Level.h"


Level::Level()
{
	for (int i = 0; i < 5; i++)
	{
		notes.emplace_back(4 + i, i * PI / 4, 4, 0, false);
	}
}


void Level::load()
{
	
}


void Level::update(sf::RenderWindow& window)
{
	catcher.update(window);
	for (auto& note : notes)
		note.update();
}


void Level::drawTo(sf::RenderWindow& window)
{
	catcher.drawTo(window);
	for(auto& note : notes)
		note.drawTo(window);
}

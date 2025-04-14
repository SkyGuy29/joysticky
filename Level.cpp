#include "Level.h"


Level::Level()
{
	for (int i = 0; i < 5; i++)
	{
		notes.emplace_back(4 + i, i * 45, 1, 0, false);
	}
	notes.emplace_back(10, 0, 2, 45 / 2.f, false);
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


bool Level::catchCheck()
{
	//return abs(note.getRotation() - catcher.getRotation()) <= catcher.getWidth())
}


void Level::drawTo(sf::RenderWindow& window)
{
	for(auto& note : notes)
		note.drawTo(window);
	catcher.drawTo(window);
}

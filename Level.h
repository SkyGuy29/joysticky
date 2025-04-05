#pragma once
#include "Catcher.h"

class Level
{
public:
	Level() = default;
	~Level() = default;
	void load();
	void update(sf::RenderWindow&);
	void drawTo(sf::RenderWindow&);
private:
	Catcher catcher;
};


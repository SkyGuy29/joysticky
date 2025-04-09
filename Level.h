#pragma once
#include "Catcher.h"
#include "Note.h"

class Level
{
public:
	Level();
	~Level() = default;
	void load();
	void update(sf::RenderWindow&);
	void drawTo(sf::RenderWindow&);
private:
	Catcher catcher;
	bool paused = false; //pausing invalidates the run
	std::vector<Note> notes;
};


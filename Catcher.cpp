#include "Catcher.h"


Catcher::Catcher()
{
	outline.setOrigin(0, 0);
	outline.setPosition(sf::Vector2f(WINDOW_SIZE.x * WINDOW_SCALE / 2, WINDOW_SIZE.y * WINDOW_SCALE / 2));
	outline.setRadius(50 * WINDOW_SCALE);
	outline.setFillColor(sf::Color::Transparent);
	outline.setOutlineColor(sf::Color::White);
	outline.setOutlineThickness(5);

	middle.setOrigin(0, 0);
	middle.setPosition(sf::Vector2f(WINDOW_SIZE.x * WINDOW_SCALE / 2, WINDOW_SIZE.y * WINDOW_SCALE / 2));
	middle.setRadius(25 * WINDOW_SCALE);
	middle.setFillColor(sf::Color::White);
	middle.setOutlineThickness(5);

	catcher.setOrigin(0, 0);
	catcher.setPosition(sf::Vector2f(WINDOW_SIZE.x * WINDOW_SCALE / 2, WINDOW_SIZE.y * WINDOW_SCALE / 2));
	catcher.setPointCount(30);
	for (int i = 0; i < 15; i++)
	{
		catcher.setPoint(i, sf::Vector2f((middle.getRadius() + 5 * WINDOW_SCALE) //radius
			* cos(i * PI / 90), //sin and cos for equidistant points
			(middle.getRadius() + 5 * WINDOW_SCALE)
				* sin(i * PI / 90))); 
	}

	for (int i = 15; i < 30; i++)
	{
		catcher.setPoint(i, sf::Vector2f((middle.getRadius() + 5 * WINDOW_SCALE)  //radius
			* cos(PI / 6 * (i - 1 / 15)), //sin and cos for equidistant points
			(middle.getRadius() + 5 * WINDOW_SCALE)
			* sin(PI / 6 * (i - 1 / 15)))); 
	}
	catcher.setFillColor(sf::Color::Cyan);
}


void Catcher::update()
{
	
}


void Catcher::drawTo(sf::RenderWindow& window)
{
	window.draw(outline);
	window.draw(middle);
	window.draw(catcher);	
}
